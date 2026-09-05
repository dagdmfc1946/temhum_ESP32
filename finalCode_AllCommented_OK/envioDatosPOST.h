// *************************************************************************************************
// ---------------------------------- ENVIO LOS DATOS AL SERVIDOR ----------------------------------
// *************************************************************************************************
/* 
  Archivo: envioDatosPOST.h
  Versión: 1.0
  Función: Enviar datosobtenido en formato JSON a un servidor mediante el protocolo HTTP POST.
            - MAC, address (ID) del dispositivo
            - Temperatura (entero multiplicado por 10 para preservar un decimal)
            - Humedad (entero)
            - Datos de batería (voltaje en mV)
           Se observa en la pantalla OLED mensajes de ERROR o confirmación, también en el LED interno de
           la placa un parpadeo ON/OFF con delay de 100 ms si hay un ERROR en el POST, si el POST es 
           correcto se mantiene encendido el LED durante 2 segundos.
  Autor: Diego Andrés García Díaz (@dagdmfc)
*/
// *************************************************************************************************

#include "HTTPClient.h" // Librería para manejar solicitudes HTTP (GET, POST, PUT, etc.).

// *************************************************************************************************

// ---------------------------- Configuración del endpoint del servidor ----------------------------
const String serverURL = "http://172.30.19.123:8000/moe/telemetry/registro_temp_hum"; // URL servidor

// *************************************************************************************************

// ------------------------------- FUNCIÓN PRINCIPAL ENVIO DE DATOS --------------------------------
void enviarDatosPorPOST(float temp, float hum, int v_batt) { // FUNCIÓN PRINCIPAL // Se hace una copia 'local' de los valores medidos para poder manipularlos
  if (WiFi.status() != WL_CONNECTED) { // Verifica si la conexión Wi-Fi está activa
    Serial.println("\n🔁 Reintentando conexión a la red WiFi..."); // Notificación por consola
    connectWiFi(); // Reintenta la conexión si no está conectado
  }

  HTTPClient http;                    // Crea un cliente HTTP
  String mac = WiFi.macAddress();    // Obtiene la dirección MAC como identificador del dispositivo

  // ----------------- fixed-point representation (si el servidor no usa 'float') ------------------
  int temp_int = (int)(temp * 10);   // Convierte temperatura a entero (mantiene un decimal)
  int hum_int  = (int)hum;           // Convierte humedad a entero (sin decimales)

  // -------------------- Se forma el objeto JSON para poder envíar los datos ----------------------
  String jsonPayload = "{";
  jsonPayload += "\"mac\":\"" + mac + "\","; // Dirección MAC
  jsonPayload += "\"values\":{"; // Datos del sensor
  jsonPayload += "\"temperature\":" + String(temp_int) + ",";  // Temperatura como entero
  jsonPayload += "\"humidity\":" + String(hum_int); // Humedad como entero
  jsonPayload += "},";
  jsonPayload += "\"battery\":{"; // Datos de la batería 
  jsonPayload += "\"voltage\":" + String(v_batt) + ",";  // Voltaje (mV) como entero
  jsonPayload += "\"level\":0"; // Nivel (porcentaje) de la batería, ¡NO IMPLEMENTADO!
  jsonPayload += "}";
  jsonPayload += "}";

  Serial.println("\n📤 Envio de los datos en formato JSON:"); // Notificación por consola
  Serial.println(jsonPayload); // Imprime el JSON para verificación en consola

  http.begin(serverURL); // Inicia la conexión HTTP con el servidor
  http.addHeader("Content-Type", "application/json"); // Define el tipo de contenido como JSON
  
  int httpResponseCode = http.POST(jsonPayload); // Enviar la solicitud POST
  
  // -------------------------------- Verificación de la solicitud ---------------------------------
  if (httpResponseCode > 0) {
    // REVISAR LA PARTE DE ERROR EN LECTURA PARA QUE CUANDO LA LECTURA SEA DE 0, MUESTRE UN ERROR EN POST, MÁS NO UN ENVIO EXITOSO.
    Serial.printf(">> ✅ POST exitoso.\t Código HTTP: %d\n", httpResponseCode); // Notificación por consola
    Serial.println(">> Respuesta del servidor:"); // Notificación por consola
    Serial.println(http.getString()); // Muestra la respuesta del servidor en consola
    
    mostrarSendDataOLED(); // Muestra en pantalla OLED el mensaje de confirmación
  } else {
    Serial.printf("\n>> ❌ ERROR en POST: %s\n", http.errorToString(httpResponseCode).c_str()); // Notificación por consola
    
    mostrarErrorPostOLED(); // Muestra en pantalla OLED el mensaje de ERROR
  }
  
  http.end(); // Finaliza la conexión HTTP
}
// *************************************************************************************************