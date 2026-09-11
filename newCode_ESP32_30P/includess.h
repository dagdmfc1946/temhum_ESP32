// ************************************************************************************************************
// ------------------------ SE DEFINEN LIBRERIAS Y DEMAS ARCHIVOS (FUNCIONES) A USAR --------------------------
// ************************************************************************************************************
/*
  Archivo: includess.h
  Version: 1.0
  Funcion: Archivo de inclusion con todas las cabeceras del sistema. Facilita la modularidad y organizacion
           del codigo al importar configuracion, sensores, Wi-Fi, HTTP POST, OLED y Deep Sleep.
  Autor: Diego Andres Garcia Diaz (@dagdmfc)
*/
// ************************************************************************************************************

#include "parameters.h"      // Parametros globales: pines y tiempo de sueño
#include "uso_LED.h"         // Inicializacion y control del LED interno
#include "lectura_DHT.h"     // Lectura del sensor DHT11
#include "lectura_Vbatt.h"   // Lectura de la tension de bateria
#include "wifi_ON.h"         // Conexion a la red Wi-Fi
#include "envioDatosPOST.h"  // Envio de datos al servidor por HTTP POST
#include "oled_ON.h"         // Control de la pantalla OLED Adafruit SSD1306
#include "dormir_Placa.h"    // Activacion del modo Deep Sleep

// ************************************************************************************************************
