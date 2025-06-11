float Xi = 0.456;   // Initial value
float r = 3.9;      // Logistic parameter
int iterations = 100;

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("X_i\tX_i+1\tR");  // Headers for Plotter or CSV
}

void loop() {
  for (int i = 0; i < iterations; i++) {
    float Xi_next = Xi * r * (1 - Xi);

    // Plot 1: X_i vs X_i+1
    Serial.print(Xi);
    Serial.print("\t");
    Serial.print(Xi_next);

    // Plot 2: X_i vs r (optional: use for bifurcation-style plotting)
    Serial.print("\t");
    Serial.println(r);

    Xi = Xi_next;
    delay(100); // slow down for Plotter
  }

  while (true); // Stop after one run
}

