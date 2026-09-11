// ***************************************************************************************************
// -------------------------------- SENSADO TEMPERATURA Y HUMEDAD ------------------------------------
// ***************************************************************************************************
/*
  Archivo: lectura_DHT.h
  Version: 1.0
  Funcion: Define y ejecuta la lectura de temperatura y humedad del sensor DHT11. Comprueba errores
           y notifica el resultado en la pantalla OLED y mediante el LED de la placa.
  Autor: Diego Andres Garcia Diaz (@dagdmfc)
*/
// **************************************************************************************************

#include "parameters.h"
#include "DHT.h"
#include "oled_ON.h"

DHT dht(DHTPIN, DHTTYPE);

// --------------------------- FUNCION PRINCIPAL PARA LECTURA DE SENSOR -----------------------------
void dataRead_DHT(float* temp, float* hum) {
  Serial.println("Iniciando proceso de lectura del DHT11...");
  dht.begin();

  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (isnan(t) || isnan(h)) {
    Serial.println("ERROR en la lectura del sensor DHT11");
    mostrarErrorSensorOLED();
    *temp = 0;
    *hum = 0;
  } else {
    *temp = t;
    *hum = h;
    Serial.printf("Temperatura: %.1f C\tHumedad: %.1f %%\n", t, h);
  }
}
// *************************************************************************************************
