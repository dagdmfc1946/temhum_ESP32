// ***************************************************************************************************
// ----------------------------------------- DEFINICIONES --------------------------------------------
// ***************************************************************************************************
/*
  Archivo: parameters.h
  Version: 1.0
  Funcion: Define los pines y parametros globales del sistema para una ESP32 DevKit de 30 pines.
           La pantalla OLED usa el bus I2C, el DHT11 usa un pin digital y la bateria se mide
           mediante el ADC del GPIO34.
  Autor: Diego Andres Garcia Diaz (@dagdmfc)
*/
// ***************************************************************************************************

// ------------------------------------ Pines del Sensor DHTxx ---------------------------------------
#define DHTPIN 4 // Pin de datos del sensor DHT11
#define DHTTYPE DHT11 // Tipo de sensor utilizado

// ---------------------------------- Pines de Lectura de Voltaje ------------------------------------
#define PIN_VBAT_ADC 34 // GPIO34: entrada ADC para leer la tension de bateria
#define VBAT_DIVIDER_FACTOR 4.9f // Factor del divisor resistivo utilizado en el circuito

// -------------------------------- Configuracion del Deep Sleep -------------------------------------
#define uS_TO_S_FACTOR 1000000ULL // Pasa microsegundos a segundos
#define TIME_TO_SLEEP 300 // Duracion de cada ciclo, en segundos

// -------------------------------- Configuracion de la pantalla OLED -------------------------------
#define SDA_OLED 21 // GPIO21: SDA del bus I2C
#define SCL_OLED 22 // GPIO22: SCL del bus I2C
#define OLED_ADDRESS 0x3C // Direccion I2C habitual de la OLED 0.96"
#define OLED_WIDTH 128 // Resolucion horizontal de la pantalla
#define OLED_HEIGHT 64 // Resolucion vertical de la pantalla
#define OLED_RESET -1 // La pantalla no utiliza pin de reset dedicado

// -------------------------------- Configuracion del LED interno ------------------------------------
#define LED 2 // LED integrado habitual de la ESP32 DevKit
// ***************************************************************************************************
