// ******************************************************************************************************
// ------------------------------- USO PANTALLA OLED (0.96) INTEGRADA -----------------------------------
// ******************************************************************************************************
/*
  Archivo: oled_ON.cpp
  Versión: 1.0
  Función: Implementa funciones de visualización en pantalla OLED para mostrar datos, errores,
           estado del sistema, y alertas. Controla además la alimentación de la pantalla OLED.
  Autor: Diego Andrés García Díaz (@dagdmfc)
*/
// *************************************************************************************************

#include "oled_ON.h" // Archivo cabecera con declaraciones de funciones de uso para la pantalla OLED
#include "WiFi.h" // Librería neecesaria para mostrar MAC en pantalla OLED

// *************************************************************************************************

// --------------------------- Inicializa el objeto de la pantalla OLED ----------------------------
static SSD1306Wire display(0x3c, 500000, SDA_OLED, SCL_OLED, GEOMETRY_128_64, RST_OLED);

// *************************************************************************************************

// ------------------ FUNCIONES PARA CONTROL DE ALIMENTACIÓN DE LA PANTALLA OLED -------------------
// Alimentación ON pantalla OLED
void VextON() { // FUNCIÓN PRINCIPAL ON
  pinMode(Vext, OUTPUT); // Configura el pin de alimentación OLED como salida
  digitalWrite(Vext, LOW); // Enciende Vext (activa alimentación de 3.3 V a pantalla OLED)
}
// -------------------------------------------------------------------------------------------------

// Alimentación OFF pantalla OLED
void VextOFF() { // FUNCIÓN PRINCIPAL OFF
  pinMode(Vext, OUTPUT); // Configura el pin de alimentación OLED como salida
  digitalWrite(Vext, HIGH); // Apaga Vext (corta alimentación a pantalla OLED)
}
// *************************************************************************************************


// --------------------- Inicialización y apagado de pantalla OLED ---------------------------------
// Inicializa pantalla OLED
void initOLED() { // FUNCIÓN PRINCIPAL
  VextON(); // Enciende la pantalla OLED
  delay(100); // Retraso para estabilizar la inicialización de la pantalla OLED
  display.init(); // Inicializa controlador pantalla OLED
}
// -------------------------------------------------------------------------------------------------

// Desctiva pantalla OLED
void apagarOLED() { // FUNCIÓN PRINCIPAL
  display.displayOff(); // Apaga visualización del display en la pantalla OLED
  VextOFF(); // Apaga la pantalla OLED
}
// *************************************************************************************************


// ----------------------------- FUNCIONES DE VISUALIZACIÓN OLED ----------------------------------
// display.fill(0) → Rellena todo de negro (equivalente a clear).
// display.fill(255) → Pantalla blanca (para "borrado" visible).

// Muestra texto con lecturas del sensor en pantalla OLED
void mostrarDatosOLED(float temp, float hum) { // FUNCIÓN PRINCIPAL
  initOLED(); // Inicialización de la pantalla OLED
  display.setFont(ArialMT_Plain_24); // Tamaño de fuente grande
  display.setTextAlignment(TEXT_ALIGN_CENTER); // Centrado horizontal
  String strTemp = "T: " + String(temp, 1) + " °C"; // Formato para la temperatura
  String strHum  = "H: " + String(hum, 1) + " %"; // Formato para la humedad
  display.clear(); // Limpia la pantalla antes de dibujar nuevos datos
  display.drawString(64, 8, strTemp); // Muestra temperatura en pantalla OLED 
  display.drawString(64, 36, strHum); // Muestra humedad en pantalla OLED
  display.display(); // Actualiza físicamente la pantalla (necesario tras clear)
  delay(2000); // Retraso de 2 segundos para visualización
}
// -------------------------------------------------------------------------------------------------

