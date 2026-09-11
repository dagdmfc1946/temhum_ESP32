// *******************************************************************************************
// ---------------------------------- ARCHIVO PRINCIPAL --------------------------------------
// >>> IMPORTANTE: Para que funcione correctamente el modo Deep Sleep, todo el codigo debe
// ejecutarse dentro de void setup(). <<<
// *******************************************************************************************
/*
  Archivo: newCode_ESP32_30P.ino
  Version: 1.0
  Funcion: Programa principal para una ESP32 de 30 pines. Lee un sensor DHT11, muestra los datos
           en una pantalla OLED SSD1306 de 0.96", mide la tension de bateria mediante el ADC del
           GPIO34, envia los datos por HTTP POST y entra en modo Deep Sleep.
  Autor: Diego Andres Garcia Diaz (@dagdmfc)
*/
// *******************************************************************************************

#include "includess.h"

// ----------------------------- FUNCION PRINCIPAL A EJECUTAR --------------------------------
void setup() {
  Serial.begin(115200);
  initLED();
  Serial.println("\nESP32 de 30 pines despierta - LECTURA: Sensor DHT11");

  float TEM = 0.0;
  float HUM = 0.0;
  dataRead_DHT(&TEM, &HUM);
  mostrarDatosOLED(TEM, HUM);

  int V_batt = read_VBatt();
  if (V_batt < 3300) {
    mostrarAdvertenciaBateria();
  }

  connectWiFi();
  enviarDatosPorPOST(TEM, HUM, V_batt);

  mostrarDeepSleepOLED();
  apagarOLED();
  sleep();
}

// ------------------------------- FUNCION QUE NO SE USA ------------------------------------
void loop() {
  // No se utiliza: el dispositivo entra en Deep Sleep al finalizar setup().
}
// *******************************************************************************************
