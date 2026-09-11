// *************************************************************************************************
// ------------------------------------- CONEXION A RED WI-FI --------------------------------------
// *************************************************************************************************
/*
  Archivo: wifi_ON.h
  Version: 1.0
  Funcion: Gestiona la conexion Wi-Fi con un limite de tiempo y muestra el estado en la pantalla
           OLED y en el LED interno de la ESP32 de 30 pines.
  Autor: Diego Andres Garcia Diaz (@dagdmfc)
*/
// *************************************************************************************************

#include "WiFi.h"
#include "esp_wifi.h"
#include "oled_ON.h"

// ----------------------------- Credenciales de la red Wi-Fi a usar -------------------------------
const char* ssid = "NOMBRE_DE_LA_RED"; // Reemplazar por el nombre de la red Wi-Fi
const char* password = "CONTRASENA_DE_LA_RED"; // Reemplazar por la contraseña de la red Wi-Fi

// ----------------------------- FUNCION PRINCIPAL DE CONEXION WI-FI -------------------------------
void connectWiFi() {
  Serial.println("\nConectando a la red Wi-Fi...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  unsigned long startAttemptTime = millis();
  const unsigned long timeout = 10000;
  mostrarConexionWiFiOLED();

  while (WiFi.status() != WL_CONNECTED && (millis() - startAttemptTime) < timeout) {
    delay(200);
    Serial.print(".");
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
  }

  esp_wifi_set_ps(WIFI_PS_MIN_MODEM);

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConexion Wi-Fi exitosa");
    Serial.print("Direccion MAC: ");
    Serial.println(WiFi.macAddress());
    mostrarConectadoWiFi();
  } else {
    Serial.println("\nERROR: no se pudo conectar a la red Wi-Fi");
    mostrarErrorWiFiOLED();
  }
}
// *************************************************************************************************
