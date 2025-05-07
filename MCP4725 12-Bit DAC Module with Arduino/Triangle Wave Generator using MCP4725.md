#### Generating a triangle wave using the MCP4725 and Arduino involves incrementing and decrementing the DAC output in a loop to create a linear rise and fall in voltage.

##### Here’s a complete code to generate a triangle wave.

---
```
#include <Wire.h>
#include <Adafruit_MCP4725.h>
 
Adafruit_MCP4725 dac;
 
const PROGMEM uint16_t DACLookup_Triangle_100[100] =
{
    0,   82,  164,  246,  328,  410,  491,  573, 
  655,  737,  819,  901,  983, 1065, 1147, 1229,
 1310, 1392, 1474, 1556, 1638, 1720, 1802, 1884,
 1966, 2048, 2129, 2211, 2293, 2375, 2457, 2539,
 2621, 2703, 2785, 2867, 2948, 3030, 3112, 3194,
 3276, 3358, 3440, 3522, 3604, 3686, 3767, 3849,
 3931, 4013, 4095, 4013, 3931, 3849, 3767, 3686,
 3604, 3522, 3440, 3358, 3276, 3194, 3112, 3030,
 2948, 2867, 2785, 2703, 2621, 2539, 2457, 2375,
 2293, 2211, 2129, 2048, 1966, 1884, 1802, 1720,
 1638, 1556, 1474, 1392, 1310, 1229, 1147, 1065,
  983,  901,  819,  737,  655,  573,  491,  410,
  328,  246,  164,   82 
};
 
void setup(void) {
  dac.begin(0x61);  // Initialize MCP4725 with address 0x60
}
 
void TRIANGLE(void) {
  uint16_t i;
  int freq = analogRead(A0) + 1;  // Read frequency from analog pin A0
  for (i = 0; i < 100; i++) {
    dac.setVoltage(pgm_read_word(&(DACLookup_Triangle_100[i])), false);
    delayMicroseconds(freq);
  }
}
 
void loop(void) {
  TRIANGLE();
}
```
---

#### To observe the Triangular Wave connect the Output & GND Pin to the Oscilloscope. You will get this type of output:

![Output](https://how2electronics.com/wp-content/uploads/2023/09/Triangular.jpg)
