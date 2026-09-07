# `oled_ON.h`

## Propósito

Declara la interfaz pública de la pantalla OLED y sus funciones de alimentación, visualización y apagado.

## Funciones declaradas

- `VextON()` y `VextOFF()`: controlan la alimentación de la pantalla.
- `initOLED()` y `apagarOLED()`: inicializan y apagan el display.
- `mostrarDatosOLED()`: presenta temperatura y humedad.
- `mostrarErrorSensorOLED()` y `mostrarAdvertenciaBateria()`: muestran alertas de adquisición.
- `mostrarConexionWiFiOLED()` y `mostrarConectadoWiFi()`: informan del estado Wi-Fi.
- `mostrarErrorWiFiOLED()`: informa de una conexión fallida.
- `mostrarErrorPostOLED()` y `mostrarSendDataOLED()`: informan del resultado HTTP.
- `mostrarDeepSleepOLED()`: anuncia la entrada en sueño.

## Interacción

Las implementaciones están en `oled_ON.cpp`. Este archivo incluye `parameters.h`, `Wire.h` y `HT_SSD1306Wire.h`, por lo que los módulos DHT, Wi-Fi, HTTP y el programa principal pueden llamar a la misma interfaz sin conocer los detalles I2C.

## Hardware

La dirección I2C, geometría y pines reales se configuran en la instancia privada de `oled_ON.cpp`. `Vext` usa lógica activa en nivel bajo para encender la alimentación de la OLED.