int led1 = 3; 
int led2 = 5; 
int led3 = 6;
int led4 = 9;
int led5 = 10; 

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');

    if (command == "ON") {
      allOn();
      while (Serial.available() == 0);
      int choice = Serial.parseInt();

      if (choice == 1) {
        blinkLED();
      } 
      else if (choice == 2) {
        fadeLED();
      } 
      else if (choice == 3) {
        MidLED();
      } 
      else if (choice == 4) {
        runningLED();
      } 
      else if (choice == 5) {
        backingLED();
      }
    } 
    else if (command == "OFF") {
      allOff();
    }
  }
}

void blinkLED() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    delay(300);

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    delay(300);
  }
}

void fadeLED() {
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(led1, brightness);
    analogWrite(led2, brightness);
    analogWrite(led3, brightness);
    analogWrite(led4, brightness);
    analogWrite(led5, brightness);
    delay(5);
  }

  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(led1, brightness);
    analogWrite(led2, brightness);
    analogWrite(led3, brightness);
    analogWrite(led4, brightness);
    analogWrite(led5, brightness);
    delay(5);
  }
}

void MidLED() {
  for (int j = 0; j < 5; j++) {
    digitalWrite(led3, HIGH);
    delay(150);
    digitalWrite(led3, LOW);

    digitalWrite(led4, HIGH);
    delay(150);
    digitalWrite(led4, LOW);

    digitalWrite(led3, HIGH);
    delay(150);
    digitalWrite(led3, LOW);

    digitalWrite(led2, HIGH);
    delay(150);
    digitalWrite(led2, LOW);
  }
}

void runningLED() {
  for (int j = 0; j < 3; j++) {
    digitalWrite(led1, HIGH);
    delay(150);
    digitalWrite(led1, LOW);

    digitalWrite(led2, HIGH);
    delay(150);
    digitalWrite(led2, LOW);

    digitalWrite(led3, HIGH);
    delay(150);
    digitalWrite(led3, LOW);

    digitalWrite(led4, HIGH);
    delay(150);
    digitalWrite(led4, LOW);

    digitalWrite(led5, HIGH);
    delay(150);
    digitalWrite(led5, LOW);
  }
}

void backingLED() {
  for (int j = 0; j < 3; j++) {  
    digitalWrite(led1, HIGH);
    digitalWrite(led5, HIGH);
    delay(200);

    digitalWrite(led2, HIGH);
    digitalWrite(led4, HIGH);
    delay(200);

    digitalWrite(led3, HIGH);
    delay(300);

    digitalWrite(led3, LOW);
    delay(200);

    digitalWrite(led2, LOW);
    digitalWrite(led4, LOW);
    delay(200);

    digitalWrite(led1, LOW);
    digitalWrite(led5, LOW);
    delay(200);
  }
}

void allOn() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
}

void allOff() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
}
