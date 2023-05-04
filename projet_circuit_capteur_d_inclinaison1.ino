// C++ code
//
int tiltPin = 8;
int ledPin = 13;
int tiltState;
void setup()
{
  pinMode(tiltPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  tiltState = digitalRead(tiltPin);
  if(tiltState){
    digitalWrite(ledPin, HIGH);
  } else{
    digitalWrite(ledPin, LOW);
  }
}