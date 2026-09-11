// ***************************************************************************************************
// ------------------------ OBTENER LECTURAS DE LA TENSION DE LA BATERIA (mV) ------------------------
// ***************************************************************************************************
/*
  Archivo: lectura_Vbatt.h
  Version: 1.0
  Funcion: Realiza la lectura de bateria mediante el ADC del GPIO34 y aplica el factor de correccion
           correspondiente al divisor resistivo utilizado en el circuito.
  Autor: Diego Andres Garcia Diaz (@dagdmfc)
*/
// ***************************************************************************************************

#include "parameters.h"

// ------------------------ OBTENER LECTURA DE LA TENSION DE LA BATERIA -----------------------------
int read_VBatt() {
  analogReadResolution(12); // Resolucion ADC de 12 bits, valores de 0 a 4095
  analogSetPinAttenuation(PIN_VBAT_ADC, ADC_11db); // Rango ampliado de entrada del ADC

  delay(10); // Tiempo para estabilizar la señal antes de leer
  int mV = analogReadMilliVolts(PIN_VBAT_ADC); // Tension medida en el pin ADC
  int voltage_batt = (int)(mV * VBAT_DIVIDER_FACTOR); // Corrige el divisor resistivo

  Serial.printf("VBatt = %d mV\n", voltage_batt);
  return voltage_batt;
}
// ***************************************************************************************************
