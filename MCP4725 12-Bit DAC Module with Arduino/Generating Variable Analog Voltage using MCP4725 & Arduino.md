## Generating a **variable analog voltage** using the MCP4725 and Arduino is a **common application** for this DAC module. By varying the digital input to the MCP4725, you can produce a range of **analog output voltages**.

#### In the following code, we will generate the 5 different analog voltages from Vout pin of MCP4725.

---
```
#include <Wire.h>
#include <Adafruit_MCP4725.h>
Adafruit_MCP4725 dac;
 
#define DAC_RESOLUTION    (9)   // Set this value to 9, 8, 7, 6 or 5 to adjust the resolution
 
 
void setup()
{
  Serial.begin(9600);
  delay(100);  // Small delay to ensure Serial is ready.
 
  Serial.println("MCP4725 Test");
 
  if (dac.begin(0x61))        //could be 0x60 or 0x62
  {
    Serial.println("MCP4725 Initialized Successfully.");
  }
  else
  {
    Serial.println("Failed to Initialize MCP4725.");
  }
}
 
 
void loop()
{
  dac.setVoltage((1 * 4095) / 5, false);    //Set voltage to 1V
  delay(2000);
  dac.setVoltage((2 * 4095) / 5, false);    //Set voltage to 2V
  delay(2000);
  dac.setVoltage((3 * 4095) / 5, false);    //Set voltage to 3V
  delay(2000);
  dac.setVoltage((4 * 4095) / 5, false);    //Set voltage to 4V
  delay(2000);
  dac.setVoltage(4095, false);              //Set voltage to 5V or (Vcc)
  delay(2000);
}

```
---

##### Upload the above code to the Arduino Nano Board and the setup is ready for testing. For testing the multimeter is required.
