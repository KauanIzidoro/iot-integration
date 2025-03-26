#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

String serverUrl1 = "http://localhost:8080/api/v1/kauanlucasesp32/telemetry"
String serverUrl2 = "http://thingsboard.cloud/api/v1/1yplgtj1yxs78et8hpf0/telemetry"
HTTPClient http;

const char* ssid = "WIFI_ADM_CFP402";
const char* password = "ac4ce0ss2";

void setup() {
    Serial.begin(115200);

    WiFi.begin(ssid, password);
    Serial.print("Conectando");

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nConectado ao WiFi!");
    Serial.print("Endereço IP: ");
    Serial.println(WiFi.localIP()); 
}

void loop() {
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/json");
    StaticJsonDocument<200> jsonPayload;
    jsonPayload["value1"] = 20.0;
    jsonPayload["value2"] = 30.0;
    jsonPayload["value3"] = 40.0;

    String jsonString;
    serializeJson(doc, jsonString);

    int httpResponseCode = http.POST(jsonString);

    if (httpResponseCode > 0) {
        Serial.println(http.getString());
    } else {
        Serial.println("Erro na requisição");
    }

    http.end();
}