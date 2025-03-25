#define BLYNK_TEMPLATE_ID "TMPL3RgWyKK-b"
#define BLYNK_TEMPLATE_NAME "motor"
#define BLYNK_AUTH_TOKEN "nhJg0Ltjp1kDtBb-Kb1aQm0u-B-VsNh-"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Replace with your network credentials
char auth[] = "nhJg0Ltjp1kDtBb-Kb1aQm0u-B-VsNh-";
char ssid[] = "sachu";
char pass[] = "sachu1234";

#define LED_PIN D2 // Replace with the GPIO pin to which the LED is connected
#define LED_PIN2 D3
#define SPEED D4
void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN2,OUTPUT);
  pinMode(SPEED,OUTPUT);
  // Initially turn off the LED
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V0) // Virtual pin V1 for the LED control
{
  int ledState = param.asInt(); // Get value from the app (0 or 1)
  digitalWrite(LED_PIN,ledState);
}
BLYNK_WRITE(V1) // Virtual pin V1 for the LED control
{
  int ledState = param.asInt(); // Get value from the app (0 or 1)
  digitalWrite(LED_PIN2,ledState);
}
BLYNK_WRITE(V2) // Virtual pin V1 for the LED control
{
  int ledState = param.asInt(); // Get value from the app (0 or 1)
  analogWrite(SPEED,ledState);
}

void loop() {
  Blynk.run();
}
