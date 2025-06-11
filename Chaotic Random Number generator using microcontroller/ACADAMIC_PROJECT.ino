#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <math.h>

Adafruit_MCP4725 dac;

const int amplitude = 2047; // Half of 4095
const int offset = 2047;
const float frequency = 2.0;  // Lower it for visible plotting
const int sampleRate = 100;   // Lower sample rate for Serial Plotter

void setup() {
  dac.begin(0x60);       // Start DAC
  Serial.begin(9600);    // Start Serial for plotter
}

void loop() {
  for (int i = 0; i < sampleRate / frequency; i++) {
    float angle = 2 * PI * frequency * i / sampleRate;
    int value = offset + (amplitude * sin(angle));
    dac.setVoltage(value, false);       // Send to DAC
    Serial.println(value);              // Send to Plotter
    delay(10);  // Adjust for smooth plotting
  }
}
