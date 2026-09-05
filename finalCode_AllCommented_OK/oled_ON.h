// *************************************************************************************************
// ---------------------- LLAMADO DE FUNCIONES A USAR PARA LA PANTALLA OLED ------------------------
// *************************************************************************************************
/*
  Archivo: oled_ON.h
  Versión: 1.0
  Función: Declaración de prototipos de funciones utilizadas para la gestión de la pantalla OLED.
  Autor: Diego Andrés García Díaz (@dagdmfc)
*/
// *************************************************************************************************

#include "parameters.h" // Contiene configuraciones de pines (#define) y parámetros del sistema (NO ES NECESARIO MODIFICAR)
#include "Wire.h" // Librería para comunicación I2C
#include "HT_SSD1306Wire.h" // Librería específica para manejar pantallas OLED con el controlador SSD1306


// *************************************************************************************************

// --------------------------- Prototipos de funciones de pantalla OLED ----------------------------

void VextON(); // Enciende Vext (3.3 V) para alimentar pantalla OLED
void VextOFF(); // Apaga Vext alimentación pantalla OLED
void initOLED(); // Inicializa la pantalla OLED
void mostrarDatosOLED(float temp, float hum); // Muestra temperatura y humedad en pantalla OLED
void mostrarErrorSensorOLED(); // Muestra mensaje de error al fallar lectura del sensor DHT
void mostrarAdvertenciaBateria(); // Muestra advertencia por batería baja
void mostrarConectadoWiFi(); // Mensaje de conexión exitosa a Wi-Fi
void mostrarConexionWiFiOLED(); // Mensaje durante intento de conexión Wi-Fi
void mostrarErrorWiFiOLED(); // Error de conexión Wi-Fi
void mostrarErrorPostOLED(); // Error al enviar POST al servidor
void mostrarSendDataOLED(); // Éxito en el envío de POST
void mostrarDeepSleepOLED(); // Mensaje de entrada en Deep Sleep
void apagarOLED(); // Apaga pantalla OLED y alimentación

// *************************************************************************************************
