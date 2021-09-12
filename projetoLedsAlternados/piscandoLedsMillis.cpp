// Exemplo utilizando a função millis(), eliminando o travamento do Arduino

int ledVermPin = 7; // pino do LED Vermelho
int ledAzulPin = 6; // pino do LED Azul
int botPin = 2; // pino do Botão

unsigned long timer = millis(); // variável onde armazenamos a contagem de tempo ("horário") atual
int ledAzulEstado = LOW; // variável onde guardamos a informação se o LED azul está aceso ou apagado

void setup() {
  pinMode(ledVermPin, OUTPUT);
  pinMode(ledAzulPin, OUTPUT);
  pinMode(botPin, INPUT);
}

void loop() {
  // Faz o LED Azul piscar em intervalos distintos
  if(millis() - timer > 500 && ledAzulEstado == HIGH){
    timer = millis();
    ledAzulEstado = !ledAzulEstado;
  }
  if(millis() - timer > 3000 && ledAzulEstado == LOW){
    timer = millis();
    ledAzulEstado = !ledAzulEstado;
  }
  digitalWrite(ledAzulPin,ledAzulEstado);
  
  
  // Faz o LED Vermelho acender acender quando o botão é pressionado
  if(digitalRead(botPin) == HIGH){
    digitalWrite(ledVermPin, HIGH);
  }
  else{
    digitalWrite(ledVermPin, LOW);
  }
}