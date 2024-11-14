
// Definição dos pinos para o sensor ultrassônico
const int PinTrigger = 6; // Pino usado para disparar os pulsos do sensor
const int PinEcho = 7;    // Pino usado para ler a saída do sensor

// Definição das constantes para cálculo da distância
float duration, distance;

// Definição dos pinos para o driver de motor L298N
#define IN1 2   // Pino de controle IN1 para Motor A
#define IN2 3   // Pino de controle IN2 para Motor A
#define ENA 9   // Pino de habilitação ENA para Motor A (conectado a um pino PWM)
#define IN3 4   // Pino de controle IN3 para Motor B
#define IN4 5   // Pino de controle IN4 para Motor B
#define ENB 10  // Pino de habilitação ENA para Motor B (conectado a um pino PWM)

// Função para disparar o pulso ultrassônico
void DisparaPulsoUltrasonico() {
  digitalWrite(PinTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(PinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(PinTrigger, LOW);
}

// Funções para controlar os motores
void ajustarVelocidade(int vel) {
  analogWrite(ENA, vel); // Ajusta a velocidade do Motor A
  analogWrite(ENB, vel); // Ajusta a velocidade do Motor B
}

void moverFrente() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Velocidade();
}

void parar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void re() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Velocidade();
}

void virarDireita() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Velocidade();
}

void virarEsquerda() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Velocidade();
}

void virar360() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Velocidade();
}
void Velocidade(){
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  delay(30);
  analogWrite(ENA,200);
  analogWrite(ENB,200);
  delay(30);
  analogWrite(ENA,150);
  analogWrite(ENB,150);
  delay(30);
}
// Função de setup: inicializa os pinos
void setup() {
  // Inicializa o LED embutido
  pinMode(LED_BUILTIN, OUTPUT);

  // Inicializa os pinos do sensor ultrassônico
  pinMode(PinTrigger, OUTPUT);
  pinMode(PinEcho, INPUT);

  // Configura os pinos de controle como saída
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);  // ENA como saída PWM
  pinMode(ENB, OUTPUT);  // ENB como saída PWM

  // Inicializa o estado inicial dos motores e do sensor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}

// Função loop: executa continuamente
void loop() {
  // Dispara o pulso ultrassônico
  DisparaPulsoUltrasonico();

  duration = pulseIn(PinEcho, HIGH);
  distance = (duration*.0343)/2;

  // Verifica a distância e toma ações
  if (distance > 20) { // Se a distância for maior que 0.2 metros
    digitalWrite(LED_BUILTIN, HIGH); // Liga o LED

    moverFrente(); // Move o carrinho para frente

  } else { // Se a distância for menor ou igual a 0.2 metros
    digitalWrite(LED_BUILTIN, LOW); // Desliga o LED

    parar(); // Para o carrinho
    delay(400); // Aguarda meio segundo

    re(); // Move o carrinho para trás
    delay(500); // Move para trás por meio segundo
    
    parar(); // Para novamente
    delay(200); // Pequena pausa

    // Escolhe aleatoriamente virar à esquerda ou à direita
    int x = random(0, 3);
    if (x == 0) {
      virarEsquerda();
    } else if(x == 1) {
      virarDireita();
    } else {
      virar360();
    }
    delay(400); // Vira por meio segundo

    parar(); // Para após virar
    delay(200); // Pequena pausa
    
  }
  delay(30); // Pequena pausa antes da próxima leitura
}
