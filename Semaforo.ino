#define ledV1 2
#define ledA1 3
#define ledR1 4
#define ledV2 5
#define ledA2 6
#define ledR2 7
#define potenciometro 3

#define boton1 9
#define boton2 8

int tpoten = 0;
bool activo1 = true;


void setup() {
  
  //Asignacion de pines a los leds
  pinMode(ledV1, OUTPUT);
  pinMode(ledA1, OUTPUT);
  pinMode(ledR1, OUTPUT);
  pinMode(ledV2, OUTPUT);
  pinMode(ledA2, OUTPUT);
  pinMode(ledR2, OUTPUT);

  //Asignacion de pines a los botones
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);


  //Apagado de todos los leds al inicio
  digitalWrite(ledV1, LOW);
  digitalWrite(ledA1, LOW);
  digitalWrite(ledR1, LOW);
  digitalWrite(ledV2, LOW);
  digitalWrite(ledA2, LOW);
  digitalWrite(ledR2, LOW);

  //Comienza con encendido del semaforo 1 (vehiculos) y apagado semaforo 2 (peatones)
  digitalWrite(ledV1, HIGH);
  digitalWrite(ledR2, HIGH);
}

void loop() {
  // Verificar semaforo encendido
  if(activo1){

    //Semáforo 1 (vehiculos) encendido, lee estado de boton2
    int valor1 = digitalRead(boton2);
    
    // Si va a cambiar estado apagado a encendido para semaforo 2, boton2 presionado
    if(valor1==1){ 
      //Enciende semaforo 2
      serie2();
      
      activo1=false;
    }
  }else{

    // Semáforo 2 (peatones) encendido, lee estado boton1
    int valor2 = digitalRead(boton1);

    // Cambiar estado semaforo 1 (vehiculos) a encendido, boton presionado
    if(valor2==1){
      //Enciende semaforo 2
      serie1();
      
      activo1=true;      
    }
  }
  
}

void serie1(){ //Vehiculos
  
  //Lee cambio de valor de resistencia del potenciometro
  tpoten =analogRead(potenciometro);

  //Inicia serie con semaforo 1 en verde y semaforo 2 en rojo
  digitalWrite(ledV1, HIGH);
  digitalWrite(ledA1, LOW);
  digitalWrite(ledR1, LOW);
  digitalWrite(ledV2, LOW);
  digitalWrite(ledA2, LOW);
  digitalWrite(ledR2, HIGH);

  //Tiempo de espera del valor recibido por el potenciometro
  delay(tpoten);
  
  //Lee cambio de valor de resistencia del potenciometro
  tpoten =analogRead(potenciometro);

  //Serie con semaforo 1 en amarillo y semaforo 2 en rojo
  digitalWrite(ledV1, LOW);
  digitalWrite(ledA1, HIGH);
  digitalWrite(ledR1, LOW);
  digitalWrite(ledV2, LOW);
  digitalWrite(ledA2, LOW);
  digitalWrite(ledR2, HIGH);

  //Tiempo de espera del valor recibido por el potenciometro
  delay(tpoten);
  
  //Lee cambio de valor de resistencia del potenciometro
  tpoten =analogRead(potenciometro);

  //Serie con semaforo 1 en rojo y semaforo 2 en verde
  digitalWrite(ledV1, LOW);
  digitalWrite(ledA1, LOW);
  digitalWrite(ledR1, HIGH);
  digitalWrite(ledV2, HIGH);
  digitalWrite(ledA2, LOW);
  digitalWrite(ledR2, LOW);

  //Tiempo de espera del valor recibido por el potenciometro
  delay(tpoten);
  
  //Lee cambio de valor de resistencia del potenciometro
  tpoten =analogRead(potenciometro);

  //Serie con semaforo 1 en rojo y semaforo 2 en amarillo
  digitalWrite(ledV1, LOW);
  digitalWrite(ledA1, LOW);
  digitalWrite(ledR1, HIGH);
  digitalWrite(ledV2, LOW);
  digitalWrite(ledA2, HIGH);
  digitalWrite(ledR2, LOW);

 
}

void serie2(){ //Peatones

  //Lee cambio de valor de resistencia del potenciometro
  tpoten =analogRead(potenciometro);

  //Inicia serie con semaforo 1 en rojo y semaforo 2 en verde
  digitalWrite(ledV1, LOW);
  digitalWrite(ledA1, LOW);
  digitalWrite(ledR1, HIGH);
  digitalWrite(ledV2, HIGH);
  digitalWrite(ledA2, LOW);
  digitalWrite(ledR2, LOW);

  //Tiempo de espera del valor recibido por el potenciometro
  delay(tpoten);
  
  //Lee cambio de valor de resistencia del potenciometro
  tpoten =analogRead(potenciometro);

  //Serie con semaforo 1 en rojo y semaforo 2 en amarillo
  digitalWrite(ledV1, LOW);
  digitalWrite(ledA1, LOW);
  digitalWrite(ledR1, HIGH);
  digitalWrite(ledV2, LOW);
  digitalWrite(ledA2, HIGH);
  digitalWrite(ledR2, LOW);

  //Tiempo de espera del valor recibido por el potenciometro
  delay(tpoten);
  
  //Lee cambio de valor de resistencia del potenciometro
  tpoten =analogRead(potenciometro);

  //Serie con semaforo 1 en verde y semaforo 2 en rojo
  digitalWrite(ledV1, HIGH);
  digitalWrite(ledA1, LOW);
  digitalWrite(ledR1, LOW);
  digitalWrite(ledV2, LOW);
  digitalWrite(ledA2, LOW);
  digitalWrite(ledR2, HIGH);

  //Tiempo de espera del valor recibido por el potenciometro
  delay(tpoten);
  
  //Lee cambio de valor de resistencia del potenciometro
  tpoten =analogRead(potenciometro);

  //Serie con semaforo 1 en amarillo y semaforo 2 en rojo
  digitalWrite(ledV1, LOW);
  digitalWrite(ledA1, HIGH);
  digitalWrite(ledR1, LOW);
  digitalWrite(ledV2, LOW);
  digitalWrite(ledA2, LOW);
  digitalWrite(ledR2, HIGH);

 
}
