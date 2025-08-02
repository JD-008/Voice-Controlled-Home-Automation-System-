#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

// WiFi Credentials
const char* ssid = "wifi_name";
const char* password = "wifi_password";

// Adafruit IO Credentials
#define AIO_SERVER "io.adafruit.com"
#define AIO_USERNAME "JDR08 your adafruit io username"
#define AIO_KEY "aio key present in dashboard"

// MQTT Setup
WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, 1883, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Subscribe ac_control = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/ac_control");

// GPIO Pin for Signal Output
#define SIGNAL_PIN D1 // Use D1 (GPIO5) for output signal

// Counter for ON Commands
int commandCounter = 0;

void setup() {
    pinMode(SIGNAL_PIN, OUTPUT); // Set SIGNAL_PIN as output
    digitalWrite(SIGNAL_PIN, LOW); // Initialize as LOW (OFF)

    Serial.begin(115200);
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }

    Serial.println("\nConnected to WiFi!");
    mqtt.subscribe(&ac_control);
}

void loop() {
    MQTT_connect();

    Adafruit_MQTT_Subscribe *subscription;
    while ((subscription = mqtt.readSubscription(5000))) {
        if (subscription == &ac_control) {
            String command = (char *)ac_control.lastread;
            Serial.println("Command Received: " + command);

            if (command == "ON") {
                commandCounter++; // Increment command counter
                if (commandCounter % 2 == 0) {
                    Serial.println("Turning GPIO HIGH (ON) - Even count");
                    digitalWrite(SIGNAL_PIN, HIGH); // Turn GPIO ON for even count
                } else {
                    Serial.println("Turning GPIO LOW (OFF) - Odd count");
                    digitalWrite(SIGNAL_PIN, LOW); // Turn GPIO OFF for odd count
                }
            }
        }
    }
}

// Function to reconnect MQTT if disconnected
void MQTT_connect() {
    int8_t ret;
    if (mqtt.connected()) return;

    Serial.print("Connecting to MQTT...");
    while ((ret = mqtt.connect()) != 0) {
        Serial.println(mqtt.connectErrorString(ret));
        delay(5000);
    }
    Serial.println("Connected to MQTT!");
}