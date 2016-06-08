int pinEntrada = 7;
unsigned long contador = 0;
unsigned long tiempo;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinEntrada, INPUT);
  Serial.begin(9600);
}

void loop() {

  //test contador
  if (digitalRead(pinEntrada == HIGH))
  {
    contador++;
    Serial.print(contador);
    Serial.print("\n");
  }
  /*
    //contador por minuto
    tiempo = millis();
    while (tiempo <= tiempo + 60000)
    {
      if (digitalRead(pinEntrada == HIGH))
        {
              contador++;
        }
    }

    Serial.print("Cantidad de Vueltas en el Ultimo Minuto \n");
    Serial.print(contador);
    Serial.print("\n");
    contador = 0;
    tiempo = 0;
  */
}