// ***************************************************************************************************
// ----------------------------------------- DEFINICIONES --------------------------------------------
// ***************************************************************************************************
/*
  Archivo: parameters.h
  Versión: 1.0
  Función: Define las constantes, pines y parámetros globales del sistema como pines del sensor DHT22, 
           pines de lectura de batería, duración del Deep Sleep y configuración del LED interno.
  Autor: Diego Andrés García Díaz (@dagdmfc)
*/
// ***************************************************************************************************

// ------------------------------------ Pines del Sensor DHTxx ---------------------------------------
#define DHTPIN 3 // Pin para los datos del sensor DHT22
#define DHTTYPE DHT22 // Descomentar si se usa el DHT22
//#define DHTTYPE DHT11 // Descomentar si se usa el DHT11
// La inicialización del sensor, 'DHT dht(DHTPIN, DHTTYPE)' se realiza en 'lectura_DHT.h'


// ---------------------------------- Pines de Lectura de Voltaje ------------------------------------
#define PIN_VBAT_CTRL 37 // Pin para el control ADC
#define PIN_VBAT_ADC 1 // Lectura del valor analógico


// -------------------------------- Configuración del Deep Sleep -------------------------------------
#define uS_TO_S_FACTOR 1000000ULL // Pasa microsegundos a segundos
// Modificar según el tiempo de toma de datos que se desee
#define TIME_TO_SLEEP  300 // Duración de cada ciclo (segundos)
// ***************************************************************************************************


// ***************************************************************************************************
// ------------------------------ Configuración de la pantalla OLED ----------------------------------
// Definiciones de pines para el bus I2C de la OLED y alimentación Vext
// NO DESCOMENTAR ya que están definidos por la placa Heltec WiFi LoRa 32 V3
//#define SDA_OLED 21
//#define SCL_OLED 22
//#define RST_OLED -1
//#define Vext 36


// -------------------------------- Configuración del LED interno ------------------------------------
//#define LED 35 // LED interno de la placa Heltec WiFi LoRa 32 V3 // NO DESCOMENTAR
// ***************************************************************************************************