#include <SoftwareSerial.h>
#include <Servo.h>

Servo maoE;
Servo maoD;
Servo headH;
Servo headV;
Servo cotoveloE;
Servo cotoveloD;
Servo ombroE;
Servo ombroD;
Servo peitoE;
Servo peitoD;

//Leds Dos Olhos
#define setorA 52
#define setorB 53

String dado_serial;
String valor;

int posi_atual;
long int nivel_ansiedade      = 12000;

boolean flag_b1               = 0;
boolean flag_b2               = 0;
boolean flag_b3               = 0;
boolean flag_automatico       = 1;
boolean flag_economia         = 0;
boolean flag_modo             = 0;
boolean flag_estado_maos      = 1;
boolean flag_estado_bracos    = 1;
boolean flag_estado_cabecaH   = 1;
boolean flag_estado_cabecaV   = 1;

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Comunicação Cel  ok...");

  peitoE.attach(4);
  ombroE.attach(5);
  peitoD.attach(6);
  ombroD.attach(7);
  cotoveloE.attach(8);
  cotoveloD.attach(9);
  maoE.attach(10);
  maoD.attach(11);
  headH.attach(12);
  headV.attach(13);
 
  maoE.write(0);
  maoD.write(0);
  headH.write(50);
  headV.write(0);

  peitoE.write(30);
  ombroE.write(0);
  peitoD.write(0);
  ombroD.write(0);
  cotoveloE.write(0);
  cotoveloD.write(0);
  
  pinMode(setorA,     OUTPUT);
  pinMode(setorB,     OUTPUT);

  //inicializacao();
}

void loop() {
  simula_consciencia();
  recebe_dados();
}

void move_mao(int posicao_final, int velocidade_servo, char membro) {
  switch (membro) {
    case 'e':
      posi_atual = maoE.read();
      if (posi_atual > posicao_final) {
        for (posi_atual = maoE.read(); posi_atual >= posicao_final; posi_atual -= 1) {
          maoE.write(posi_atual);
          delay(velocidade_servo);
        }
      } else {
        for (posi_atual = maoE.read(); posi_atual <= posicao_final; posi_atual += 1) {
          maoE.write(posi_atual);
          delay(velocidade_servo);
        }
      }
      break;

    case 'd':
      posi_atual = maoD.read();
      if (posi_atual > posicao_final) {
        for (posi_atual = maoD.read(); posi_atual >= posicao_final; posi_atual -= 1) {
          maoD.write(posi_atual);
          delay(velocidade_servo);
        }
      } else {
        for (posi_atual = maoD.read(); posi_atual <= posicao_final; posi_atual += 1) {
          maoD.write(posi_atual);
          delay(velocidade_servo);
        }
      }
      break;
  }
}

void move_cabeca(int posicao_final, int velocidade_servo, char membro) {
  switch (membro) {
    case 'h':
      posi_atual = headH.read();
      if (posi_atual > posicao_final) {
        for (posi_atual = headH.read(); posi_atual >= posicao_final; posi_atual -= 1) {
          headH.write(posi_atual);
          delay(velocidade_servo);
        }
      } else {
        for (posi_atual = headH.read(); posi_atual <= posicao_final; posi_atual += 1) {
          headH.write(posi_atual);
          delay(velocidade_servo);
        }
      }
      break;

    case 'v':
      posi_atual = headV.read();
      if (posi_atual > posicao_final) {
        for (posi_atual = headV.read(); posi_atual >= posicao_final; posi_atual -= 1) {
          headV.write(posi_atual);
          delay(velocidade_servo);
        }
      } else {
        for (posi_atual = headV.read(); posi_atual <= posicao_final; posi_atual += 1) {
          headV.write(posi_atual);
          delay(velocidade_servo);
        }
      }
      break;
  }
}

