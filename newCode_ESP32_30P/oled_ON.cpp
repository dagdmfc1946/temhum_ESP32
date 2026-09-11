// ******************************************************************************************************
// ------------------------------- USO PANTALLA OLED (0.96) -------------------------------------------
// ******************************************************************************************************
/*
  Archivo: oled_ON.cpp
  Version: 1.0
  Funcion: Implementa las funciones de visualizacion para una OLED SSD1306 de 128x64 pixeles.
           La comunicacion se realiza mediante I2C usando las librerias Adafruit_GFX y
           Adafruit_SSD1306.
  Autor: Diego Andres Garcia Diaz (@dagdmfc)
*/
// *************************************************************************************************

#include "oled_ON.h"
#include "WiFi.h"

Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, OLED_RESET);

// --------------------------- Inicializacion y apagado de pantalla -------------------------------
void initOLED() {
  Wire.begin(SDA_OLED, SCL_OLED);
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println("ERROR al inicializar la pantalla OLED");
    return;
  }
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setTextWrap(false);
}

void apagarOLED() {
  display.ssd1306_command(SSD1306_DISPLAYOFF);
  Wire.end();
}

// ----------------------------- Funciones auxiliares de visualizacion ---------------------------
static void mostrarTresLineas(const char* linea1, const char* linea2, const char* linea3, uint8_t textoSize) {
  initOLED();
  display.clearDisplay();
  display.setTextSize(textoSize);
  display.setTextColor(SSD1306_WHITE);
  display.setTextWrap(false);

  display.setCursor(0, 0);
  display.println(linea1);
  display.setCursor(0, 24);
  display.println(linea2);
  display.setCursor(0, 48);
  display.println(linea3);
  display.display();
}

// ----------------------------- Funciones de visualizacion OLED ---------------------------------
void mostrarDatosOLED(float temp, float hum) {
  initOLED();
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 8);
  display.printf("T: %.1f C", temp);
  display.setCursor(0, 36);
  display.printf("H: %.1f %%", hum);
  display.display();
  delay(2000);
}

void mostrarErrorSensorOLED() {
  mostrarTresLineas("ERROR", "LECTURA", "DHT11", 2);
  unsigned long startTime = millis();
  while (millis() - startTime < 2000) {
    digitalWrite(LED, HIGH);
    delay(400);
    digitalWrite(LED, LOW);
    delay(400);
  }
  delay(1000);
}

void mostrarAdvertenciaBateria() {
  mostrarTresLineas("LOW", "BATTERY", "", 2);
  delay(2000);
  unsigned long startTime = millis();
  while (millis() - startTime < 2000) {
    digitalWrite(LED, HIGH);
    delay(50);
    digitalWrite(LED, LOW);
    delay(50);
  }
}

void mostrarConexionWiFiOLED() {
  mostrarTresLineas("Conectando", "a red", "Wi-Fi...", 2);
}

void mostrarConectadoWiFi() {
  mostrarTresLineas("Conexion", "Wi-Fi", "exitosa", 2);
  delay(1000);

  initOLED();
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 20);
  display.println("MAC:");
  display.setCursor(0, 40);
  display.println(WiFi.macAddress());
  display.display();
  delay(800);
  digitalWrite(LED, LOW);
}

void mostrarErrorWiFiOLED() {
  mostrarTresLineas("ERROR", "conexion", "Wi-Fi", 2);
  digitalWrite(LED, HIGH);
  delay(5000);
}

void mostrarErrorPostOLED() {
  mostrarTresLineas("ERROR", "POST en", "servidor", 2);
  unsigned long startTime = millis();
  while (millis() - startTime < 2000) {
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(100);
  }
}

void mostrarSendDataOLED() {
  mostrarTresLineas("POST", "CORRECTO", "servidor", 2);
  digitalWrite(LED, HIGH);
  delay(2000);
  digitalWrite(LED, LOW);
}

void mostrarDeepSleepOLED() {
  mostrarTresLineas("Modo", "DEEP SLEEP", "Zzzzzz...", 2);
  delay(1500);
}
// *************************************************************************************************
