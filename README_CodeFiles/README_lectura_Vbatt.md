# `lectura_Vbatt.h`

## Propósito

Obtiene la tensión de la batería usando el ADC del ESP32 y devuelve el resultado en milivoltios.

## API

`read_VBatt()` no recibe parámetros y retorna un `int` con la tensión corregida.

## Funcionamiento

Configura el ADC a 12 bits, activa `PIN_VBAT_CTRL` para alimentar el divisor resistivo, espera 10 ms y lee `PIN_VBAT_ADC` mediante `analogReadMilliVolts()`. Multiplica la lectura por `4.9` para compensar el divisor de la placa.

## Interacción

`finalCode_AllCommented_OK.ino` guarda el retorno en `V_batt`. Si es menor de 3300 mV, solicita `mostrarAdvertenciaBateria()`; posteriormente el mismo valor se incluye en el JSON de `envioDatosPOST.h`.

## Calibración y hardware

El factor `4.9` depende del divisor resistivo y de la placa. Al cambiar hardware deben verificarse `PIN_VBAT_CTRL`, `PIN_VBAT_ADC`, límites del ADC y la calibración. La función activa el divisor, pero no lo desactiva explícitamente después de medir, por lo que el apagado final queda a cargo del ciclo de Deep Sleep.