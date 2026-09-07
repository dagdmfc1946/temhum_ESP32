# `wifi_ON.h`

## Propósito

Configura el ESP32 como estación Wi-Fi, intenta conectarlo a la red y comunica visualmente el resultado.

## API

`connectWiFi()` inicia la conexión usando `ssid` y `password`, espera como máximo diez segundos y configura ahorro de energía `WIFI_PS_MIN_MODEM`.

## Funcionamiento

La función selecciona `WIFI_STA`, llama a `WiFi.begin()`, muestra el estado en OLED y alterna el LED mientras espera. Si conecta, imprime la MAC y muestra confirmación; si vence el límite, muestra el error y deja que el programa continúe.

## Interacción

El `.ino` llama a esta función antes del POST. `envioDatosPOST.h` también la llama como reintento si la conexión se perdió. `oled_ON.cpp` presenta los mensajes y `dormir_Placa.h` apaga Wi-Fi al final del ciclo.

## Seguridad y comportamiento

Las credenciales están escritas directamente en el archivo y deben sustituirse por una configuración segura antes de distribuir el firmware o publicar el repositorio. La conexión no se reintenta indefinidamente: tras diez segundos el flujo continúa hacia el módulo HTTP, que puede intentar una reconexión adicional.