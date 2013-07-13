float incoming = 0; // for incoming serial data
int motor = 11;
int led = 13;
float normval = 0;

void setup() {
  Serial.begin(57600);
  pinMode(motor, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    incoming = Serial.read();
    Serial.println(incoming);
    analogWrite(motor, incoming);
    normval = pow((float)incoming * 0.8 + 0.2, 1.75);
    analogWrite(led, int(normval));
  }
}


