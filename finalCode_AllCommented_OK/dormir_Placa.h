// ******************************************************************************************************
// ----------------------------------------- MODO DEEP SLEEP --------------------------------------------
// ******************************************************************************************************
/*
  Archivo: dormir_Placa.h
  Versión: 1.0
  Función: Ejecuta la rutina para poner el ESP32 en modo Deep Sleep. Apaga periféricos, Wi-Fi, Bluetooth, 
           y configura el temporizador de reactivación.
           >>> El chip (ESP32-S3) pierde todo el contenido de RAM durante el Deep Sleep, por esta razón el 
           código arranca de cero cada vez. Para hacer esto repetitivo se llama la función 'esp_deep_sleep()'
           al final del 'void setup()' y previamente en el archivo 'parameters.h' se configura el tiempo 
           de sueño en segundos en: "#define TIME_TO_SLEEP  300 // Duración de cada ciclo (segundos)". <<<
  Autor: Diego Andrés García Díaz (@dagdmfc)
*/
// ******************************************************************************************************

#include "esp_bt.h" // Librería para controlar el Bluetooth del ESP32
#include "esp_sleep.h" // Libreía para funciones de bajo consumo (Deep Sleep y Ligth Sleep)
#include "SPI.h" // Librería para la comunicación con dispositivos SPI (sensores, pantallas, entre otros)

// ******************************************************************************************************

// ----------------------------------- FUNCIÓN PRINCIPAL DEEP SLEEP -------------------------------------
void sleep() { // FUNCIÓN PRINCIPAL
  WiFi.mode(WIFI_OFF); // Apaga el Wi-Fi para reducir el consumo energético
  //WiFi.setSleep(true);  // Alternativa compatible con entorno de Arduino --> COMPILA CORRECTAMENTE (requiere pruebas)
  //esp_wifi_stop(); // Alternativa para apagar el WiFi completamente (requiere pruebas)

  btStop(); // Detiene el Bluetooth en alto nivel
  esp_bt_controller_disable(); // Apaga el controlador Bluetooth a nivel hardware

  SPI.end(); // Desactiva bus SPI para asegurar bajo consumo
  Wire.end(); // Finaliza el bus I2C (en caso de haberse utilizado)
  //Radio.Sleep(); // Comando para poner el módulo LoRa en sueño (Genera ERROr, tal vez es por Librería)
  
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR); // Configura temporizador de sueño usando macro TIME_TO_SLEEP (en segundos), se define en el archivo 'parameters.h'
  Serial.println("\n💤 Entrando en Sueño Profundo... 💤\n");   Serial.println("\nConectando a la red WiFi..."); // Notificación por consola
  Serial.flush(); // Espera a que toda la información serial sea enviada antes de continuar con la ejecución
  
  //gpio_deep_sleep_hold_en() // Obligar a todos los pines a mantener su estado durante el sueño profundo (Genera error (Librería?!), o puede que se use solo en el entorno ESP-IDF)
  
  esp_deep_sleep_start(); // Inicia el modo de Sueño Profundo (Deep Sleep)
  //
  // ---------------- En caso de falla (No debería) | Reinicia y/o Verifica manualmente -----------------
  /* 
  ESTA PARTE SERÍA PARA LA VERIFICACIÓN DEL USUARIO FINAL AL DISPOSITIVO, ES DECIR, SI SE PRESIONA EL 
  BOTÓN 'RST' Y EL USUARIO FINAL OBSERVA INMEDIATAMENTE LA LECTURA DEL SENSOR A TRAVÉS DE LA PANTALLA OLED  
  */
  Serial.println("⚠ ¡ERROR en Deep Sleep!\t Reiniciando en 5 segundos..."); // Notificación por consola
  Serial.flush(); // Espera a que toda la información serial sea enviada antes de continuar con la ejecución
  delay(5000); // Espera 5 segundos antes de reiniciar
  ESP.restart(); // Reinicia completamente el chip ESP32 por software. Al pulsar el botón 'RST' de la placa (VERIFICACIÓN INSTANTÁNEA)
}
// ******************************************************************************************************