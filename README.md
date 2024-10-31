# Carrinho Robô com Desvio de Obstáculos Usando Ultrassônico

Este repositório contém o código e instruções para construir um carrinho robô que evita obstáculos usando um sensor de distância ultrassônico e um Arduino. O robô detecta obstáculos à sua frente e evita colisões mudando de direção.

<details>
<summary>🇧🇷 Versão em Português</summary>

## Componentes

Os principais componentes usados neste projeto são:

1. **Arduino UNO R3**  
   - O microcontrolador que alimenta o robô e processa os dados do sensor.

2. **Módulo Driver de Motor L298N (HW-095)**  
   - Um módulo de driver de motor H-bridge duplo que controla a velocidade e direção dos dois motores DC.

3. **Sensor de Distância Ultrassônico HC-SR04**  
   - Um sensor que mede a distância até obstáculos à frente do carrinho, permitindo que ele os detecte e evite.

4. **2x Motores DC TT (3-6V) com Caixa de Redução e Eixo Duplo**  
   - Esses motores movimentam as rodas, fornecendo o movimento e controle de velocidade necessários para o carrinho robô.

5. **Protoboard**  
   - Usado para conectar o sensor ultrassônico e outros componentes sem solda.

## Como Funciona

O carrinho robô é programado para se mover para frente até detectar um obstáculo a uma distância pré-definida usando o sensor ultrassônico HC-SR04. Ao detectar um obstáculo, o carrinho para e muda de direção para evitar a colisão.

### Fluxo Básico:
1. **Mover para Frente:** O carrinho se move para frente por padrão.
2. **Detecção de Obstáculo:** O sensor HC-SR04 mede constantemente a distância à frente do carrinho.
3. **Desvio:** Se um obstáculo for detectado dentro de um intervalo definido, o carrinho para, dá ré e muda de direção.
4. **Retomar Movimento:** O carrinho retoma o movimento para frente quando o caminho está livre.

## Conexões

### Conexões:
- **Arduino UNO** controla o sensor HC-SR04 e o driver de motor L298N.
- **Driver de Motor L298N** conecta-se aos dois motores TT para controlar sua velocidade e direção.
- **Sensor Ultrassônico HC-SR04** é conectado ao Arduino para medir a distância.

### Configuração dos Pinos:
- **Sensor Ultrassônico HC-SR04**  
  - VCC: 5V no Arduino  
  - GND: GND no Arduino  
  - Trig: Pino Digital X no Arduino (substitua "X" pelo pino utilizado)  
  - Echo: Pino Digital Y no Arduino (substitua "Y" pelo pino utilizado)

- **Driver de Motor L298N**  
  - IN1, IN2: Pinos de controle para o Motor A  
  - IN3, IN4: Pinos de controle para o Motor B  
  - ENA e ENB: Controle de velocidade para Motor A e B

## Código

O código Arduino inicializa o sensor e o driver de motor, verificando constantemente a distância à frente. Se um obstáculo for detectado dentro de um limite de distância, o carrinho para, dá ré e vira até encontrar um caminho livre.

## Requisitos

- [IDE Arduino](https://www.arduino.cc/en/software) para fazer o upload do código no Arduino UNO
- Conhecimento básico de cabeamento e programação Arduino

## Instruções de Configuração

1. Monte o chassi do robô e fixe todos os componentes como mostrado na imagem.
2. Conecte cada componente seguindo as instruções de cabeamento acima.
3. Faça o upload do código para o Arduino UNO usando a IDE Arduino.
4. Alimente o Arduino e o driver de motor. O carrinho deve começar a se mover e evitar obstáculos.

## Licença

Este projeto é open-source e está disponível sob a licença MIT.

</details>

<details>
<summary>🇺🇸 English Version</summary>

## Components

The main components used in this project are:

1. **Arduino UNO R3**  
   - The microcontroller that powers the robot and processes the sensor data.

2. **L298N Motor Driver Module (HW-095)**  
   - A dual H-bridge motor driver module that controls the speed and direction of the two DC motors.

3. **HC-SR04 Ultrasonic Distance Sensor**  
   - A sensor module that measures the distance to obstacles in front of the car, allowing it to detect and avoid them.

4. **2x TT DC Motors (3-6V) with Gear Reduction and Dual Shaft**  
   - These motors drive the wheels, providing the necessary movement and speed control for the robot car.

5. **Small Breadboard**  
   - Used for connecting the ultrasonic sensor and other components without soldering.

## How It Works

The robot car is programmed to move forward until it detects an obstacle within a predefined distance using the HC-SR04 ultrasonic sensor. Upon detecting an obstacle, the car stops and reverses or turns in a different direction to avoid collision.

### Basic Workflow:
1. **Move Forward:** The car moves forward by default.
2. **Obstacle Detection:** The HC-SR04 sensor continuously measures the distance in front of the car.
3. **Avoidance:** If an obstacle is detected within a set range, the car stops, reverses, and changes direction.
4. **Resume Movement:** The car resumes forward movement once the path is clear.

## Wiring

### Connections:
- **Arduino UNO** controls the HC-SR04 sensor and the L298N motor driver.
- **L298N Motor Driver** connects to both TT motors to control their speed and direction.
- **HC-SR04 Sensor** is connected to the Arduino for distance measurement.

### Pin Configuration:
- **HC-SR04 Ultrasonic Sensor**  
  - VCC: 5V on Arduino  
  - GND: GND on Arduino  
  - Trig: Digital Pin X on Arduino (replace "X" with the actual pin used)  
  - Echo: Digital Pin Y on Arduino (replace "Y" with the actual pin used)

- **L298N Motor Driver**  
  - IN1, IN2: Control pins for Motor A  
  - IN3, IN4: Control pins for Motor B  
  - ENA and ENB: Speed control for Motor A and B

## Code

The Arduino code will initialize the sensor and motor driver, constantly checking the distance ahead. If an obstacle is detected within a certain distance threshold, the car will stop, reverse, and turn until it finds a clear path.

## Requirements

- [Arduino IDE](https://www.arduino.cc/en/software) for uploading the code to the Arduino UNO
- Basic understanding of wiring and Arduino programming

## Setup Instructions

1. Assemble the robot chassis and mount all components as shown in the image.
2. Connect each component following the wiring instructions above.
3. Upload the code to the Arduino UNO using the Arduino IDE.
4. Power the Arduino and the motor driver. The car should start moving and avoid obstacles.

## License

This project is open-source and available under the MIT License.

</details>
