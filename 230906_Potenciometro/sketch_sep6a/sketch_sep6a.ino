/*
Potenciometro:
  Componente que contém um resistor e um cursor que permite regular a resistência no pino de saída
Portas analógicas:
  O arduino tem 6 portas analógicas (A0 até A5) com resolução de 10 bits (1024 níveis) para leitura
*/

#define pinPot A0

void setup() {
  Serial.begin(57600);
}

void loop() {
  int val = analogRead(pinPot);
  Serial.println(val);
  delay(500);
}
