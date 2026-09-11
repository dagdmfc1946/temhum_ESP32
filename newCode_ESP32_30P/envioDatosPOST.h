// *************************************************************************************************
// ---------------------------------- ENVIO DE DATOS AL SERVIDOR -----------------------------------
// *************************************************************************************************
/*
  Archivo: envioDatosPOST.h
  Version: 1.0
  Funcion: Envia por HTTP POST la MAC del dispositivo, temperatura, humedad y tension de bateria
           en formato JSON. El endpoint debe ser configurado antes de usar el dispositivo.
  Autor: Diego Andres Garcia Diaz (@dagdmfc)
*/
// *************************************************************************************************

#include "HTTPClient.h"
#include "WiFi.h"
#include "oled_ON.h"

// ---------------------------- Configuracion del endpoint del servidor ----------------------------
const String serverURL = "http://DIRECCION_DEL_SERVIDOR:8000/moe/telemetry/registro_temp_hum";

// ------------------------------- FUNCION PRINCIPAL ENVIO DE DATOS -------------------------------
void enviarDatosPorPOST(float temp, float hum, int v_batt) {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Reintentando conexion a la red Wi-Fi...");
    connectWiFi();
  }

  HTTPClient http;
  String mac = WiFi.macAddress();
  int temp_int = (int)(temp * 10);
  int hum_int = (int)hum;

  String jsonPayload = "{";
  jsonPayload += "\"mac\":\"" + mac + "\",";
  jsonPayload += "\"values\":{";
  jsonPayload += "\"temperature\":" + String(temp_int) + ",";
  jsonPayload += "\"humidity\":" + String(hum_int);
  jsonPayload += "},";
  jsonPayload += "\"battery\":{";
  jsonPayload += "\"voltage\":" + String(v_batt) + ",";
  jsonPayload += "\"level\":0";
  jsonPayload += "}}";

  Serial.println("\nEnvio de datos en formato JSON:");
  Serial.println(jsonPayload);

  http.begin(serverURL);
  http.addHeader("Content-Type", "application/json");
  int httpResponseCode = http.POST(jsonPayload);

  if (httpResponseCode > 0) {
    Serial.printf("POST exitoso. Codigo HTTP: %d\n", httpResponseCode);
    Serial.println(http.getString());
    mostrarSendDataOLED();
  } else {
    Serial.printf("ERROR en POST: %s\n", http.errorToString(httpResponseCode).c_str());
    mostrarErrorPostOLED();
  }

  http.end();
}
// *************************************************************************************************
