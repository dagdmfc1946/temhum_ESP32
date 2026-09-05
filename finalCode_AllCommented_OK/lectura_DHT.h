// ***************************************************************************************************
// -------------------------------- SENSADO TEMPERATURA Y HUMEDAD ------------------------------------
// ***************************************************************************************************
// >>> Leer la temperatura o humedad tarda alrededor de 250 ms. Las lecturas del sensor pueden 
// tardar hasta 2 segundos (antigüedad) ya que es un sensor lento. Estos tiempos ya los configura 
// por defecto la librería 'DHT.h' <<<
// ***************************************************************************************************
/*
  Archivo: lectura_DHT.h
  Versión: 1.0
  Función: Define y ejecuta la función de lectura de temperatura y humedad del sensor DHT22. 
           Implementa verificación de error y muestra mensajes en OLED si falla la lectura, además
           de visualizar en el LED interno de la placa un parpadeo ON/OFF con delay de 400 ms que
           indica un error en la lectura del sensor.
  Autor: Diego Andrés García Díaz (@dagdmfc)
*/
// **************************************************************************************************

#include "parameters.h" // Contiene configuraciones de pines (#define) y parámetros del sistema
#include "DHT.h" // Librería oficial para comunicación con sensores DHT11/DHT22
#include "oled_ON.h" // Control de la pantalla OLED integrada en la placa

DHT dht(DHTPIN, DHTTYPE); // Se inicializa el sensor creando un objeto con el pin de datos y el tipo de sensor

// **************************************************************************************************

// --------------------------- FUNCIÓN PRINCIPAL PARA LECTURA DE SENSOR -----------------------------
void dataRead_DHT(float* temp, float* hum) { // FUNCIÓN PRINCIPAL // 'float* __' --> Accede o modifica el valor almacenado en una dirección de memoria (puntero).
  Serial.println("Iniciando proceso de lectura..."); // Mensaje de diagnóstico en consola

  dht.begin(); // Inicializa la comunicación con el sensor DHT22

  float t = dht.readTemperature(); // Lee temperatura en grados Celsius
  float h = dht.readHumidity(); // Lee humedad relativa en porcentaje

  // Verifica si la lectura es válida; si no, reporta error y muestra en pantalla
  if (isnan(t) || isnan(h)) {
    Serial.println("❌ ¡¡ERROR en la lectura del sensor!!"); // Notifica error en consola
    mostrarErrorSensorOLED(); // Muestra mensaje de error en pantalla OLED
    *temp = 0; // Devuelve 0 como valor de temperatura inválida (ERROR lectura sensor)
    *hum = 0; // Devuelve 0 como valor de humedad inválida (ERROR lectura sensor)
  } else {
    *temp = t; // Asigna la temperatura leída a la variable original
    *hum = h; // Asigna la humedad leída a la variable original
    Serial.printf("Temperatura: %.1f °C\tHumedad: %.1f %%\t   ", t, h); // Imprime resultados en consola
  }
  // NOTA: No se incluye delay() aquí para no afectar el tiempo del ciclo de sueño
}
// *************************************************************************************************