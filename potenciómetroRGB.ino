/*
* En esta practica teniamos que realizar la montage y  
* programación de un led RGB controlado por un potenciometro
* en ella debiamos utilizar el comando (map) y (constrain) para
* adaptar las señales analogicas de entrada a las salidas;
* Tambien teniamos que dividir el recorrido del potenciometro
* 6 niveles cada uno con un color que se muestra por el monitor 
* serie de forma Decima, Binaria y Hexadecimal.
*
* Rey Mirón Brais
* 21 / 04 / 2025
*/
// definición de entradas y salidas
#define LEDR 4
#define LEDV 3
#define LEDA 2
#define POT A0
//#define ANODO_C  //este define se puede comentar segun si tenemos un led en anodo comun o en catodo comun permitienod estos dos tipos 

int tiempo = 10; // tiempo de ciclos
int lectura1 = 0; // lectura = valor del potenciometro (0-1023) 
int nivel = 0; // valor entero para definir 6 niveles de color
int lectura2 = 0; // lectura = valor del potenciometro limitada (0-1023) (0-1000) 
int valor = 0; // Valor entero mapeado del potenciometro a un valor manejable

void setup(){
  Serial.begin(9600); // activar monitor serie
}

void loop(){
  lectura1 = analogRead(POT); // lectura del potecciometro
  lectura2 = constrain(lectura1, 0, 1000); // limitación de los valores de entrada de (0-1000) mediante comando (constrain)
  valor = map(lectura2, 0, 1000, 0, 600); // comando (map) para reducir el tamaño del rango de valores (0-1023) (0-600)
  if(valor <= 100){                       // condiciones de niveles 0,1,2,3,4,5 utilizando concatenación if-else
    nivel = 0;
    delay (tiempo);
  }
  else if(valor <= 200){
    nivel = 1;
    delay (tiempo);
  }
       else if(valor <= 300){
         nivel = 2;
         delay (tiempo);
       }
            else if(valor <= 400){
              nivel = 3;
              delay (tiempo);
            }
                 else if(valor <= 500){
                   nivel = 4;
                   delay (tiempo);
                 }
                      else if(valor <= 600){
                        nivel = 5;
                        delay (tiempo);
                      }
  if(nivel == 0){ // condiciones de cada nivel y su activacion de (Color)
    Color(6, 250, 239);
    delay (tiempo);
  }
  if(nivel == 1){
    Color(47, 55, 223);
    delay (tiempo);
  }
  if(nivel == 2){
    Color(255, 224, 51);
    delay (tiempo);
  }
  if(nivel == 3){
    Color(176, 2, 29);
    delay (tiempo);
  }
  if(nivel == 4){
    Color(246, 67, 181);
    delay (tiempo);
  }
  if(nivel == 5){
    Color(67, 246, 78);
    delay (tiempo);
  }
}

void Color( int rojo, int verde, int azul){ // Funcion Void Color donde se declaran los valores enteros (rojo / verde / azul)
                        // esta condicion funciona igual que las demas if pero esta depende de si eta definid0 (ANODO_C) 
  #ifdef ANODO_C 
    rojo = 255 - rojo;
    verde = 255 - verde;
    azul = 255 - azul; 
  #endif
  analogWrite(LEDR, rojo); // asociación de valores enteros a cada led (LEDR / LEDV / LEDA)
  analogWrite(LEDV, verde);
  analogWrite(LEDA, azul); // mostar valores de (rojo / verde / azul) de forma DECIMAL , BINARIA , HEXADECIMAL
  Serial.print("Decimal: "); Serial.print(rojo, DEC); Serial.print(" "); Serial.print(verde, DEC); Serial.print(" "); Serial.print(azul, DEC); 
  Serial.print("    "); // añadir espacio de separación 
  Serial.print("Binario: "); Serial.print(rojo, BIN); Serial.print(" "); Serial.print(verde, BIN); Serial.print(" "); Serial.print(azul, BIN);
  Serial.print("    "); // añadir espacio de separación
  Serial.print("Hexadecimal: "); Serial.print(rojo, HEX); Serial.print(" "); Serial.print(verde, HEX); Serial.print(" "); Serial.println(azul, HEX);
}
