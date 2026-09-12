# ESP32 de 30 pines: sensor de temperatura y humedad

## Descripcion

Este directorio contiene una nueva version modular del proyecto para una placa ESP32 de 30 pines. El programa realiza un ciclo completo al arrancar:

1. Inicializa el LED integrado.
2. Lee temperatura y humedad mediante un DHT11.
3. Muestra las lecturas en una pantalla OLED SSD1306 de 0.96 pulgadas y 128x64 pixeles.
4. Lee la tension de bateria mediante el ADC del GPIO34.
5. Muestra el estado de la bateria cuando la tension medida es igual o superior a 3300 mV.
6. Se conecta a una red Wi-Fi.
7. Envia las lecturas al servidor mediante HTTP POST en formato JSON.
8. Apaga los perifericos y entra en Deep Sleep durante el tiempo configurado.

El archivo `loop()` permanece vacio porque el dispositivo se reinicia desde `setup()` despues de cada despertar.

## Archivos

- `newCode_ESP32_30P.ino`: flujo principal del ciclo de lectura, envio y sueño.
- `parameters.h`: pines, direccion I2C, resolucion OLED, divisor de bateria y tiempo de sueño.
- `includess.h`: incluye las cabeceras del proyecto.
- `lectura_DHT.h`: inicializacion y lectura del DHT11.
- `lectura_Vbatt.h`: lectura del ADC y conversion a milivoltios.
- `oled_ON.h` y `oled_ON.cpp`: funciones de la pantalla OLED con Adafruit GFX y Adafruit SSD1306, incluida `mostrarEstadoBateria(int voltage)`.
- `wifi_ON.h`: conexion Wi-Fi y gestion del indicador LED/OLED.
- `envioDatosPOST.h`: construccion y envio del JSON por HTTP POST.
- `dormir_Placa.h`: apagado de perifericos y Deep Sleep.
- `uso_LED.h`: inicializacion del LED integrado.

## Conexion de hardware

| Elemento | GPIO | Observaciones |
| --- | ---: | --- |
| DHT11 | 4 | Pin de datos; usar resistencia pull-up segun el montaje |
| OLED SDA | 21 | Bus I2C |
| OLED SCL | 22 | Bus I2C |
| OLED VCC | 3V3 | Alimentacion de la pantalla |
| OLED GND | GND | Tierra comun |
| Bateria ADC | 34 | Entrada ADC; usar divisor resistivo y no superar el rango permitido |
| LED integrado | 2 | Indicador visual de estado |

El GPIO34 es solo de entrada, por lo que esta version no usa un pin de control para activar el divisor de bateria. El factor de correccion se configura con `VBAT_DIVIDER_FACTOR`.

## Estado de bateria

La funcion `mostrarEstadoBateria(int voltage)` se ejecuta cuando la lectura es de al menos 3300 mV. Muestra en la OLED el texto `BATTERY STATUS` y el valor medido en milivoltios durante dos segundos. Si la lectura es inferior a 3300 mV, se ejecuta `mostrarAdvertenciaBateria()` en su lugar.

## Librerias necesarias

Instalar desde el gestor de librerias del Arduino IDE:

- `DHT sensor library` de Adafruit.
- `Adafruit GFX Library`.
- `Adafruit SSD1306`.

Tambien se requieren las librerias incluidas con el core de Arduino para ESP32: `WiFi`, `HTTPClient`, `Wire`, `SPI`, `esp_sleep` y Bluetooth.

## Configuracion antes de cargar

1. En `wifi_ON.h`, reemplazar `NOMBRE_DE_LA_RED` y `CONTRASENA_DE_LA_RED`.
2. En `envioDatosPOST.h`, reemplazar `DIRECCION_DEL_SERVIDOR` y ajustar el puerto o la ruta si es necesario.
3. En `parameters.h`, verificar `VBAT_DIVIDER_FACTOR` segun los valores reales del divisor resistivo.
4. Ajustar `TIME_TO_SLEEP` si se necesita otro intervalo entre lecturas.
5. Seleccionar en Arduino IDE la placa ESP32 de 30 pines correspondiente al hardware utilizado.

## Formato enviado

El cuerpo JSON conserva la estructura del proyecto original:

```json
{
  "mac": "AA:BB:CC:DD:EE:FF",
  "values": {
    "temperature": 253,
    "humidity": 62
  },
  "battery": {
    "voltage": 4100,
    "level": 0
  }
}
```

La temperatura se envia multiplicada por 10 para conservar un decimal; la humedad y la tension se envian como enteros. El campo `battery.level` permanece en `0` porque el porcentaje de bateria aun no esta implementado.

## Notas de seguridad y medicion

- No conecte una bateria directamente al GPIO34: utilice un divisor resistivo adecuado.
- El valor de `VBAT_DIVIDER_FACTOR` debe calibrarse comparando la lectura con un multimetro.
- La direccion `0x3C` es la habitual para estas pantallas; si no hay imagen, compruebe la direccion I2C y el cableado.
- El DHT11 necesita tiempos de lectura mayores que otros sensores; la libreria gestiona el protocolo y los tiempos basicos.
