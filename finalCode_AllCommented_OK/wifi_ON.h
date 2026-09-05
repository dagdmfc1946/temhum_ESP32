// *************************************************************************************************
// ------------------------------------- CONEXIÓN A RED WI-FI --------------------------------------
// *************************************************************************************************
/*
  Archivo: wifi_ON.h
  Versión: 1.0
  Función: Gestiona la conexión a la red Wi-Fi especificada. Implementa límite de tiempo para conexión, 
           notificaciones visuales en pantalla OLED, LED interno de la placa para visualizar un parpadeo
           ON/OFF con delay de 200 ms y finalmente control energético del Wi-Fi para el modo Deep Sleep.
  Autor: Diego Andrés García Díaz (@dagdmfc)
*/
// *************************************************************************************************

#include "WiFi.h" // Librería para manejo del Wi-Fi (Arduino)
#include "esp_wifi.h" // Librería específica para ESP32 --> COMPILA CORRECTAMENTE
#include "oled_ON.h" // Control de la pantalla OLED integrada en la placa

// *************************************************************************************************

// ----------------------------- Credenciales de la red Wi-Fi a usar -------------------------------
//const char* ssid = "CTE";       // ¡REEMPLAZAR con el nombre de la red WiFi a usar!
//const char* password = "3B62014554CC783D9DAEF0BD56966A34A2D32755635967F41CDC3EC1552D2B5D"; // ¡REEMPLAZAR con la contraseña de la red WiFi a usar!
// ----------------------------- Credenciales de la red Wi-Fi a usar -------------------------------
const char* ssid = "Ecosistema-FCV";     // ¡REEMPLAZAR con el nombre de la red WiFi a usar!
const char* password = "3mpLoyed_*FcV";  // ¡REEMPLAZAR con la contraseña de la red WiFi a usar!

// *************************************************************************************************

// ----------------------------- FUNCIÓN PRINCIPAL DE CONEXIÓN WI-FI -------------------------------
void connectWiFi() {
  Serial.println("\nConectando a la red WiFi..."); // Notificación por consola

  WiFi.mode(WIFI_STA); // Configura el ESP32 como estación (cliente)
  WiFi.begin(ssid, password); // Inicia la conexión a la red Wi-Fi

  unsigned long startAttemptTime = millis(); // Marca el tiempo de inicio
  const unsigned long timeout = 10000; // Límite de espera: 10 segundos

  mostrarConexionWiFiOLED(); // Muestra en pantalla OLED el mensaje de conexión

  while (WiFi.status() != WL_CONNECTED && (millis() - startAttemptTime) < timeout) {
    delay(200);              // Espera antes de volver a verificar
    Serial.print(".");        // Imprime punto para indicar progreso
    digitalWrite(LED, HIGH); // Parpadeo del LED como indicador visual
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
  }

  // ----- Reduce el consumo energético de WiFi mientras está conectado, sin cortar la conexión -----
  esp_wifi_set_ps(WIFI_PS_MIN_MODEM); // Ahorro de energía moderado manteniendo conexión Wi-Fi
  //esp_wifi_set_ps(WIFI_PS_MAX_MODEM); // Máximo ahorro (puede afectar latencia y rendimiento) ---> DESCOMENTAR Y PROBAR A VER SI REDUCE MÁS EL CONSUMO (Mirar si genera errores en la conexión)
  // ------------------------------------------------------------------------------------------------

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n📶 ¡Conexión WiFi exitosa!"); // Confirmación por consola
    Serial.print(">> Dirección MAC: \n");
    Serial.println(WiFi.macAddress()); // Imprime la MAC para identificación en servidor

    mostrarConectadoWiFi(); // Muestra mensaje de éxito en OLED
  } else {
    Serial.println("\n🚫 ERROR: No se pudo conectar a la red WiFi dentro del tiempo límite.");
    mostrarErrorWiFiOLED(); // Muestra error en pantalla OLED
  }
}
// *************************************************************************************************