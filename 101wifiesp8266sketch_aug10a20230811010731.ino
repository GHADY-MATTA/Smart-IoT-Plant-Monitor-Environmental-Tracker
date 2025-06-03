#include <Adafruit_Sensor.h>
// #include <DHT11.h>

#define BLYNK_AUTH_TOKEN "thKuPKkJMXZ_MAY-jJn1uCzRIPrTgzss"  // Your Blynk Auth Token
#define BLYNK_TEMPLATE_ID "TMPL6y5nbyPUW"
#define BLYNK_TEMPLATE_NAME "dht11 temperature"

#include <DHT.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// DHT Sensor Setup
#define DHTPIN D2 // Data pin connected to D2
#define DHTTYPE DHT11 // Sensor type: DHT11

DHT dht(DHTPIN, DHTTYPE); // Create DHT instance

// Your network credentials
char ssid[] = "Matta";   // Replace with your Wi-Fi name
char pass[] = "M12345678";   // Replace with your Wi-Fi password

void setup() {
  Serial.begin(115200); // Initialize Serial Monitor
  Serial.println("DHT Sensor Test Starting...");
  dht.begin(); // Initialize DHT sensor

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);  // Connect to Blynk with the Auth Token
}

void loop() {
  Blynk.run();  // Run Blynk library

  // Read temperature and humidity
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if sensor reading failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    // Print values to Serial Monitor
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // Send the values to the Blynk app
    Blynk.virtualWrite(V0, temperature);  // Send temperature data to virtual pin V0
    Blynk.virtualWrite(V1, humidity);     // Send humidity data to virtual pin V1
  }

  delay(2000); // Wait 2 seconds before the next reading
}
