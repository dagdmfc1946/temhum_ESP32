// *******************************************************************************************
// ---------------------------------- ARCHIVO PRINCIPAL --------------------------------------
// >>> IMPORTANTE: Para que funcione correctamente el modo Deep Sleep del ESP32, todo el código 
// debe ejecutarse dentro de 'void setup()' <<<
// *******************************************************************************************
/*
  Archivo: final_Code.ino
  Versión: 1.0
  Función: Programa principal que gestiona el flujo completo del sistema IoT de sensado con DHT22. 
           Realiza lectura de sensores, muestra datos en pantalla OLED, evalúa nivel de batería 
           (lectura tensión en mV), conecta a Wi-Fi y envía los datos por POST a un servidor. Al 
           finalizar entra en modo Deep Sleep (Sueño Profundo).
           Se usa la placa de desarrollo 'Heltec WiFi LoRa 32 V3' que integra el chip 'ESP32-S3'.
  Autor: Diego Andrés García Díaz (@dagdmfc)
*/
// *******************************************************************************************

#include "includess.h" // Archivo que agrupa e incluye todas las librerías necesarias

// *******************************************************************************************

// ----------------------------- FUNCIÓN PRINCIPAL A EJECUTAR --------------------------------
void setup() {
  Serial.begin(115200); // Inicializa la comunicación serial con la PC a 115200 baudios
  
  // PASO 1: Inicializa el LED interno para usarlo como indicador visual de estado
  initLED(); // Configura el pin del LED como salida y lo apaga
  
  Serial.println("\n>>> ¡ESP32 Despierta! - LECTURA: Sensor DHT22 <<<"); // Mensaje en consola indicando inicio del ciclo
  
  // PASO 2: Lectura de temperatura y humedad desde el sensor DHT22
  float TEM = 0.0; // Variable para almacenar temperatura en °C
  float HUM = 0.0; // Variable para almacenar humedad relativa en %
  dataRead_DHT(&TEM, &HUM); // Ejecuta lectura del sensor y guarda resultados en TEM y HUM

  // PASO 3: Muestra los datos leídos en la pantalla OLED
  mostrarDatosOLED(TEM, HUM); // Imprime temperatura y humedad en pantalla OLED

  // PASO 4: Lectura del voltaje de la batería (mV)
  int V_batt = read_VBatt(); // Ejecuta lectura y devuelve tensión en mV
  if (V_batt < 3300) { // Si la tensión es menor a XXXX mV, se considera batería baja
    mostrarAdvertenciaBateria(); // Muestra alerta visual en pantalla OLED y parpadea LED
  }

  // PASO 5: Conexión a red Wi-Fi
  connectWiFi(); // Intenta conectarse al Wi-Fi previamente definido desde el archivo 'wifi_ON.h'
                 // const char *ssid = "NOMBRE-RED"; --> Modificar "NOMBRE-RED" por el nombre de la red Wi-Fi a usar
                 // const char *password = "CONTRASEÑA-RED"; --> Modificar "CONTRASEÑA-RED" por la contraseña de la red Wi-Fi a usar
                 // Muestra estado en pantalla OLED y LED

  // PASO 6: Envío de datos al servidor por el método HTTP POST
  enviarDatosPorPOST(TEM, HUM, V_batt); // Envía datos en formato JSON y verifica respuesta del servidor

  // PASO 7: Entrar en modo Deep Sleep para ahorrar energía
  mostrarDeepSleepOLED(); // Muestra mensaje de entrada a Deep Sleep
  apagarOLED(); // Apaga pantalla OLED físicamente para reducir consumo
  sleep(); // Inicia modo Deep Sleep. El programa se reiniciará desde setup() al despertar

  // PASO 8: Reinicio automático tras Deep Sleep controlado por "TIME_TO_SLEEP" en 'parameters.h'
}

// *******************************************************************************************
// --------------------------------- FUNCIÓN QUE NO SE USA -----------------------------------
void loop() {
/* 
  ¡¡NO VA NADA EN ESTA PARTE, ESTO CON EL FIN DE QUE LA ESP32 ENTRE EN MODO
  DE SUEÑO PROFUNDO CORRECTAMENTE!! 
*/
}
// *******************************************************************************************