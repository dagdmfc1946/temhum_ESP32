// *************************************************************************************************
// --------------------------------- USO LED INTERNO DE LA PLACA -----------------------------------
// *************************************************************************************************
/*
  Archivo: uso_LED.h
  Version: 1.0
  Funcion: Configura el LED interno de la ESP32 de 30 pines para generar señales visuales de estado.
  Autor: Diego Andres Garcia Diaz (@dagdmfc)
*/
// *************************************************************************************************

#include "parameters.h"

// ---------------------------- FUNCION PARA INICIALIZAR EL LED INTERNO ----------------------------
void initLED() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW); // Apagado por defecto
}
// *************************************************************************************************
