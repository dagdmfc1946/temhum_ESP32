// ************************************************************************************************************
// ------------------------ SE DEFINEN LIBRERÍAS Y DEMÁS ARCHIVOS (FUNCIONES) A USAR --------------------------
// ************************************************************************************************************
/*
  Archivo: includess.h
  Versión: 1.0
  Función: Archivo de inclusión con todas las cabeceras del sistema. Facilita la modularidad y organización
           del código al importar configuraciones, funciones de sensores, Wi-Fi, HTTP POST, OLED y Deep Sleep.
  Autor: Diego Andrés García Díaz (@dagdmfc)
*/
// ************************************************************************************************************

#include "parameters.h"      // Archivo de parámetros globales (pines, tiempo de sueño, etc.)
#include "uso_LED.h"         // Función de inicialización y control del LED interno de la placa
#include "lectura_DHT.h"     // Función para obtener temperatura y humedad del sensor DHT22
#include "lectura_Vbatt.h"   // Función para leer la tensión de la batería en mV
#include "wifi_ON.h"         // Función para conexión a la red Wi-Fi con credenciales pre-definidas
#include "envioDatosPOST.h"  // Función que estructura y envía datos al servidor por HTTP POST
#include "oled_ON.h"         // Funciones de control de la pantalla OLED (mensajes, errores, datos)
#include "dormir_Placa.h"    // Función para activar el modo de bajo consumo (Deep Sleep) en la placa

// ************************************************************************************************************
