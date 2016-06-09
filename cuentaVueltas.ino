/*
Contador con optoacoplador
*/


const byte pinIN = 2;
volatile unsigned long contador = 0;
unsigned long tiempo;
unsigned long fin;

#define intervalo 10000

void setup()
{
  pinMode(pinIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(pinIN), cuenta, RISING);
  Serial.begin(9600);
  tiempo = millis();
  fin = tiempo + intervalo;
}

void loop()
{
  if (tiempo >= fin)
  {
    Serial.print("Cantidad de interrupciones en 10 seg =");
    Serial.println(contador);
    contador = 0;
    tiempo = millis();
    fin = tiempo + intervalo;
  }
}

void cuenta()
{
  contador++;
}
