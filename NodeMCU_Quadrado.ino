
//Variaveis correspondentes aos pinos do nodemcu e da placa do motor.
// DEFINIÇÃO  PINO CORRESPONDENTE
#define ONA       14          // Habilita/acelera os motores da direita                      GPIO14(D5)     //pino da placa que controla os motores
#define ONB       12          // Habilita/acelera os motores da esquerda                     GPIO12(D6)    //pino da placa que controla os motores
#define IN_1      15          // Ponte H L298N in1 faz os motores  da direita ir pra tras    GPIO15(D8)   //pino da placa que controla os motores
#define IN_2      13          // Ponte H L298N in2 faz os motores da direita ir pra frente   GPIO13(D7)  //pino da placa que controla os motores
#define IN_3      2           // Ponte H L298N in3 faz os motores da esquerda ir  pra tras   GPIO2(D4)  //pino da placa que controla os motores
#define IN_4      0           // Ponte H L298N in4 faz os motores da esquerda ir pra frente  GPIO0(D3) //pino da placa que controla os motores

     
int speedCar = 600;  //define a velocidade 400 - 1023.

void setup() {
 pinMode(ONA,  OUTPUT);
 pinMode(ONB,  OUTPUT);  
 pinMode(IN_1, OUTPUT);
 pinMode(IN_2, OUTPUT);
 pinMode(IN_3, OUTPUT);
 pinMode(IN_4, OUTPUT); 
}
   
void paraFrente(){ 
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ONA, speedCar);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ONB, speedCar);
}

void paraDireita(){ 
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ONA, speedCar);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ONB, speedCar);
}

void pararCarro(){ 
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      analogWrite(ONA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      analogWrite(ONB, speedCar);
}


void loop() {
  int voltas = 0;   
  if (voltas < 4) { 
    paraFrente(); 
    delay(2500); // delay de 5000 milisegundos de segundo ou seja = 5 segundos
    paraDireita(); 
    delay(1250); // delay de 2000 milisegundos de segundo ou seja = 2 segundos mais ou menos o tempo pra virar 90° pra acabar o quadrado
    voltas++;
  }
  pararCarro;
}
