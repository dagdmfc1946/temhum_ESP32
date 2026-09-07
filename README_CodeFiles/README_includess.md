# `includess.h`

## Propósito

Actúa como cabecera agregadora del proyecto. El archivo principal solo necesita incluir este módulo para disponer de la configuración y de las funciones del firmware.

## Módulos incluidos

- `parameters.h`: pines y constantes.
- `uso_LED.h`: inicialización del LED.
- `lectura_DHT.h`: lectura del DHT22.
- `lectura_Vbatt.h`: lectura del ADC de batería.
- `wifi_ON.h`: conexión Wi-Fi.
- `envioDatosPOST.h`: creación y envío del JSON.
- `oled_ON.h`: declaraciones de la interfaz OLED.
- `dormir_Placa.h`: Deep Sleep.

## Interacción

La inclusión se resuelve antes de compilar, por lo que las funciones quedan disponibles para `finalCode_AllCommented_OK.ino`. También hace que algunos módulos vean símbolos definidos en otros módulos. Al añadir nuevos archivos, deben incorporarse aquí solo si forman parte del flujo principal.

## Consideraciones

Es una cabecera de inclusiones directas y no contiene funciones propias. Para evitar definiciones duplicadas al crecer el proyecto, sería recomendable añadir guardas de inclusión o `#pragma once` y separar declaraciones de implementaciones.