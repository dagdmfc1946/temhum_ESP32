// *************************************************************************************************
// --------------------------------- USO LED INTERNO DE LA PLACA -----------------------------------
// *************************************************************************************************
/*
  Archivo: uso_LED.h
  Versión: 1.0
  Función: Configura el LED interno de la placa para generar señales visuales de estado del sistema. 
           Apoya la interpretación de errores en conjunto con la pantalla OLED.
  Autor: Diego Andrés García Díaz (@dagdmfc)
*/
// *************************************************************************************************

// ---------------------------- FUNCIÓN PARA INICIALIZAR EL LED INTERNO ----------------------------
void initLED() { // FUNCIÓN PRINCIPAL
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW); // Apagado por defecto
}
// *************************************************************************************************
















// LED parpadea para enviar los datos
// void ledBlinkEnvio() { // FUNCIÓN PRINCIPAL
//   unsigned long startTime = millis();
//   while (millis() - startTime < 1000) { // 1 segundos
//     digitalWrite(LED, HIGH);
//     delay(100);
//     digitalWrite(LED, LOW);
//     delay(100);
//   }
// }
// -------------------------------------------------------------------------------------------------
//
// LED parpadea para indicar error de lectura del sensor
// void ledErrorLecturaDHT() {
//   unsigned long startTime = millis();
//   while (millis() - startTime < 1500) { // 3 segundos
//     digitalWrite(LED, HIGH);
//     delay(400);
//     digitalWrite(LED, LOW);
//     delay(400);
//   }
// }
// -------------------------------------------------------------------------------------------------
//
// LED parpadea mientras se establece la conexión WiFi
// void ledBlinkConexionWiFi() {
//   unsigned long startTime = millis();
//   while (millis() - startTime < 10000) { // 10 segundos
//     digitalWrite(LED, HIGH);
//     delay(200);
//     digitalWrite(LED, LOW);
//     delay(200);
//   }
// }
// -------------------------------------------------------------------------------------------------
//
// LED encendido si se envian los datos bien
// void ledSendDataOK() { // YA
//   digitalWrite(LED, HIGH);
//   delay(1500);
//   digitalWrite(LED, LOW);
// }
// -------------------------------------------------------------------------------------------------
//
// LED parpadea para indicar ERROR en POST al servidor
// void ledErrorPOST() { // YA
//   unsigned long startTime = millis();
//   while (millis() - startTime < 2000) { // 2 segundos
//     digitalWrite(LED, HIGH);
//     delay(100);
//     digitalWrite(LED, LOW);
//     delay(100);
//   }
// }
// -------------------------------------------------------------------------------------------------
//
// LED parpadea para indicar batería baja
// void ledBlinkBattery() { // YA
//   unsigned long startTime = millis();
//   while (millis() - startTime < 2000) { // 2 segundos
//     digitalWrite(LED, HIGH);
//     delay(50);
//     digitalWrite(LED, LOW);
//     delay(50);
//   }
// }
// *************************************************************************************************