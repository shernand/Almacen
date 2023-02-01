//*****************************************************************************
// Aplicación para la medición de Distancia un sensor de 
// Ultrasonido.
//
// Vcc    --> 5 Vdc
// Trig   --> Trigger (INPUT) - Pin 3
// Echo   --> Echo (OUTPUT) - Pin 2
// Gnd    --> Gnd 
//-----------------------------------------------------------------------------

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);

int trigPin = 3;            // Trigger
int echoPin = 2;            // Echo
long duration, cm, inches;

//=============================================================================

//-----[ AJUSTES ]-----
void setup(){
  Serial.begin(9600);       // Inicialización de puerto serial
  pinMode(trigPin, OUTPUT); // definición de Salidas / Entradas
  pinMode(echoPin, INPUT);

  lcd.begin(20,4);          // Ajuste de la LCD
}
//-----[ LAZO PRINCIPAL ]-----
void loop(){
  // El sensor es disparado por un pulso ("HIGH"-"LOW") de 10 o mas uSegs.
  // Emplear un pulso corto (en "LOW") antes de asefurar un pulso limpio en
  // "HIGH".
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lectura de la señal del sensor. Un pulso en nivel "HIGH", cuya duración
  // es el tiempo (en microsegundos) desde el envío de la señal "ping"
  // hasta la recepción del eco al rebotar en el objeto detectado.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // Conversión del tiempo leído, a distancia.
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;

  // Despliegue de la lectura
  lcd.setCursor(0,0);
  lcd.print("Inches:");
  lcd.print(inches);
  lcd.print("in");
  
  lcd.setCursor(0,1);
  lcd.print("Cm:");
  lcd.print(cm);
  lcd.print("cm");

  Serial.print(inches);
  
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(250);
}












//*****************************************************************************
