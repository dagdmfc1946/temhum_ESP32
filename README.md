# TemHum_IA

## 🌡️ Sistema IoT de Medición de Temperatura y Humedad

### Descripción general

**TemHum_IA** es un prototipo de sistema IoT orientado a la medición de temperatura y humedad relativa en ambientes interiores. Utiliza el sensor **DHT22** y la placa **Heltec WiFi LoRa 32 (V3)**, que integra un microcontrolador **ESP32-S3**, conectividad Wi-Fi y pantalla OLED.

El sistema captura lecturas ambientales, las visualiza en pantalla OLED y las transmite mediante **HTTP POST (JSON)** a un servidor remoto. Además, implementa ciclos de **Deep Sleep (modo de sueño profundo)** para extender la autonomía de la batería recargable que lo alimenta.

---

## ⚙️ Funcionalidades principales

- Lectura de temperatura y humedad con sensor **DHT22**.
- Visualización de datos en pantalla OLED integrada.
- Medición del voltaje de batería.
- Transmisión de datos vía **Wi-Fi** mediante **HTTP POST**.
- Alertas visuales mediante **pantalla OLED** y **LED interno**.
- Gestión energética con **Deep Sleep** cada 300 segundos **(5 minutos)**.

---

## 📂 Estructura del proyecto

Este repositorio contiene tanto el **código fuente** como la **documentación técnica** del sistema TemHum_IA.

---

### 🔧 Código fuente

El código está organizado en módulos para facilitar su mantenimiento y escalabilidad. Se puede compilar usando **Arduino IDE** o **PlatformIO**.

#### Archivos principales
- `final_Code.ino`: flujo principal del programa
- `parameters.h`: definición de pines, tiempos y constantes
- `lectura_DHT.h`, `lectura_Vbatt.h`: adquisición de datos
- `wifi_ON.h`, `envioDatosPOST.h`: conectividad y transmisión
- `oled_ON.cpp/.h`, `uso_LED.h`: visualización en OLED y LED interno
- `dormir_Placa.h`: control del modo Deep Sleep

---

## 📦 Librerías necesarias

Para compilar correctamente el proyecto, asegurarse de instalar las siguientes librerías en el Arduino IDE:

### 📚 Sensor DHT22
- **DHT sensor library**  
  https://github.com/adafruit/DHT-sensor-library
- **Adafruit Unified Sensor**  
  https://github.com/adafruit/Adafruit_Sensor

### 📚 Pantalla OLED (I2C)
- **HT_SSD1306Wire** *(o equivalente compatible con OLED 0.96” de Heltec)*  
  Incluida generalmente con el framework de Heltec

### 📚 Conectividad Wi-Fi y HTTP
- **WiFi**
- **HTTPClient**
- **esp_wifi**
- **esp_sleep**

---

> ⚠️ Asegurarse de tener instalado el **ESP32 Board Package** en el **Boards Manager** del Arduino IDE.


## 🛠️ Instalación del soporte para ESP32 en Arduino IDE

Para poder compilar y cargar correctamente este proyecto en una placa ESP32, es necesario instalar el paquete oficial de placas ESP32 en el **Arduino IDE**.

### 🔗 URL del gestor de tarjetas

Agregar la siguiente URL en las preferencias del Arduino IDE:
- **https://espressif.github.io/arduino-esp32/package_esp32_index.json**
- Rama de desarrollo: https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json

### 🧭 Pasos para la instalación

1. **Abrir el Arduino IDE**.
2. Dirigirse a `Archivo` → `Preferencias`.
3. En el campo **"Gestor de URLs Adicionales de Tarjetas"**, pegar la URL anterior.
   > Si ya hay URLs añadidas, separalas con una coma.
4. Hacer clic en **"OK"** para guardar.
5. Ahora dirigirse a `Herramientas` → `Placa` → `Gestor de placas o tarjetas`.
6. Buscar "**esp32**" y seleccionar la opción publicada por **Espressif Systems**.
7. Hacer clic en **"Instalar"**
8. Esperar a que finalice la descarga e instalación (puede tardar unos minutos).

Una vez completado, se podrá seleccionar la placa como la **Heltec WiFi LoRa 32 (ESP32-S3)** desde el menú de placas.

> ✅ Recomendación: Tener el Arduino IDE actualizado.

---

## 📄 Licencia

Este proyecto está licenciado bajo los términos de la **Licencia MIT**.

Esto significa que:

- Se puede **usar, copiar, modificar, fusionar, publicar, distribuir, sublicenciar** y/o vender copias del software.
- Se debe incluir una copia del aviso de copyright y la licencia.
- El software se proporciona **"tal cual"**, sin garantías de ningún tipo, expresas o implícitas.

Para más detalles, consultá el archivo [`LICENSE`](./LICENSE) incluido en este repositorio.

---

## 🚀 Instrucciones de compilación (Arduino IDE)

1. Clonar este repositorio:

```bash
git clone https://gitlab.com/business-lab/temhum_ia.git
```

---

> **Autor:** Diego Andrés García Díaz (@dagdmfc) - 2025
