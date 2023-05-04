// C++ code
//
int sensorValue = 0;
int oldSensorValue = 0;
int redPin = 13;
int bluePin = 12;
int greenPin = 11;

void setup() {
  Serial.begin(9600); // initialize serial communication at 9600 bits per second
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.print("Nouvelle valeur recue - ");
  Serial.println(sensorValue);
}

void loop() {
  oldSensorValue = sensorValue;
  sensorValue = analogRead(A0); // read port A0
  if(oldSensorValue != sensorValue){
    Serial.print("Nouvelle valeur recue - ");
  	Serial.println(sensorValue); // print new sensor value
  }
  // change led color depending on sensor value
  if(sensorValue < 100){
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    digitalWrite(redPin, HIGH);
  } else if(sensorValue < 300){
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
    digitalWrite(redPin, HIGH);
  } else {
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
    digitalWrite(redPin, LOW);
  }
  delay(1);
}