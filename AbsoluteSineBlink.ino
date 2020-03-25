/*
 * Giuseppe Roberti
 */

#include "Arduino.h"
// #include "WiFiClient.h"
// #include "ESP8266WiFi.h"

// WiFiClient c;
float x = 0, y = 0;

#define ON LOW
#define OFF HIGH
#define THE_LED 5
#define TAU (2*PI)
#define VELOCITY 0.02
#define MULTIPLIER 100
#define DELTA 100

void blink(int, int, int);

void setup()
{
  // initialize output LEDs.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(THE_LED, OUTPUT);
  digitalWrite(LED_BUILTIN, OFF);
  digitalWrite(THE_LED, OFF);

  // initialize Serial
  Serial.begin(9600);

  // turn on builtin led for 100ms to signal setup is done
  blink(LED_BUILTIN, 100, 100);
}

void blink(int led, int ms, int ms_after) {
  digitalWrite(led, ON);
  delay(ms);
  digitalWrite(led, OFF);
  delay(ms_after);
}

void loop()
{
  y = DELTA + abs(sin(x) * (DELTA+MULTIPLIER));
  blink(THE_LED, DELTA, y - DELTA);

  x = x + VELOCITY;
  if (x >= TAU) x = 0;

  Serial.print("x:");
  Serial.print(x);
  Serial.print(",y:");
  Serial.print(y);
  Serial.println();
}
