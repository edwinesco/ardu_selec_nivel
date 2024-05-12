const int pulsador = 12;  // Pin para conectar el pulsador

int contador = 0;         // Variable contador que incermentamos cada que se pulsa
int estadoPulsador = 0;   // Variable para almacenar el estado del pulsador

void setup() {
  // put your setup code here, to run once:
    //DDRD = 0;     //Configuro todo el puerto D como salidas

    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);

    pinMode(pulsador, INPUT);

    PORTD = 0;    //Hago una limpieza inicial del puerto D
}

void loop() {

// En este bloque de codigo preguntamos por el estado del pulsador para 
// incrementar el contador usado para seleccionar secuencia.
  estadoPulsador = digitalRead(pulsador);
  if(estadoPulsador == HIGH){
    delay(300);
    estadoPulsador = digitalRead(pulsador);
    if(estadoPulsador == HIGH){
      if(contador == 8){
        contador = 0;
      }else{
        contador = contador + 1;
      }
    }
  }

// En este bloque se hace la secuencia segun al valor almacenado en contador.
  switch(contador){
    case 0:
      PORTD = 0b00000001;
      break;
    case 1:
      PORTD = 0b00000011;
      break;
    case 2:
      PORTD = 0b00000111;
      break;
    case 3:
      PORTD = 0b00001111;
      break;
    case 4:
      PORTD = 0b00011111;
      break;
    case 5:
      PORTD = 0b00111111;
      break;
    case 6:
      PORTD = 0b01111111;
      break;
    case 7:
      PORTD = 0b11111111;
      break;
    default:
      break;
  }

}