void move_cotovelo(int posicao_final, int velocidade_servo, char membro) {
  switch (membro) {
    case 'e':
      posi_atual = cotoveloE.read();
      if (posi_atual > posicao_final) {
        for (posi_atual = cotoveloE.read(); posi_atual >= posicao_final; posi_atual -= 1) {
          cotoveloE.write(posi_atual);
          delay(velocidade_servo);
        }
      } else {
        for (posi_atual = cotoveloE.read(); posi_atual <= posicao_final; posi_atual += 1) {
          cotoveloE.write(posi_atual);
          delay(velocidade_servo);
        }
      }
      break;

    case 'd':
      posi_atual = cotoveloD.read();
      if (posi_atual > posicao_final) {
        for (posi_atual = cotoveloD.read(); posi_atual >= posicao_final; posi_atual -= 1) {
          cotoveloD.write(posi_atual);
          delay(velocidade_servo);
        }
      } else {
        for (posi_atual = cotoveloD.read(); posi_atual <= posicao_final; posi_atual += 1) {
          cotoveloD.write(posi_atual);
          delay(velocidade_servo);
        }
      }
      break;
  }
}

void move_ombro(int posicao_final, int velocidade_servo, char membro) {
  switch (membro) {
    case 'e':
      posi_atual = ombroE.read();
      if (posi_atual > posicao_final) {
        for (posi_atual = ombroE.read(); posi_atual >= posicao_final; posi_atual -= 1) {
          ombroE.write(posi_atual);
          delay(velocidade_servo);
        }
      } else {
        for (posi_atual = ombroE.read(); posi_atual <= posicao_final; posi_atual += 1) {
          ombroE.write(posi_atual);
          delay(velocidade_servo);
        }
      }
      break;

    case 'd':
      posi_atual = ombroD.read();
      if (posi_atual > posicao_final) {
        for (posi_atual = ombroD.read(); posi_atual >= posicao_final; posi_atual -= 1) {
          ombroD.write(posi_atual);
          delay(velocidade_servo);
        }
      } else {
        for (posi_atual = ombroD.read(); posi_atual <= posicao_final; posi_atual += 1) {
          ombroD.write(posi_atual);
          delay(velocidade_servo);
        }
      }
      break;
  }
}

void move_peito(int posicao_final, int velocidade_servo, char membro) {
  switch (membro) {
    case 'e':
      posi_atual = peitoE.read();
      if (posi_atual > posicao_final) {
        for (posi_atual = peitoE.read(); posi_atual >= posicao_final; posi_atual -= 1) {
          peitoE.write(posi_atual);
          delay(velocidade_servo);
        }
      } else {
        for (posi_atual = peitoE.read(); posi_atual <= posicao_final; posi_atual += 1) {
          peitoE.write(posi_atual);
          delay(velocidade_servo);
        }
      }
      break;

    case 'd':
      posi_atual = peitoD.read();
      if (posi_atual > posicao_final) {
        for (posi_atual = peitoD.read(); posi_atual >= posicao_final; posi_atual -= 1) {
          peitoD.write(posi_atual);
          delay(velocidade_servo);
        }
      } else {
        for (posi_atual = peitoD.read(); posi_atual <= posicao_final; posi_atual += 1) {
          peitoD.write(posi_atual);
          delay(velocidade_servo);
        }
      }
      break;
  }
}

void black_eye() {
  digitalWrite(setorA, HIGH);
  digitalWrite(setorB, HIGH);
}

void blue_eye() {
  digitalWrite(setorA, LOW);
  digitalWrite(setorB, LOW);
}

void center_on() {
  digitalWrite(setorA, LOW);
  digitalWrite(setorB, HIGH);
}

void center_off() {
  digitalWrite(setorA, HIGH);
  digitalWrite(setorB, LOW);
}

void pisca() {
  black_eye();
  delay(random(30, 300));
  center_off();
}

void olha_mao_E() {
  move_cabeca(5, random(40, 60) , 'v');
  move_cabeca(80, random(20, 40) , 'h');
}

