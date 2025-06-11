void setup() {
  Serial.begin(9600);
  delay(1000);

  float r = 3.9;
  float Xi = 0.456;
  int iterations = 100;

  for (int i = 0; i < iterations; i++) {
    float Xi_next = r * Xi * (1 - Xi);

    // Serial Plotter Output — labeled values only
    Serial.print("Xi:");
    Serial.print(Xi, 6);      // X_i
    Serial.print("\t");
    Serial.print("R:");
    Serial.println(r, 6);     // constant r line

    Xi = Xi_next;  // Update for next step
    delay(50);     // Delay for stable plotting
  }
}

void loop() {
  while (true); // Stop loop after one run
}
