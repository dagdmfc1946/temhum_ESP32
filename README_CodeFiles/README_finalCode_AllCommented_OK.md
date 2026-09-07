# `finalCode_AllCommented_OK.ino`

## Propósito

Es el punto de entrada del firmware. Ejecuta una medición, presenta sus resultados, intenta publicarlos y pone el ESP32 en Deep Sleep para repetir el proceso tras el despertar.

## Flujo de `setup()`

1. Inicia el puerto serie a 115200 baudios y prepara el LED.
2. Lee temperatura y humedad con `dataRead_DHT()`.
3. Muestra esas lecturas durante dos segundos en la OLED.
4. Lee la batería con `read_VBatt()` y muestra una alerta si es menor de 3300 mV.
5. Establece la conexión Wi-Fi con `connectWiFi()`.
6. Envía temperatura, humedad y batería con `enviarDatosPorPOST()`.
7. Muestra el aviso de Deep Sleep, apaga la OLED y llama a `sleep()`.

`loop()` queda vacío intencionadamente: el ciclo se ejecuta una vez por arranque y el temporizador de Deep Sleep provoca el siguiente arranque.

## Interacción

`includess.h` incorpora todos los módulos. Las variables `TEM`, `HUM` y `V_batt` conectan la adquisición con la pantalla y el envío. Las funciones de OLED y LED solo informan del estado; no deciden si se continúa. Incluso con una lectura inválida o batería baja, el programa continúa hacia Wi-Fi y POST.

## Ciclo temporal

`TIME_TO_SLEEP` define 300 segundos de sueño en `parameters.h`. El intervalo real entre lecturas también incluye los retardos del sensor, OLED, Wi-Fi, HTTP y mensajes de estado.