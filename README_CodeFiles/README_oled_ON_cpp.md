# `oled_ON.cpp`

## Propósito

Implementa la gestión de la OLED SSD1306 integrada, incluyendo alimentación, mensajes de estado y señales complementarias mediante el LED.

## Configuración

Crea un objeto privado `SSD1306Wire` con dirección `0x3C`, frecuencia I2C de 500 kHz, geometría `128x64` y los pines definidos por la placa. `VextON()` activa la alimentación con nivel bajo y `VextOFF()` la corta con nivel alto.

## Mensajes

Muestra lecturas del DHT22, errores del sensor, batería baja, conexión Wi-Fi, errores Wi-Fi, resultado del POST y entrada en Deep Sleep. Las funciones inicializan la pantalla, limpian el búfer, dibujan el texto, actualizan el display y esperan el tiempo necesario para que el usuario lo vea.

## Interacción

`oled_ON.h` expone los prototipos. `lectura_DHT.h`, `wifi_ON.h`, `envioDatosPOST.h` y el `.ino` llaman a estas funciones para comunicar estados del ciclo. El LED se utiliza en paralelo para señalar errores o éxitos.

## Consideraciones

Cada mensaje vuelve a encender e inicializar la pantalla, por lo que el flujo es simple pero consume tiempo y energía. La OLED no decide el flujo de negocio. Las esperas de hasta varios segundos forman parte del tiempo activo del ciclo.