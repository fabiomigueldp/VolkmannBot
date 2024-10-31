
/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/
/*
ALIMENTAÇÂO
  FGHIJ 17 -
  FGHIJ 16 +

  ABCDE 7  5V+
  ABCDE 10 -

MOTOR
  conectado no VERMELHO
  sensor frente
  esquerdac ->  5 4
  direita   ->  3 2 


SENSOR
  localBRANCO 7;8;9;10

AZUL (entrada usb topo)

  DIREITA:
    caboBRANCO local11 -> localBRANCO E9
    caboAZUL   local12   -> localBRANCO E8
    =========================================
    caboPRETO     local~5   -> localVERMELHO IN4
    caboMARROM    local 4   -> localVERMELHO IN3
    caboVERMELHO  local~3   -> localVERMELHO IN2
    caboLARANJA   local 2   -> localVERMELHO IN!
  
  ESQUERDA:
    caboPRETO local vin  -> localBRANCO J16 (area do sensor ent deve da pra usar o motor neste momento)



BRANCO Y {a, b, ... , z} X{ 1, 2, ...} primeiro quadrante a1 inferior esquerda

VERMELHO Driver Motor H L298n
IN1 = 2
IN2 = 3
IN3 = 4
IN4 = 5
*/
int PinTrigger = 6; // Pino usado para disparar os pulsos do sensor
int PinEcho = 7; // pino usado para ler a saida do sensor
float TempoEcho = 0;
const float VelocidadeSom_mpors = 340; // em metros por segundo
const float VelocidadeSom_mporus = 0.000340; // em metros por microsegundo


#define IN1 4
#define IN2 5
#define IN3 3
#define IN4 2

#define velmotor 3
#define mla1 IN1
#define mlb1 IN3
#define mla2 IN2
#define mlb2 IN4
#define tmp 3000
int vel = 0;
float dist = 0;

void  DisparaPulsoUltrasonico() {
  digitalWrite(PinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(PinTrigger, LOW);

}

float CalcularDistancia(float tempo_us) {
  return (tempo_us*VelocidadeSom_mporus)/2;
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  //================================================dist
  pinMode(velmotor,OUTPUT);
  pinMode(mla1,OUTPUT);
  pinMode(mlb1,OUTPUT);
  pinMode(mla2,OUTPUT);
  pinMode(mlb2,OUTPUT);
  pinMode(PinTrigger, OUTPUT);
  pinMode(PinEcho, INPUT);

  digitalWrite(mla1,LOW);
  digitalWrite(mlb1,LOW);
  digitalWrite(mla2,LOW);
  digitalWrite(mlb2,LOW);
  digitalWrite(PinTrigger, LOW);
  analogWrite(velmotor,vel);
}

// the loop function runs over and over again forever
void loop() {   
                   // wait for a second
  //=============================================================================
  DisparaPulsoUltrasonico();
  TempoEcho = pulseIn(PinEcho, HIGH);
  dist = CalcularDistancia(TempoEcho);

  vel = 255;
  analogWrite(velmotor,vel);
  if (dist  > 0.2) {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)

  digitalWrite(mla1,HIGH);
  digitalWrite(mlb1,HIGH);
  digitalWrite(mla2,LOW);
  digitalWrite(mlb2,LOW);

  } else {
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW

  digitalWrite(mla1,LOW);
  digitalWrite(mlb1,LOW);
  digitalWrite(mla2,HIGH);
  digitalWrite(mlb2,HIGH);
  
  }
}