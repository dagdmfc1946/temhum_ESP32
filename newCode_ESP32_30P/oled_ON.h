// *************************************************************************************************
// ---------------------- LLAMADO DE FUNCIONES PARA LA PANTALLA OLED -------------------------------
// *************************************************************************************************
/*
  Archivo: oled_ON.h
  Version: 1.0
  Funcion: Declara las funciones de visualizacion y control de una pantalla OLED SSD1306 de 0.96"
           mediante las librerias Adafruit_GFX y Adafruit_SSD1306.
  Autor: Diego Andres Garcia Diaz (@dagdmfc)
*/
// *************************************************************************************************

#include "parameters.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void initOLED();
void mostrarDatosOLED(float temp, float hum);
void mostrarErrorSensorOLED();
void mostrarAdvertenciaBateria();
void mostrarEstadoBateria(int voltage);
void mostrarConectadoWiFi();
void mostrarConexionWiFiOLED();
void mostrarErrorWiFiOLED();
void mostrarErrorPostOLED();
void mostrarSendDataOLED();
void mostrarDeepSleepOLED();
void apagarOLED();
// *************************************************************************************************