void olha_mao_D() {
  move_cabeca(5,  random(40, 60) , 'v');
  move_cabeca(20 , random(20, 40) , 'h');
}

void inicializacao() {
  center_on();
  move_cabeca(20, 30, 'v');
  move_cabeca(35, 30, 'h');
  move_mao(90, 30, 'e');
  move_mao(90, 30, 'd');
  center_off();
  move_cotovelo(0, 20,'e');
  move_cotovelo(0, 20,'d');
  move_ombro(0,10,'d');
  move_ombro(0,10,'e');
  move_peito(0,10,'d');
  move_peito(0,10,'e');
  
}

void recebe_dados() {
  while (Serial.available() > 0) {
    dado_serial = Serial.readStringUntil('\n'); //Serial.readString();
    Serial.println(dado_serial);

    if (dado_serial == "automatico")          { // Modo Automatico
      Serial.println(dado_serial);
      flag_automatico = 1;
    }
    if (dado_serial == "manual")              { // Modo Manual
      Serial.println(dado_serial);
      flag_automatico = 0;
      center_on();
    }

    if (dado_serial == "ansiedade_baixa")     { // Ansiedade Baixa
      nivel_ansiedade      = 12000;
    }
    if (dado_serial == "ansiedade_alta")      { // Ansiedade Alta
      nivel_ansiedade      = 6000;
    }

    if (dado_serial.startsWith("maoEF")) { // Mao Esquerda Fecha
      move_cotovelo(60, random(30, 40), 'e');
      olha_mao_E();
      move_mao(120, random(10, 30), 'e'); //180 fecha 0 abre
      delay(1000);
      move_mao(0, random(10, 20), 'e'); //180 fecha 0 abre
    }
    if (dado_serial.startsWith("maoEA")) { // Mao Esquerda Abre
      move_mao(120, random(10, 20), 'e'); //180 fecha 0 abre
      olha_mao_E();
      move_cotovelo(60, random(30, 40), 'e');
      delay(1000);
      move_mao(0, random(10, 30), 'e');
    }
    if (dado_serial.startsWith("maoDF")) { // Mao Direita Fecha
      move_cotovelo(60, random(30, 40), 'd');
      olha_mao_D();
      move_mao(120, random(10, 30), 'd'); //180 fecha 0 abre
      delay(1000);
      move_mao(0, random(10, 20), 'd'); //180 fecha 0 abre
    }
    if (dado_serial.startsWith("maoDA")) { // Mao Direita Abre
      olha_mao_D();
      move_mao(120, random(10, 20), 'd'); //180 fecha 0 abre
      move_cotovelo(60, random(30, 40), 'd');
      delay(1000);
      move_mao(0, random(10, 30), 'd');
   
    }
    if (dado_serial == "maosD")          { // Desativa as Mãos
      flag_estado_maos = 0;
      Serial.println("flag_estado_maos = " + String(flag_estado_maos));
    }
    if (dado_serial == "maosA")          { // Ativa as Mãos
      flag_estado_maos = 1;
      Serial.println("flag_estado_maos = " + String(flag_estado_maos));
    }

    if (dado_serial == "cabecaHd")            { // Desativa Cabeça Horizontal
      flag_estado_cabecaH = 0;
      Serial.println("flag_estado_cabecaH = " + String(flag_estado_cabecaH));
    }
    if (dado_serial == "cabecaHa")            { // Ativa Cabeça Horizontal
      flag_estado_cabecaH = 1;
      Serial.println("flag_estado_cabecaH = " + String(flag_estado_cabecaH));
    }
    if (dado_serial == "cabecaVd")            { // Desativa Cabeça Vertical
      flag_estado_cabecaV = 0;
      Serial.println("flag_estado_cabecaV = " + String(flag_estado_cabecaV));
    }
    if (dado_serial == "cabecaVa")            { // Ativa Cabeça Vertical
      flag_estado_cabecaV = 1;
      Serial.println("flag_estado_cabecaV = " + String(flag_estado_cabecaV));
    }
    if (dado_serial == "bracosD")             { // Desativa Os Braços
      flag_estado_bracos = 0;
      Serial.println("flag_estado_bracos = "+String(flag_estado_bracos));
    }  
    if (dado_serial == "bracosA")             { // Ativa Os Braços
      flag_estado_bracos = 1;
      Serial.println("flag_estado_bracos = "+String(flag_estado_bracos));
    }  
    
    if (dado_serial == "centraliza")          { // Centraliza Cabeça
      move_cabeca(20, random(30, 40) , 'v');
      move_cabeca(45, random(30, 40) , 'h');
    }
    if (dado_serial == "afirmativo")          { // Afirmativo Confirma
      move_cabeca(45, random(10, 20), 'h');
      move_cabeca(20,  random(20, 40), 'v');
      move_cabeca(0, random(20, 40), 'v');
      move_cabeca(20, random(20, 40), 'v');
      center_on();
      
      move_cotovelo(70, 20,'e');
      move_cotovelo(70, 20,'d');
      move_ombro(0,10,'d');
      move_ombro(0,10,'e');
      move_peito(0,10,'d');
      move_peito(0,10,'e');

      move_mao(100, 10, 'e'); 
      move_mao(100, 10, 'd'); 
    }

    if (dado_serial.startsWith("bracoES"))            { // Braço Esquerdo Sobe
      olha_mao_E();
      //valor = dado_serial.substring(7, dado_serial.length());
      //move_cotovelo('e', 's', 255, valor.toInt());
      move_cotovelo(60, random(30, 50), 'e');
    }
    if (dado_serial.startsWith("bracoED"))            { // Braço Direito Desce
      olha_mao_E();
      move_cotovelo(0, random(30, 50), 'e');
    }
    if (dado_serial.startsWith("bracoDS"))            { // Braço Direito Sobe
      olha_mao_D();
      move_cotovelo(60, random(30, 40), 'd');
    }
    if (dado_serial.startsWith("bracoDD"))            { // Braço Direito Desce
      olha_mao_D();
      move_cotovelo(0, random(30, 40), 'd');
    }

    if (dado_serial.startsWith("ombro_E_sobe"))        { // Ombro Superior Esquerdo Sobe
      move_cotovelo(60, random(30, 50), 'e');
      olha_mao_E();
      move_ombro(50, random(30, 50), 'e');
      delay(1000);
      delay(random(100,1000));
      move_ombro(0, random(30, 50), 'e');
    }
    if (dado_serial.startsWith("ombro_E_desce"))       { // Ombro Superior Esquerdo Desce
      olha_mao_E();
      move_ombro(0, random(30, 50), 'e');
    }
    if (dado_serial.startsWith("ombro_D_sobe"))        { // Ombro Superior Direito Sobe
      move_cotovelo(60, random(30, 50), 'd');
      olha_mao_D();
      move_ombro(50, random(30, 50), 'd');
      delay(1000);
      delay(random(100,1000));
      move_ombro(0, random(30, 50), 'd');
    }
    if (dado_serial.startsWith("ombro_D_desce"))       { // Ombro Superior Direito Desce
      olha_mao_D();
      move_ombro(0, random(30, 50), 'd');
    }

    if (dado_serial.startsWith("peito_E_sobe"))        { // Ombro Lateral Esquerdo Sobe
      move_cotovelo(60, random(30, 40), 'e');
      olha_mao_E();
      move_peito(0, random(30, 50), 'e');
      delay(1000);
      delay(random(100,1000));
      move_peito(30, random(30, 40), 'e');
    }
    if (dado_serial.startsWith("peito_E_desce"))       { // Ombro Lateral Esquerdo Desce
      olha_mao_E();
      move_peito(30, random(30, 50), 'e');
    }
    if (dado_serial.startsWith("peito_D_sobe"))        { // Ombro Lateral Direito Sobe
      move_cotovelo(50, random(30, 50), 'd');
      olha_mao_D();
      move_peito(50, random(30, 50), 'd');
      delay(1000);
      delay(random(100,1000));
      move_peito(0, random(30, 50), 'd');
    }
    if (dado_serial.startsWith("peito_D_desce"))       { // Ombro Lateral Direito Desce
      olha_mao_D();
      move_peito(0, random(30, 50), 'd');
    }
  }
}

