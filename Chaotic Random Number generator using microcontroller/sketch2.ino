void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("X_i\tX_i+1");

  float r = 3.9;
  float Xi = 0.456;

  for (int i = 1; i < 100; i++) {
    float Xi_next = Xi * r * (1 - Xi);

    Serial.print(Xi);
    Serial.print("\t");
    Serial.println(Xi_next);

    Xi = Xi_next;
    delay(50); // Adjust for Serial Plotter or data collection
  }
}

void loop() {
  while (true); // Prevent rerunning
}
