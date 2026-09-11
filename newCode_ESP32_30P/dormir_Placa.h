// ******************************************************************************************************
// ----------------------------------------- MODO DEEP SLEEP --------------------------------------------
// ******************************************************************************************************
/*
  Archivo: dormir_Placa.h
  Version: 1.0
  Funcion: Apaga Wi-Fi, Bluetooth, SPI e I2C y configura el temporizador para poner la ESP32 en
           modo Deep Sleep. Al despertar, el chip vuelve a ejecutar el programa desde setup().
  Autor: Diego Andres Garcia Diaz (@dagdmfc)
*/
// ******************************************************************************************************

#include "WiFi.h"
#include "esp_bt.h"
#include "esp_sleep.h"
#include "SPI.h"

// ----------------------------------- FUNCION PRINCIPAL DEEP SLEEP ---------------------------------
void sleep() {
  WiFi.mode(WIFI_OFF);
  btStop();
  esp_bt_controller_disable();
  SPI.end();
  Wire.end();

  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  Serial.println("\nEntrando en Sueño Profundo...");
  Serial.flush();
  esp_deep_sleep_start();

  Serial.println("ERROR en Deep Sleep. Reiniciando...");
  Serial.flush();
  delay(5000);
  ESP.restart();
}
// ******************************************************************************************************
