// Semáforo simples com pedestres utilizando millis() e delay()

int carroRA = 7;               // estabelece o semáforo para carros da via A
int carroYA = 6;
int carroGA = 5;
int pedR = 8;                  // estabelece o semáforo para pedestres
int pedG = 9;
int botao = 12;                // pino do botão
bool travessia = false;        // variável que armazena se o botão de pedestres foi acionado
unsigned long timer;           // tempo desde a conclusão do último ciclo para pedestres
int estagio = 1;               // variável que armazena o estágio dos semáforos de carro

void setup() {
  pinMode(carroRA, OUTPUT);
  pinMode(carroYA, OUTPUT);
  pinMode(carroGA, OUTPUT);
  pinMode(pedR, OUTPUT);
  pinMode(pedG, OUTPUT);
  pinMode(botao, INPUT);
  // acende a luz amarela da via A e vermelho dos pedestres
  digitalWrite(carroYA, HIGH);
  digitalWrite(pedR, HIGH);
  // Comunicação serial
  Serial.begin(9600);
  Serial.println("Iniciando...");
}

void loop() {
  int botPed = digitalRead(botao);
  // Verifica se o botão foi pressionado
  if (botPed == HIGH) {
    // Um pedestre deseja atravessar a rua
    Serial.println("Um pedestre deseja atravessar a rua");
    travessia = true;
  }
  EstagiosCarros();
}