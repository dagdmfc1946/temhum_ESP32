# `parameters.h`

## Propósito

Centraliza las constantes de hardware y temporización utilizadas por los demás módulos.

## Parámetros actuales

| Macro | Valor | Uso |
|---|---:|---|
| `DHTPIN` | `3` | GPIO de datos del DHT22 |
| `DHTTYPE` | `DHT22` | Tipo de sensor |
| `PIN_VBAT_CTRL` | `37` | Control del divisor de batería |
| `PIN_VBAT_ADC` | `1` | Entrada ADC de batería |
| `uS_TO_S_FACTOR` | `1000000ULL` | Conversión de segundos a microsegundos |
| `TIME_TO_SLEEP` | `300` | Duración del Deep Sleep |

Los pines de OLED y LED aparecen comentados porque la definición de la placa Heltec V3 los proporciona desde el entorno de placa.

## Interacción

`lectura_DHT.h` usa `DHTPIN` y `DHTTYPE`; `lectura_Vbatt.h` usa los pines del ADC; `oled_ON.cpp` usa los identificadores de OLED; y `dormir_Placa.h` usa los factores temporales. `uso_LED.h` y las funciones OLED dependen de `LED`.

## Migración

Al cambiar de placa o cableado hay que revisar todos los GPIO, la lógica de `Vext`, la existencia del LED y la calibración del divisor. Un GPIO incorrecto puede impedir la lectura o causar una conexión eléctrica insegura.