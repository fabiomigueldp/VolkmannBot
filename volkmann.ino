// Definição dos pinos para o sensor ultrassônico
const int PinTrigger = 6; // Pino usado para disparar os pulsos do sensor
const int PinEcho = 7;    // Pino usado para ler a saída do sensor

// Definição das constantes para cálculo da distância
const float VelocidadeSom_m_por_us = 0.000340; // Velocidade do som em metros por microsegundo

// Definição dos pinos para o driver de motor L298N
#define IN1 4   // Pino de controle IN1 para Motor A
#define IN2 5   // Pino de controle IN2 para Motor A
#define IN3 3   // Pino de controle IN3 para Motor B
#define IN4 2   // Pino de controle IN4 para Motor B

#define ENA 9   // Pino ENA para controle de velocidade do Motor A (PWM)
#define ENB 10  // Pino ENB para controle de velocidade do Motor B (PWM)

const int velocidadeNormal = 200; // Velocidade padrão (0 a 255)
const int velocidadeReverso = 150; // Velocidade para reversão

// Variáveis para armazenar tempo de eco e distância calculada
unsigned long TempoEcho = 0;
float distancia = 0.0;

// Função para disparar o pulso ultrassônico
void DisparaPulsoUltrasonico() {
  digitalWrite(PinTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(PinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(PinTrigger, LOW);
}

// Função para calcular a distância com base no tempo do eco
float CalcularDistancia(unsigned long tempo_us) {
  return (tempo_us * VelocidadeSom_m_por_us) / 2;
}

// Funções para controlar os motores
void moverFrente() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, velocidadeNormal);
  analogWrite(ENB, velocidadeNormal);
}

void parar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void re() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, velocidadeReverso);
  analogWrite(ENB, velocidadeReverso);
}

void virarDireita() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, velocidadeNormal);
  analogWrite(ENB, velocidadeNormal);
}

void virarEsquerda() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, velocidadeNormal);
  analogWrite(ENB, velocidadeNormal);
}

// Função de setup: inicializa os pinos
void setup() {
  // Inicializa o LED embutido
  pinMode(LED_BUILTIN, OUTPUT);

  // Inicializa os pinos do driver de motor como saídas
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Inicializa os pinos do sensor ultrassônico
  pinMode(PinTrigger, OUTPUT);
  pinMode(PinEcho, INPUT);

  // Inicializa o estado inicial dos motores e do sensor
  parar();
  digitalWrite(PinTrigger, LOW);

  // Inicia a comunicação serial para depuração (opcional)
  Serial.begin(9600);
}

// Função loop: executa continuamente
void loop() {
  // Dispara o pulso ultrassônico
  DisparaPulsoUltrasonico();

  // Lê o tempo do pulso de eco
  TempoEcho = pulseIn(PinEcho, HIGH, 30000); // Timeout de 30ms para evitar bloqueios

  // Calcula a distância
  distancia = CalcularDistancia(TempoEcho);

  // Exibe a distância no monitor serial (opcional)
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" metros");

  // Verifica a distância e toma ações
  if (distancia > 0.2) { // Se a distância for maior que 0.2 metros
    digitalWrite(LED_BUILTIN, HIGH); // Liga o LED

    moverFrente(); // Move o carrinho para frente
  } else { // Se a distância for menor ou igual a 0.2 metros
    digitalWrite(LED_BUILTIN, LOW); // Desliga o LED

    parar(); // Para o carrinho
    delay(500); // Aguarda meio segundo

    re(); // Move o carrinho para trás
    delay(500); // Move para trás por meio segundo

    parar(); // Para novamente
    delay(200); // Pequena pausa

    // Escolhe aleatoriamente virar à esquerda ou à direita
    if (random(0, 2) == 0) {
      virarEsquerda();
    } else {
      virarDireita();
    }
    delay(500); // Vira por meio segundo

    parar(); // Para após virar
    delay(200); // Pequena pausa
  }

  delay(100); // Pequena pausa antes da próxima leitura
}
