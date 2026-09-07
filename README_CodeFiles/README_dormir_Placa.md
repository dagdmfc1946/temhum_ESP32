# `dormir_Placa.h`

## Propósito

Define `sleep()`, la rutina que prepara la Heltec WiFi LoRa 32 V3 para entrar en Deep Sleep y despertar mediante un temporizador. El objetivo es reducir el consumo entre mediciones periódicas.

## Dependencias

- `esp_bt.h` para detener Bluetooth.
- `esp_sleep.h` para configurar y activar Deep Sleep.
- `SPI.h` y los objetos `WiFi` y `Wire` disponibles desde las inclusiones globales.
- `TIME_TO_SLEEP` y `uS_TO_S_FACTOR` de `parameters.h`.

## Funcionamiento

`sleep()` apaga Wi-Fi, detiene Bluetooth, finaliza SPI e I2C, configura el despertador con `TIME_TO_SLEEP * uS_TO_S_FACTOR`, vacía el puerto serie y llama a `esp_deep_sleep_start()`.

El ESP32-S3 pierde el estado normal de RAM durante Deep Sleep. Por eso, al despertar vuelve a iniciar el programa desde `setup()` y repite el ciclo completo. La sección posterior a `esp_deep_sleep_start()` solo actúa como respaldo: si la llamada fallara, espera cinco segundos y reinicia mediante `ESP.restart()`.

## Interacción

El archivo principal llama a `sleep()` después de apagar la OLED. `parameters.h` determina la duración del sueño, mientras que `wifi_ON.h`, `SPI` y la pantalla ya han usado los periféricos que esta rutina desconecta.

## Consideraciones

El mensaje serie posterior a la configuración del temporizador dice que se está conectando a Wi-Fi, aunque el dispositivo está entrando en sueño; es un texto heredado que puede corregirse sin cambiar la lógica.