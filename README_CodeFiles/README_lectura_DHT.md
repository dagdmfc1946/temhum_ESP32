# `lectura_DHT.h`

## Propósito

Inicializa el sensor DHT22 y obtiene temperatura y humedad relativa.

## API

`dataRead_DHT(float* temp, float* hum)` recibe punteros a las variables de salida. En una lectura válida escribe temperatura en Celsius y humedad en porcentaje. Si la librería devuelve `NaN`, escribe `0` en ambas variables.

## Funcionamiento

El objeto global `dht` se construye con `DHTPIN` y `DHTTYPE` de `parameters.h`. Cada llamada ejecuta `dht.begin()`, lee ambos valores y valida el resultado con `isnan()`.

## Interacción

El `.ino` pasa las variables `TEM` y `HUM`. En caso de error, se llama a `mostrarErrorSensorOLED()` de `oled_ON.cpp`; después el flujo principal continúa y puede enviar los ceros resultantes al servidor.

## Consideraciones

El DHT22 es lento y la librería controla sus tiempos internos. El pin, el tipo de sensor y el cableado deben coincidir con `parameters.h`. La función no calcula promedios ni reintenta una lectura fallida.