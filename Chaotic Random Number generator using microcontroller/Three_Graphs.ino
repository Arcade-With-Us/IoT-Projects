float r = 3.9;       // Constant r
float Xi = 0.456;    // Initial value
int iterations = 100;

void setup() {
  Serial.begin(9600);
  delay(1000);  // Give time for Serial to initialize

  for (int i = 0; i < iterations; i++) {
    float Xi_next = r * Xi * (1 - Xi);  // Logistic map calculation

    // Serial Plotter output — numeric with labels only
    Serial.print("X_i:");
    Serial.print(Xi);
    Serial.print("\t");

    Serial.print("X_i+1:");
    Serial.print(Xi_next);
    Serial.print("\t");

    Serial.print("R:");
    Serial.println(r);

    Xi = Xi_next;  // Update for next step
    delay(50);     // Smooth output for plotting
  }
}

void loop() {
  while (true); // Stop loop
}
