const int in3 = 2;
const int in4 = 3;
const int en2 = 5;

void setup() {
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(en2, OUTPUT);

    analogWrite(en2, 255);
}

void loop() {
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(1000);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(1000);
}