void simula_consciencia() {
  if (flag_automatico == 1) { //Modo Automático (flag_automatico == 1)
    if (random(1, nivel_ansiedade) < 20) { //Olho
      pisca();
    }
    if (random(1, nivel_ansiedade) < 4) { //Cabeça Vertical
      if (flag_estado_cabecaV == 1) {
        move_cabeca(random (30, 40), random (50, 80), 'v');
      }
    }
    if (random(1, nivel_ansiedade) < 4) { //Cabeça Horizontal
      if (flag_estado_cabecaH == 1) {
        move_cabeca(random (20, 70), random (20, 50), 'h');
      }
    }
    if (random(1, nivel_ansiedade) < 4) { //Move Mão Esquerda
      if (flag_estado_maos == 1) {
        move_mao(random (0, 100), random (10, 30), 'e');
        if (random(1, 10) <= 5) {
          olha_mao_E();
        }
      }
    }
    if (random(1, nivel_ansiedade) < 4) { //Move Mão Direita
      if (flag_estado_maos == 1) {
        move_mao(random (0, 100), random (10, 20), 'd');
        if (random(1, 10) <= 5) {
          olha_mao_D();
        }
      }
    }
    if (random(1, nivel_ansiedade) < 3) { //Move Braço Esquerdo
      if (flag_estado_bracos == 1) {
        move_cotovelo(random (0, 50), random (20, 40), 'e');
        if (random(1, 10) <= 5) {
          olha_mao_E();
        }
      }
    }
    if (random(1, nivel_ansiedade) < 3) { //Move Braço Direito
      if (flag_estado_bracos == 1) {
        move_cotovelo(random (0, 50), random (20, 40), 'd');
        if (random(1, 10) <= 5) {
          olha_mao_D();
        }
      }
    }

    if (random(1, nivel_ansiedade) < 2) { //Move Ombro Esquerdo
      if (flag_estado_bracos == 1) {
        move_cotovelo(random (50, 60), random (20, 40), 'e');
        olha_mao_E();
        pisca();
        move_ombro(random (10, 40), random (20, 40), 'e');
        delay(300);
        pisca();
        move_ombro(0, random (20, 40), 'e');
        pisca();
      }
    }
    if (random(1, nivel_ansiedade) < 2) { //Move Ombro Direito
      if (flag_estado_bracos == 1) {
        move_cotovelo(random (50, 60), random (20, 40), 'd');
        olha_mao_D();
        pisca();
        move_ombro(random (10, 40), random (20, 40), 'd');
        delay(300);
        pisca();
        move_ombro(0, random (20, 40), 'd');
        pisca();
        }
    }
    if (random(1, nivel_ansiedade) < 2) { //Move Peito Esquerdo
      if (flag_estado_bracos == 1) {
        move_cotovelo(60, random (20, 40), 'e');
        olha_mao_E();
        pisca();
        move_peito(random (0,30), random (20, 40), 'e');
        delay(300);
        pisca();
        move_peito(30, random (20, 40), 'e');
        pisca();
      }
    }
    if (random(1, nivel_ansiedade) < 2) { //Move Peito Direito
      if (flag_estado_bracos == 1) {
        move_cotovelo(60, random (20, 40), 'd');
        olha_mao_D();
        pisca();
        move_peito(random (0,60), random (20, 40), 'd');
        delay(300);
        pisca();
        move_peito(0, random (20, 40), 'd');
        pisca();      }
    }
  }
}


 
