//******************************************************************************
// Revisión de una aplicación para un Sistema de Cerradura de una Puerta
// Aplicación simple para ensayar características de la plataforma Arduino.
// Autor:   Sergio fco. hernández Machuca (Adaptación de diversas aplicaciones)
// Fecha:   Agosto del 2019
//
//
//******************************************************************************
#include <Keypad.h>
#include <LiquidCrystal.h>
//---[Habilitación de la LCD]---
//--> CAMBIA para LCD de 20x4, manejada por módulo I2C <--
// Inicializa la LCD
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//---[Habilitación del TECLADO]---
const byte ROWS = 4;  // Cuatro hileras del teclado
const byte COLS = 4;  // Cuatro Columnas del teclado
// --> Adaptar al teclado propio <--
// Definición de los símbolos del teclado (serigrafía)
char hexaKeys[ROWS][COLS] = {
  {'7', '8', '9', '/'},
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'C', '0', '=', '+'}
};
// Conexiones a las terminales del teclado:
byte rowPins[ROWS] = {3, 2, 19, 18};    // Hileras
byte colPins[COLS] = {17, 16, 15, 14};  // Columnas
// Inicialización de la una instancia del Teclado
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//---[Habilitación de Otros Elementos]---
const int LED_RED = 10;   // LED Rojo (Red)
const int LED_GREEN = 11; // LED Verde (Green)
const int RELAY = 12;     // Relevador de apertura (o motor)
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//---[ VARIABLES ]---
char keycount = 0;        // Conteo de intentos
char code[4];             // Retención de teclas oprimidas
//---[AJUSTES]-------------------------------------------------------------------
void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(RELAY, OUTPUT);
  // Ajuste de las características de la LCD (¡Modificar!)
  lcd.begin(16, 2);
  lcd.print("Password Access:");  // Impresión de un mensaje en la LCD
  lcd.setCursor(0, 1);    // Mover cursor a la segunda línea
  lcd.cursor();           // Encender el cursor
  digitalWrite(LED_GREEN, HIGH);  // Prendido
  digitalWrite(LED_RED, LOW);     // Apagado
  digitalWrite(RELAY, LOW);       // Apagado del relevador
}
//---[CICLO]--------------------------------------------------------------------
void loop() {
  char customKey = customKeypad.getKey();

  if (customKey && (keycount < 4) && (customKey != '=') && (customKey != 'C')) {
    // lcd.print(customKey);    // Para imprimir tecla introducida
    lcd.print('*');             // Enmascaramiento de info, para protección
    code[keycount] = customKey;
    keycount++;
  }
  if (customKey == 'C') {   // Tecla "Cancel/Lock" presionada para limpiar LCD...
    Lock();                 // ...y cerrar la puerta
  }
  if (customKey == '=') {   // Revisar Password y abrir
    if ((code[0] == '1') && (code[1] == '2') && (code[2] == '3') && (code[3] == '4'))
      // Verificar el password, por omisión: “1234”
    {
      digitalWrite(LED_GREEN, LOW); // Apaga LED Verde
      digitalWrite(LED_RED, HIGH);  // Enciende LED Rojo
      digitalWrite(RELAY, HIGH);    // Apertura de la puerta
      lcd.setCursor(0, 1);
      lcd.print("Door Open       ");
      delay(4000);                  // Se mantiene abierta por 4 segundos
      Lock();
    }
    else
    {
      lcd.setCursor(0, 1);            //
      lcd.print("Invalid Password");  // Muestra mensaje de error
      delay(1500);                    // Espera un momento
      Lock();
    }
  }
}
//******************************************************************************
//-----[ SUBRUTINAS y FUNCIONES ]-----
//---[Cerradura de Puerta y ACtualización de mensaje en la LCD ]---
void Lock() {
  lcd.setCursor(0, 1);            //
  lcd.print("Door Locked     ");  //
  delay(1500);                    // Espera un tiempo
  lcd.setCursor(0, 1);            //
  lcd.print("                ");  // Limpieza del password
  lcd.setCursor(0, 1);
  keycount = 0;                   // Reinicia número de intentos
  digitalWrite(LED_GREEN, HIGH);  // LED Verde
  digitalWrite(LED_RED, LOW);     // LED Rojo
  digitalWrite(RELAY, LOW);       // Cierra la puerta
}
//******************************************************************************
