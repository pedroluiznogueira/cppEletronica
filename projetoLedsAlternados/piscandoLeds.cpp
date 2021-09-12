// Exemplo de quando a função delay() não deve ser utilizada

int ledVermPin = 7; // pino do LED Vermelho
int ledAzulPin = 6; // pino do LED Azul
int botPin = 2; // pino do Botão

void setup() {
  pinMode(ledVermPin, OUTPUT);
  pinMode(ledAzulPin, OUTPUT);
  pinMode(botPin, INPUT);
}

void loop() {
  // Faz o LED Azul piscar em intervalos de 1 segundo
  digitalWrite(ledAzulPin, HIGH);
  delay(1000);
  digitalWrite(ledAzulPin, LOW);
  delay(1000);
  
  
  // Faz o LED Vermelho acender acender quando o botão é pressionado
  if(digitalRead(botPin) == HIGH){
	digitalWrite(ledVermPin, HIGH);
  }
  else{
    digitalWrite(ledVermPin, LOW);
  }
}