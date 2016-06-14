int pinIN = 7; //pin de entrada
unsigned long contador = 0; // variable contador
unsigned long tiempo; //variable para tiempo actual
unsigned long fin; // variable para tiempo de finalizacion
int bandera = 1; //una bandera

#define lapso 10000 //el tiempo de medicion en milisegundos

void setup() {
  pinMode(pinIN, INPUT); //define el pinIN como pin de entrada
  Serial.begin(9600); //arranca el puerto serie a 9600 baudios
  tiempo = millis(); //asigna a tiempo el tiemp actual
  fin = tiempo + lapso; // agrega a tiempo el valor de lapso para dar el fin 
}

void loop()
{
  //Serial.println(digitalRead(pinIN));
  tiempo = millis();
  //por la conf del circuito si no se obtruye el sensor pinIN lee LOW
  //si pasa a HIGH y bandera está en uno incrementa contador y baja la bandera porque puede estar en HIGH mas de un ciclo del programa
  if (digitalRead(pinIN) == HIGH && bandera == 1)  
  {
    contador++;
    bandera = 0;
  }
  //cuando pinIN vuelve a LOW restablece la bandera
  if (digitalRead(pinIN) == LOW)
  {
    bandera = 1;
  }
  //cuando tiempo es mas grande o igual a fin imprime contador lo resetea y establece un nuevo fin
  if (tiempo >= fin)
  {
    Serial.print("Cantidad de interrupciones en ");
    Serial.print(lapso / 1000);
    Serial.print(" seg = ");
    Serial.println(contador);
    contador = 0;
    fin = tiempo + lapso;
  }
 
}