// Muestra mensaje de ERROR de lectura del sensor en pantalla OLED
void mostrarErrorSensorOLED() { // FUNCIÓN PRINCIPAL
  initOLED(); // Inicialización de la pantalla OLED
  display.clear(); // Limpia la pantalla antes de dibujar nuevos datos
  display.setFont(ArialMT_Plain_16); // Tamaño de fuente medio
  display.setTextAlignment(TEXT_ALIGN_CENTER); // Centrado horizontal
  display.drawString(64, 5, "¡ERROR"); // Texto a mostrar
  display.drawString(64, 25, "LECTURA"); // Texto a mostrar
  display.drawString(64, 45, "DHT22!"); // Texto a mostrar
  display.display(); // Actualiza físicamente la pantalla (necesario tras clear)
  //delay(2000); // Retraso de 2 segundos para visualización
  
  // LED
  unsigned long startTime = millis(); // Implementa retardos sin bloquear el código (multi-tarea)
  while (millis() - startTime < 2000) { // 2 segundos ON/OFF
    digitalWrite(LED, HIGH); // LED encendido 
    delay(400); // Retraso de 0.4 segundos
    digitalWrite(LED, LOW); // LED apagado 
    delay(400); // Retraso de 0.4 segundos
  }

  delay(2000); // Retraso de 2 segundos para visualización
}
// -------------------------------------------------------------------------------------------------

// Muestra mensaje de batería baja en pantalla OLED
void mostrarAdvertenciaBateria() { // FUNCIÓN PRINCIPAL
  initOLED(); // Inicialización de la pantalla OLED
  display.clear(); // Limpia la pantalla antes de dibujar nuevos datos
  display.setFont(ArialMT_Plain_24); // Tamaño de fuente grande
  display.setTextAlignment(TEXT_ALIGN_CENTER); // Centrado horizontal
  display.drawString(64, 10, "¡LOW"); // Texto a mostrar
  display.drawString(64, 38, "BATTERY!"); // Texto a mostrar
  display.display(); // Actualiza físicamente la pantalla (necesario tras clear)
  delay(2000); // Retraso de 2 segundos para visualización
  
  // LED
  unsigned long startTime = millis(); // Implementa retardos sin bloquear el código (multi-tarea)
  while (millis() - startTime < 2000) { // 2 segundos ON/OFF
    digitalWrite(LED, HIGH); // LED encendido 
    delay(50); // Retraso de 0.05 segundos
    digitalWrite(LED, LOW); // LED apagado
    delay(50); // Retraso de 0.05 segundos
  }
}
// -------------------------------------------------------------------------------------------------

// Muestra mensaje de conexión a Wi-Fi en pantalla OLED
void mostrarConexionWiFiOLED() { // FUNCIÓN PRINCIPAL
  initOLED(); // Inicialización de la pantalla OLED
  display.clear(); // Limpia la pantalla antes de dibujar nuevos datos
  display.setFont(ArialMT_Plain_16); // Tamaño de fuente medio 
  display.setTextAlignment(TEXT_ALIGN_CENTER); // Centrado horizontal
  display.drawString(64, 5,  "Conectando"); // Texto a mostrar
  display.drawString(64, 25, "a red"); // Texto a mostrar
  display.drawString(64, 45, "Wi-Fi..."); // Texto a mostrar
  display.display(); // Actualiza físicamente la pantalla (necesario tras clear)
}
// -------------------------------------------------------------------------------------------------

// Muestra mensaje de conexión CORRECTA a Wi-Fi en pantalla OLED
void mostrarConectadoWiFi() { // FUNCIÓN PRINCIPAL
  // Visualización de Conectando a Wi-Fi...
  initOLED(); // Inicialización de la pantalla OLED
  display.clear(); // Limpia la pantalla antes de dibujar nuevos datos
  display.setFont(ArialMT_Plain_16); // Tamaño de fuente medio
  display.setTextAlignment(TEXT_ALIGN_CENTER); // Centrado horizontal
  display.drawString(64, 5,  "¡Conexión"); // Texto a mostrar
  display.drawString(64, 25, "Wi-Fi"); // Texto a mostrar
  display.drawString(64, 45, "exitosa!"); // Texto a mostrar
  display.display(); // Actualiza físicamente la pantalla (necesario tras clear)
  delay(1000); // Retraso de 1 segundo para visualización
  
  // Visualización de MAC
  display.clear(); // Limpia la pantalla antes de dibujar nuevos datos
  display.setFont(ArialMT_Plain_10); // Tamaño de fuente pequeño
  display.setTextAlignment(TEXT_ALIGN_CENTER); // Centrado horizontal
  String mac = WiFi.macAddress(); // Guarda la MAC del dispositivo
  display.drawString(64, 15, "MAC:"); // Texto a mostrar
  display.drawString(64, 35, mac); // Muestra la MAC en la pantalla OLED
  display.display(); // Actualiza físicamente la pantalla (necesario tras clear)
  delay(800); // Retraso de 0.8 segundos para visualización
  
  // LED
  digitalWrite(LED, LOW); // LED apagado si se logra una CORRECTA CONEXIÓN A WI-FI
}
// -------------------------------------------------------------------------------------------------

