// Libraries
#include <DHT.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define DHTPIN 19
#define DHTTYPE DHT11

// Inisialisasi DHT11 dan HTTP
DHT dht(DHTPIN, DHTTYPE);
HTTPClient http;

// Server (Ganti ke IP localhost nya)
const char* serverUrl = "http://192.168.0.1:5000/sensor/data";

// Wi-Fi (Ganti ssid dan password)
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Variabel lain
float temperature = 0;
float humidity = 0;
String jsonData = "";
int httpResponseCode = 0;

void setup() {
  Serial.begin(115200);
  setupWiFi();
  dht.begin();
}

void loop() {
  delay(3000); // delay 3 detik untuk memberikan waktu sebelum membaca data lagi
  getDHTData();
  sendSensorData();
}

void setupWiFi() {
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA); // Setting wifi chip sebagai station/client
  WiFi.begin(ssid, password); // Koneksi ke jaringan wifi

  // Menunggu ESP32 terkoneksi ke WiFI
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void getDHTData() {
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.println("Temperature: " + String(temperature) + "°C");
    Serial.println("Humidity: " + String(humidity) + "%");
  }
}

void sendSensorData() {
  jsonData = "{ \"temperature\": " + String(temperature) + ", \"humidity\": " + String(humidity) + " }";

  http.begin(serverUrl);
  http.addHeader("Content-Type", "application/json");

  httpResponseCode = http.POST(jsonData); // mengirim POST request aktual

  if (httpResponseCode > 0) {
    String response = http.getString(); // mendapatkan response to the request
    Serial.print("HTTP Response code: ");
    Serial.println(response); // mencetak request answer
    Serial.println();
  } else {
    Serial.print("Error in HTTP POST request: ");
    Serial.println(httpResponseCode);
    Serial.println();
  }
  http.end();
}

