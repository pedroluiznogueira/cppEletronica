// Piscar LED - utilizando a função millis()
int ledPin = 13;
unsigned long timer = millis(); // variável onde armazenamos a contagem de tempo ("horário") atual
int ledEstado = LOW; // variável onde guardamos a informação se o LED azul está aceso ou apagado

void setup() {
  pinMode(ledPin, OUTPUT);
  }

void loop() {
  // Faz o LED Azul piscar em intervalos de 1 segundo
  if(millis() - timer > 1000){
    timer = millis();
    if (ledEstado == LOW){
      ledEstado = HIGH;
    }
    else{
      ledEstado = LOW;
    }
    digitalWrite(ledPin,ledEstado);
  }
}