### 🎛️ DAC Waveform & Chaotic Logistic Map Generator using Arduino Due + MCP4725 I2C DAC

This project demonstrates:
- ✅ Digital-to-Analog conversion using **MCP4725 I²C DAC** and **Arduino Due**
- 🌊 Generation of **sine wave signals**
- 📈 Visualization of a **1D chaotic logistic map**
- 🔬 Serial data plotting using **Arduino Serial Plotter**

---

## 📦 Components Required

| 🔢 No. | 🧩 Component              | 💡 Quantity |
|-------|---------------------------|-------------|
| 1     | Arduino Due               | 1           |
| 2     | MCP4725 DAC Module        | 1           |
| 3     | Jumper Wires              | ~5          |
| 4     | Breadboard                | 1           |
| 5     | Oscilloscope (Optional)   | 1           |

---

## 🔌 Circuit Diagram

🖼️ ![Circuit Diagram](./circuit.png)  
📌 **Connections:**

| MCP4725 Pin | Connects To          |
|-------------|----------------------|
| VCC         | 3.3V of Arduino Due  |
| GND         | GND                  |
| SDA         | SDA1 (Pin 20 on Due) |
| SCL         | SCL1 (Pin 21 on Due) |
| VOUT        | ➡ Oscilloscope or multimeter |

> ℹ️ Use **SDA1/SCL1 (Pins 20, 21)** instead of default SDA/SCL for **I²C on Arduino Due**.

---

## 🔁 Part 1: Generate Sine Wave using MCP4725

### ⚙️ Arduino Code

```cpp
#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;

void setup() {
  dac.begin(0x60); // Default I2C address
}

void loop() {
  for (int i = 0; i < 360; i++) {
    float rad = i * 3.1416 / 180;
    float sineValue = (sin(rad) + 1.0) / 2.0; // Normalize to 0–1
    int dacValue = (int)(sineValue * 4095);  // 12-bit value
    dac.setVoltage(dacValue, false);
    delayMicroseconds(500);  // Control waveform frequency
  }
}
```
---
## 🌪️ Part 2: Chaotic 1D Logistic Map (Xᵢ₊₁ = r · Xᵢ · (1 − Xᵢ))

📈 **`Output in Serial Plotter`**

`Visualizes:`

* **`Xᵢ`**: current value (chaotic)

* **`Xᵢ₊₁`**: next value

* **`r`**: constant control parameter
