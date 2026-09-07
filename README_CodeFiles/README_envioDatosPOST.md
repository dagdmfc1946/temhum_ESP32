# `envioDatosPOST.h`

## Propósito

Envía al servidor los datos medidos mediante una solicitud HTTP POST con cuerpo JSON.

## API

`enviarDatosPorPOST(float temp, float hum, int v_batt)` recibe temperatura en grados Celsius, humedad relativa en porcentaje y tensión de batería en milivoltios.

## Funcionamiento

1. Comprueba el estado de Wi-Fi y llama a `connectWiFi()` si no hay conexión.
2. Obtiene la MAC con `WiFi.macAddress()`.
3. Convierte la temperatura a entero multiplicándola por diez y trunca la humedad a entero.
4. Construye un JSON con `mac`, `values.temperature`, `values.humidity`, `battery.voltage` y `battery.level`.
5. Envía el JSON a `serverURL` con `Content-Type: application/json`.
6. Muestra el resultado por serie y utiliza la OLED para indicar éxito o error.
7. Libera el cliente HTTP con `http.end()`.

## Interacción

El `.ino` le entrega los valores producidos por `lectura_DHT.h` y `lectura_Vbatt.h`. Depende de `wifi_ON.h` para reconectar y de `oled_ON.cpp` para `mostrarSendDataOLED()` y `mostrarErrorPostOLED()`.

## Limitaciones y configuración

Un código HTTP positivo se considera éxito; los códigos `4xx` y `5xx` no se distinguen como errores de aplicación. `battery.level` permanece siempre en `0`, porque no existe cálculo de porcentaje. La URL usa HTTP y está escrita en el fuente; conviene parametrizarla y usar HTTPS/autenticación en producción.