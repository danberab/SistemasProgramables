//Leds para semaforo 1 (vehiculos)
#define LedVerde1 2
#define LedAmarillo1 3
#define LedRojo1 4

//Leds para semaforo 2 (peatones)
#define LedVerde2 5
#define LedAmarillo2 6
#define LedRojo2 7


// Declaracion de variables
bool activo1 = true; // Si el semáforo 1 está activo = True, de lo contrario será el semáforo 2
int tiempoCambio = 1500; // Tiempo de espera entre transición de LEDs
int tiempoEspera = 5000; // Tiempo de espera hasta comenzar transición


void setup() {
  
  // Se inicia el monitor serie
  Serial.begin(9600);

  // Modos de entrada/salida 
  pinMode(LedVerde1, OUTPUT);
  pinMode(LedAmarillo1, OUTPUT);
  pinMode(LedRojo1, OUTPUT);

  pinMode(LedVerde2, OUTPUT);
  pinMode(LedAmarillo2, OUTPUT);
  pinMode(LedRojo2, OUTPUT);


  // Apagar los leds
  digitalWrite(LedVerde1, LOW);
  digitalWrite(LedAmarillo1, LOW);
  digitalWrite(LedRojo1, LOW);
  digitalWrite(LedVerde2, LOW);
  digitalWrite(LedAmarillo2, LOW);
  digitalWrite(LedRojo2, LOW);

  // Inicio con semáforo 1 (vehiculos) paso, semáforo 2 (peatones) alto
  digitalWrite(LedVerde1, HIGH);
  digitalWrite(LedRojo2, HIGH);
 
}


void loop() {
  // Verificar semaforo encendido
  if (activo1){
    int valor2=1;
    // Si va a cambiar estado apagado a encendido para semaforo 1(vehiculos)
      if (valor2 == HIGH){

        // Enciende semáforo 2
        semaforo2();

        // Semáforo 2 activo
        activo1 = false;
      }
  }else{
    int valor1= 1;
    // Cambiar estado semaforo 1 (vehiculos) a encendido
    if (valor1 == HIGH){
      
      // Enciende semáforo 1
      semaforo1();

      // Semáforo 1 activo
      activo1 = true;
    }
  }
  
}


void semaforo1(){
  // Semáforo 1 apagado y tiempo de espera:
  delay(tiempoEspera);

  // Sigue luz amarilla
  digitalWrite(LedVerde2, LOW);
  digitalWrite(LedAmarillo2, HIGH);

  // Tiempo de espera
  delay(tiempoCambio);

  // Sigue luz roja
  digitalWrite(LedAmarillo2, LOW);
  digitalWrite(LedRojo2, HIGH);

  // Semaforo 1 encendido
  
  // Tiempo de espera
  delay(tiempoCambio);

  // Regresa luz amarilla
  digitalWrite(LedRojo1, LOW);
  digitalWrite(LedVerde1, HIGH);
}

void semaforo2(){
  // Semáforo 1 apagado y tiempo de espera:
  delay(tiempoEspera);

  // Sigue luz amarilla
  digitalWrite(LedVerde1, LOW);
  digitalWrite(LedAmarillo1, HIGH);

  // Tiempo de espera
  delay(tiempoCambio);

  // Sigue luz roja
  digitalWrite(LedAmarillo1, LOW);
  digitalWrite(LedRojo1, HIGH);

  // Semaforo 2 encendido
  
  // Tiempo de espera
  delay(tiempoCambio);

  // Regresa luz amarilla
  digitalWrite(LedRojo2, LOW);
  digitalWrite(LedVerde2, HIGH);
}
