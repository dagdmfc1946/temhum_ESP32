# `uso_LED.h`

## Propósito

Inicializa el LED interno como salida y establece su estado inicial apagado.

## API

`initLED()` ejecuta `pinMode(LED, OUTPUT)` y `digitalWrite(LED, LOW)`.

## Interacción

El archivo principal llama a `initLED()` al comienzo de cada ciclo. Después, `wifi_ON.h`, `oled_ON.cpp` y las rutinas de estado escriben directamente sobre `LED` para indicar conexión, errores, batería baja y POST correcto.

## Código desactivado

El archivo conserva funciones de parpadeo comentadas para distintos estados. No forman parte del firmware compilado; actualmente los patrones están implementados dentro de las funciones de OLED y Wi-Fi.

## Hardware

La macro `LED` debe estar definida por el soporte de la placa. Su nivel activo y GPIO pueden variar en otras ESP32, por lo que deben verificarse antes de reutilizar este módulo.