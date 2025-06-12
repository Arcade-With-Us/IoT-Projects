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

🖼️ ![Circuit Diagram](./ChatGPT Image Jun 10, 2025, 09_43_11 PM.png)  
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

## ⚙️ Arduino Code
```
float r = 3.9;       // Constant control parameter
float Xi = 0.456;    // Initial seed
int iterations = 100;

void setup() {
  Serial.begin(9600);
  delay(1000);

  for (int i = 0; i < iterations; i++) {
    float Xi_next = r * Xi * (1 - Xi);

    // For Serial Plotter
    Serial.print("X_i:");
    Serial.print(Xi, 6);
    Serial.print("\t");

    Serial.print("X_i+1:");
    Serial.print(Xi_next, 6);
    Serial.print("\t");

    Serial.print("R:");
    Serial.println(r, 6);

    Xi = Xi_next;
    delay(50);
  }
}

void loop() {
  while (true); // Stop execution
}
```
## 📊 Example Serial Monitor Output
```
i	X_i		X_i+1		R
0	0.456000	0.969062	3.90
1	0.969062	0.116778	3.90
2	0.116778	0.403239	3.90
```
## 📤 Export & Plot Xᵢ vs Xᵢ₊₁ in Python
```
import matplotlib.pyplot as plt
import numpy as np

# --------------------------
# Part 1: Time-Series Plot (Fixed r)
# --------------------------
def logistic_map_series(r=3.9, x0=0.456, n=100):
    x = np.zeros(n)
    x[0] = x0
    for i in range(1, n):
        x[i] = r * x[i-1] * (1 - x[i-1])
    return x

# Plot Xᵢ over time for a fixed r
r_fixed = 3.9
x0 = 0.456
iterations = 100
x_values = logistic_map_series(r_fixed, x0, iterations)

plt.figure(figsize=(8, 4))
plt.plot(range(iterations), x_values, marker='o', linestyle='-')
plt.title(f"Logistic Map Time Series (r = {r_fixed})")
plt.xlabel("Iteration (i)")
plt.ylabel("Xᵢ")
plt.grid(True)
plt.tight_layout()
plt.show()

# --------------------------
# Part 2: Bifurcation Diagram (r vs X)
# --------------------------
def bifurcation_diagram(r_min=2.5, r_max=4.0, steps=10000, discard=100, keep=100):
    r_values = np.linspace(r_min, r_max, steps)
    x0 = 0.5
    xs = []
    rs = []

    for r in r_values:
        x = x0
        # Remove transient
        for _ in range(discard):
            x = r * x * (1 - x)
        # Collect stable points
        for _ in range(keep):
            x = r * x * (1 - x)
            rs.append(r)
            xs.append(x)
    return rs, xs

# Plot bifurcation diagram
r_vals, x_vals = bifurcation_diagram()

plt.figure(figsize=(10, 6))
plt.plot(r_vals, x_vals, ',k', alpha=0.25)
plt.title("Bifurcation Diagram of Logistic Map")
plt.xlabel("r")
plt.ylabel("X")
plt.grid(True)
plt.tight_layout()
plt.show()
```
---

## 📌 Notes
* MCP4725 provides **12-bit precision DAC output** (0–4095)

* Logistic Map is sensitive to initial **X₀** and **r** values

* Arduino Serial Plotter only supports time-series, so for scatter plots (**Xᵢ** vs **Xᵢ₊₁**), use Python/Excel

## 🧠 What You Learn

| ✅ Skill | 💬 Application          |
|-------------|----------------------|
| DAC interfacing | Analog signal generation from digital values |
| I2C communication| Talking to MCP4725 with minimal wires |
| Non-linear dynamics| Visualize chaos using the Logistic Map |
| Serial Plotting| Real-time value tracking for debugging or display |
| Cross-platform analysis| Use Arduino + Python for hybrid data processing |
