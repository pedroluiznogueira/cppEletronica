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

void EstagiosCarros() {
  // Aqui, precisamos monitorar o botão de pedestres em paralelo
  // com o Arduino, então devemos utilizar a função millis

  // ============================================================
  // Condicional que será executada quando o timer=2s e estágio=1
  if((millis() - timer > 2000) && (estagio == 1)) {
    // Estágio 1: semáforo via A (vermelho)
    Serial.println("Estagio 1: semaforo via A (vermelho)");
    // Semáforo da via A
    digitalWrite(carroRA, HIGH);
    digitalWrite(carroYA, LOW);
    digitalWrite(carroGA, LOW);
    // Se o botão de pedestres foi pressionado, chama a função "EstagiosPed()",
    // caso contrário, continua o ciclo dos carros
    if(travessia){
      Serial.println("\n Entrando na funcao EstagiosPed()...");
      EstagiosPed();
    }
    // Número do próximo estágio
    estagio = 2;
    // Zera o timer
    timer = millis();
  }
  
  // ============================================================
  // Condicional que será executada quando o timer=3s e estágio=2
  if((millis() - timer > 3000) && (estagio == 2)) {
    // Estágio 2: semáforo via A (verde)
    Serial.println("Estagio 2: semaforo via A (verde)");
    // Semáforo da via A
    digitalWrite(carroRA, LOW);
    digitalWrite(carroYA, LOW);
    digitalWrite(carroGA, HIGH);
    // Número do próximo estágio
    estagio = 3;
    // Zera o timer
    timer = millis();
  }
  
  // ============================================================================
  // Condicional que será executada quando o timer=1s, estágio=3 e travessia=true
  if((estagio == 3) && (travessia == true)) {
    // Estágio 3: semáforo via A (amarelo)
    Serial.println("Estagio 3: semaforo via A (amarelo)");
    // Semáforo da via A
    digitalWrite(carroRA, LOW);
    digitalWrite(carroYA, HIGH);
    digitalWrite(carroGA, LOW);
    // Número do próximo estágio
    estagio = 1;
    // Zera o timer
    timer = millis();
  }

  // =========================================
  // Retorna para o loop principal do programa
}

void EstagiosPed() {
  // Aqui, não faremos outra tarefa em paralelo com o Arduino,
  // então podemos utilizar a função delay

  // ======================================================================
  // Estágio 1: Apaga o vermelho dos pedestres, acende o verde e aguarda 5s
  Serial.println("Estagio 1: Apaga o vermelho dos pedestres, acende o verde e aguarda 5s");
  digitalWrite(pedR, LOW);
  digitalWrite(pedG, HIGH);
  delay(5000);

  // =====================================================================
  // Estágio 2: Pisca o verde dos pedestres 5 vezes, em intervalos de 0,5s
  Serial.println("Estagio 2: Pisca o verde dos pedestres 5 vezes, em intervalos de 0,5s");
  for (int x=0; x<5; x++) {
    digitalWrite(pedG, HIGH);
    delay(500);
    digitalWrite(pedG, LOW);
    delay(500);
  }

  // =======================================================
  // Estágio 3: Acende o vermelho dos pedestres,
  //            atualiza a variável travessia para "false" e
  //            retorna para a função "EstagiosCarros()"
  Serial.println("Estagio 3: Acende o vermelho dos pedestres, atualiza a variavel");
  Serial.println("          travessia para false e retorna para a funcao EstagiosCarros() \n");
  digitalWrite(pedR, HIGH);
  travessia = false;
}