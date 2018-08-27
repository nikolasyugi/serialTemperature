/****** Leitura de Temperatura mostrando no monitor serial ******/

int valor; //Variável em que será armazenado o valor de leitura do sensor

int pinoTemperatura = 0; //Variável que representa o pino analógico conectado ao sensor, no caso o pino 0

int alimentacao = 5; //Tensão em volts da alimentação

void setup(){ //Parte de inicialização

  Serial.begin(9600); //Inicializa a comunicação serial

}


void loop(){ //Parte que se repetirá indefinidamente

  valor = analogRead(pinoTemperatura); //Leitura do sensor -> número de 0 a 1024

  float intermediario = (valor/1024.0)*alimentacao; // Regra de 3 para converter a leitura do sensor para tensão em mV
  
  intermediario = intermediario*1000; // Conversão de mV para V
  
  float celsius = intermediario/10; //Sensor: cada 10mV -> 1 grau Celsius
  
  /* Texto que será mostrado no monitor serial */
  Serial.print("TEMPERATURA = "); 
  Serial.print(celsius);
  Serial.print("*C");
  Serial.println();
  
  delay(1000); //Atraso de 1000ms para fazer nova leitura do sensor 

}
