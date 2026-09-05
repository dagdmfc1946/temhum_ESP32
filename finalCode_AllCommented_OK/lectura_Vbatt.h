// ***************************************************************************************************
// ------------------------ OBTENER LECTURAS DE LA TENSIÓN DE LA BATERÍA (mV) ------------------------
// ***************************************************************************************************
/*
  Archivo: lectura_Vbatt.h
  Versión: 1.0
  Función: Realiza la lectura de la tensión de batería en milivoltios (mV), aplicando un factor de 
           corrección al valor ADC leído.
  Autor: Diego Andrés García Díaz (@dagdmfc)
*/
// ***************************************************************************************************

// ------------------------ OBTENER LECTURAS DE LA TENSIÓN DE LA BATERÍA (mV) ------------------------
int read_VBatt() { // FUNCIÓN PRINCIPAL
  analogReadResolution(12); // Configura resolución ADC a 12 bits (valores de 0 a 4095)

  pinMode(PIN_VBAT_CTRL, OUTPUT); // Configura el pin de control del divisor resistivo como salida
  digitalWrite(PIN_VBAT_CTRL, HIGH); // Activa el divisor resistivo para medir la tensión

  delay(10); // Tiempo para que la señal se estabilice antes de la lectura

  int mV = analogReadMilliVolts(PIN_VBAT_ADC); // Lee la tensión analógica directamente en milivoltios

  int voltage_batt = (int)(mV * 4.9); // Corrige el valor en base al divisor resistivo del circuito

  Serial.printf("VBatt = %d mV\n", voltage_batt); // Muestra el resultado en el Monitor Serie

  return voltage_batt; // Retorna la tensión de batería ya corregida en mV
}
// ***************************************************************************************************