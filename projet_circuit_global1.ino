// C++ code
//
int tiltState; // for reading the tilt Sensor status
int tiltPin = 3;
int ledPin = 9;
int redPin = 7;
int bluePin = 6;
int greenPin = 5;
int sensorValue = 0;
int oldSensorValue = 0;

void setup(){
  pinMode(tiltPin, INPUT); // digital pin 7 is the input
  Serial.begin(9600); // initialize serial communication at 9600 bits per second
  pinMode(ledPin, OUTPUT); // digital pin 9 is the output
  pinMode(2, OUTPUT); // digital pin 2 as an output
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  digitalWrite(2, HIGH); // digital pin 2 always on
  Serial.print("Nouvelle valeur recue - ");
  Serial.println(sensorValue);
}
 
void loop(){
  // for tilt mesurement
  tiltState = digitalRead(tiltPin); // read the current value of the sensor
  if (tiltState){
    digitalWrite(ledPin, LOW); // if not tilted, turn off LED
  } else{
    digitalWrite(ledPin, HIGH); // if titlted, turn on LED
  }
  // for weight mesurement
  oldSensorValue = sensorValue; // store old sensor value
  sensorValue = analogRead(A0); // read port A0
  if(oldSensorValue != sensorValue){
    Serial.print("Nouvelle valeur recue - ");
  	Serial.println(sensorValue); // print new sensor value
  }
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