// Muestra mensaje de ERROR en conexión Wi-Fi en pantalla OLED
void mostrarErrorWiFiOLED() { // FUNCIÓN PRINCIPAL
  initOLED(); // Inicialización de la pantalla OLED
  display.clear(); // Limpia la pantalla antes de dibujar nuevos datos
  display.setFont(ArialMT_Plain_16); // Tamaño de fuente medio
  display.setTextAlignment(TEXT_ALIGN_CENTER); // Centrado horizontal
  display.drawString(64, 5,  "¡ERROR"); // Texto a mostrar
  display.drawString(64, 25, "conexión"); // Texto a mostrar
  display.drawString(64, 45, "Wi-Fi!"); // Texto a mostrar
  display.display(); // Actualiza físicamente la pantalla (necesario tras clear)
  
  // LED
  digitalWrite(LED, HIGH); // LED encendido indica FALLO en conexión Wi-Fi
  delay(5000); // Retraso de 5 segundos
}
// -------------------------------------------------------------------------------------------------

// Muestra mensaje de ERROR en POST en pantalla OLED
void mostrarErrorPostOLED() { // FUNCIÓN PRINCIPAL
  initOLED(); // Inicialización de la pantalla OLED
  display.clear(); // Limpia la pantalla antes de dibujar nuevos datos
  display.setFont(ArialMT_Plain_16); // Tamaño de fuente medio
  display.setTextAlignment(TEXT_ALIGN_CENTER); // Centrado horizontal
  display.drawString(64, 5,  "¡ERROR"); // Texto a mostrar
  display.drawString(64, 25, "POST en"); // Texto a mostrar
  display.drawString(64, 45, "servidor!"); // Texto a mostrar
  display.display(); // Actualiza físicamente la pantalla (necesario tras clear)
  //delay(2000); // Retraso de 2 segundos para visualización

  // LED
  unsigned long startTime = millis(); // Implementa retardos sin bloquear el código (multi-tarea)
  while (millis() - startTime < 2000) { // 2 segundos ON/OFF
    digitalWrite(LED, HIGH); // LED encendido 
    delay(100); // Retraso de 0.1 segundos
    digitalWrite(LED, LOW); // LED apagado 
    delay(100); // Retraso de 0.1 segundos
  }
}
// -------------------------------------------------------------------------------------------------

// Muestra mensaje de envio (POST) CORRECTO en pantalla OLED
void mostrarSendDataOLED() { // FUNCIÓN PRINCIPAL
  initOLED(); // Inicialización de la pantalla OLED
  display.clear(); // Limpia la pantalla antes de dibujar nuevos datos
  display.setFont(ArialMT_Plain_16); // Tamaño de fuente medio
  display.setTextAlignment(TEXT_ALIGN_CENTER); // Centrado horizontal
  display.drawString(64, 5,  "¡POST"); // Texto a mostrar
  display.drawString(64, 25, "CORRECTO en"); // Texto a mostrar
  display.drawString(64, 45, "servidor!"); // Texto a mostrar
  display.display(); // Actualiza físicamente la pantalla (necesario tras clear)
  
  // LED
  digitalWrite(LED, HIGH); // LED encendido para indicar POST CORRECTO en servidor
  delay(2000); // Retraso de 2 segundos
  digitalWrite(LED, LOW); // LED apagado
}
// -------------------------------------------------------------------------------------------------

// Muestra mensaje de DEEP SLEEP en pantalla OLED
void mostrarDeepSleepOLED() { // FUNCIÓN PRINCIPAL
  initOLED(); // Inicialización de la pantalla OLED
  display.clear(); // Limpia la pantalla antes de dibujar nuevos datos
  display.setFont(ArialMT_Plain_16); // Tamaño de fuente medio
  display.setTextAlignment(TEXT_ALIGN_CENTER); // Centrado horizontal
  display.drawString(64, 5,  "¡Mode"); // Texto a mostrar
  display.drawString(64, 25, "DEEP SLEEP!"); // Texto a mostrar
  display.drawString(64, 45, "Zzzzzz..."); // Texto a mostrar
  display.display(); // Actualiza físicamente la pantalla (necesario tras clear)
  delay(1500); // Retraso de 1.5 segundos para visualización
}
// *************************************************************************************************