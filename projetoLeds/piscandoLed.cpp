
// LED controlado por botão
int ledPin = 7; // pino do LED
int botPin = 2; // pino do Botão

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(botPin, INPUT);
}

void loop() {
  if(digitalRead(botPin) == HIGH){
	digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
}