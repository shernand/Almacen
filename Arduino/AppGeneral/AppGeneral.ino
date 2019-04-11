//******************************************************************************
// Desarrollo de una APLICACIÓN GENERAL
// Elementos que incluye (RTC, ENCODIFICADOR ROTATIVO, LCD, TFT, Etc.)
// ---> VERSIÓN para ENCODIFICADOR ROTATIVO <---  
// IMPORTANTE: Hacer ajustes en: MD_Menu.cpp, MD_Menu.h, en MD_Menu_lib.h, 
// en la identificación del mecanismo (interruptor) para salir de la ejecución 
// de opciones, ocupando las librerías de MD_UISwitch o similar.
// --> Para el tipo de respuesta "Y/N" a selecciones.
// --> Tipo de Dispositivo de Navegación.
// --> Tipo de Dispositivo de Despliegue de Información.
// --> Consideraciones del tipo de Interface...(agregar opciones)
// --> Verificar ACTUALIZACIONES de MN_Menu, Parola y otros apoyos.
//******************************************************************************
//-----[ AJUSTES PRINCIPALES ]-----
//=============================================================================
//---[ BIBLIOTECAS y RECURSOS y AJUSTES de la APLICACIÓN ]---
// Aquí están: Definiciones, Bibliotecas, Recursos, Ajustes por Elemento
#include "AppGeneral.h"
//=============================================================================
//---[ ADMINISTRACIÓN del MENÚ de Opciones ]---
//--[ Estructura del árbol de SELECCIÓN, DESPLIEGUE y ACCIONES de opciones ]--
#include "Estructura.h"
//=============================================================================
// Definición del arreglo de LEDs (FastLED)
CRGB leds[NUM_LEDS];
//---[ INSTANCIACIÓN del MENÚ global ]---
MD_Menu M(navigation, display,          // NAVEGACIÓN y DESPLIEGUE del usuario.
          mnuHdr, ARRAY_SIZE(mnuHdr),   // Encabezado de Datos del MENÚ 
                                        // (menu Header data)
          mnuItm, ARRAY_SIZE(mnuItm),   // Elementos de Datos del MENÚ 
                                        // (menu Item data)
          mnuInp, ARRAY_SIZE(mnuInp));  // Entradas de Datos del MENÚ 
                                        // (menu Input data)
//=============================================================================
// PREGUNTAR si están [DES]Habilitados

//-----[ VARIABLES de la APLICACIÓN ]-----

int8_t EdoLed = LOW;      // Estado inicial del LED
int8_t EdoInicial = LOW;  // Estado inicial del Temporizado
// -----
unsigned long previoMillis = 0;   // valor inicial del "Tick" interno.
unsigned long actualMillis;       // Valor de "Ticks" del sistema.
// -----
int16_t Timer0 = 2500;    // Valores para Temporizadores (milisegundos).
int16_t Timer1 = 150;     //
int16_t Timer2 = 750;     //
int16_t Timer3 = 150;     //
// -----
//---[ VARIABLES GLOBALES que se MANIPULAN y CONSULTAN desde el MENÚ]---
uint16_t dummy;           // Auxiliar para el manejo del MENÚ.
bool bValue = true;       // Valor referencia en "Callback" de funciones.
MD_Menu::value_t vBuf;    // Buffer de interface para valores del menú.
// Variables para ÍNDICES de LISTAS
uint8_t IndLista1 = 0;   // Índice en Lista 1
uint8_t IndLista2 = 1;   // Índice en Lista 2
uint8_t IndLista3 = 2;   // Índice en Lista 3
uint8_t IndLista4 = 3;   // Índice en Lista 4
uint8_t IndLista5 = 4;   // Índice en Lista 5
uint8_t IndLista6 = 5;   // Índice en Lista 6
uint8_t IndLista7 = 6;   // Índice en Lista 7
uint8_t IndLista8 = 7;   // Índice en Lista 8
uint8_t IndLista9 = 8;   // Índice en Lista 9
uint8_t IndListaA = 9;   // Índice en Lista A
// VARIABLES para el RTC:
int8_t    Horas =     12;   // Para el RTC:
int8_t    Minutos =   30;   //
int8_t    Segundos =  30;   //
int8_t    DiaSem =    4;    // 1 = Domingo, 2 = Lunes, Etc.
int8_t    DiaMes =    15;   //
int8_t    Mes =       6;    // 1 = Enero, 2 = Febrero, Etc.
int16_t   Ayo =       2018; //
// VARIABLES para DATOS empleados en la APLICACIÓN:
uint8_t Contador1 = 0;      // Contador para algún evento
uint8_t Distancia = 0;      // Contador para algún evento
uint8_t Intensidad = 0;     // Contador para algún evento
uint8_t Iluminacion = 0;    // Contador para algún evento
uint8_t Matiz = 0;          // Contador para algún evento
uint8_t Sombreado = 0;      // Contador para algún evento
uint8_t Tonalidad = 0;      // Contador para algún evento
uint8_t Transparencia = 0;  // Contador para algún evento
uint8_t Radio = 0;          // Contador para algún evento
uint8_t Contador2 = 0;      // Contador para algún evento
//---[ VARIABLES GLOBALES que se UTILIZAN en la APLICACIÓN ]---
//---[ RTC ]---
volatile boolean  bShowTime = false;
//==============================================================================
//-----[ CÓDIGO de APOYO, FUNCIONES, SUBRUTINAS, MACROS ]-----
//==============================================================================
//---[ CONVIERTE números DECIMALES a BINARIO CODIFICADO en DECIMAL ]---
byte decToBcd(byte val) {
  return ( (val / 10 * 16) + (val % 10) );
}
//---[ CONVIERTE BINARIOS CODIFICADOS en DECIMAL a DECIMALES normales ]---
byte bcdToDec(byte val) {
  return ( (val / 16 * 10) + (val % 16) );
}
//---[IMPRIME 2 DÍGITOS, anteponiendo un "0" si es necesario ]---
void p2dig(uint8_t v) {
  if (v < 10) lcd.print("0");
  lcd.print(v);
}
//---[ Día de Semana a Cadena [DOW 1=Dom, 2=Lun, 3=Mar, Etc., menos "0"] ]---
const char *dow2String(uint8_t code) {
  static const char *str[] = {"---", "Dom", "Lun", "Mar", "Mie", "Jue", "Vie",
                              "Sab"};
  return (str[code]);
}
//--- [ IMPRIME la FECHA y el TIEMPO actual en una pantalla LCD ]---
void printTime(void) {
  lcd.setCursor(0, 0);
  lcd.print("-> ");
  lcd.print(dow2String(RTC.dow)); // Día de la Semana
  lcd.print(" ");
  p2dig(RTC.dd);          // Día del Mes
  lcd.print("-");
  p2dig(RTC.mm);          // Mes
  lcd.print("-");
  lcd.print(RTC.yyyy);    // Año

  lcd.setCursor(0, 1);
  lcd.print("-> ");
  p2dig(RTC.h);           // Hora
  lcd.print(":");
  p2dig(RTC.m);           // Minutos
  lcd.print(":");
  p2dig(RTC.s);           // Segundos

  RTC.control(DS3231_12H, DS3231_OFF);  // Para usar formato de 24 horas.
  if (RTC.status(DS3231_12H) == DS3231_ON)
    lcd.print(RTC.pm ? " pm" : " am");
}
//---[ Actualiza el desplegado del RTC ]---
void displayUpdate(void) {
  RTC.readTime();
  printTime();
}
//-----
#if USE_POLLED_CB || USE_INTERRUPT
// Función de retorno ("callback") y de Interrupción (funciona igual).
void alarmICB(void) {
  bShowTime = true;    // Ajusta la bandera para actualizar.
}
#endif
//==============================================================================
//-----[ VERIFICACIÓN de que se INVOCA el MENÚ ]-----
void necesitaMenu(void) {
  if (navigation(dummy) == MD_Menu::NAV_SEL) {
    M.runMenu(true);
  }
}
//==============================================================================
// Setup()
//==============================================================================
void setup(void) {
  
  // Ensayo de FastLED:
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

  for (int i = 0; i < NUM_LEDS; i++) {  // Limpieza de la tira de LEDs.
    leds[i] = CRGB::Black;
  }
  // Parpadea Amarillo-Verde
  for (int i = 0; i <= 3; i++) {
    leds[0] = CRGB::Yellow; FastLED.show(); delay(300);
    leds[0] = CRGB::Green; FastLED.show(); delay(100);
  }
  leds[0] = CRGB::Purple;
  FastLED.show();

  //---[ Para uso GENERAL ]---
  lcd.init();       // Para poder emplear la LCD en la aplicación LOCAL.
  lcd.backlight();  // Encender el LED de fondo.
  lcd.clear();      // Limpiar la pantalla.
  lcd.setCursor(0, 3);
  lcd.print("-> APPLICACION <-- ");
  
  pinMode(LED_BUILTIN, OUTPUT);

  //--- Para uso de la APLICACIÓN
  pinMode(Timer0Pin, OUTPUT);   // Ajuste de terminales para relevadores.
  pinMode(Timer1Pin, OUTPUT);   // con Timers
  pinMode(Timer2Pin, OUTPUT);   //
  pinMode(Timer3Pin, OUTPUT);   //
  
  //--- Para el manejo del MENÚ
  display(MD_Menu::DISP_INIT);  // Ajuste para DESPLIEGUE del MENÚ.
  setupNav();                   // Ajuste de NAVEGACIÓN a través del MENÚ.
  M.begin();                  // Inicialización del Objeto del MENÚ.
  M.setMenuWrap(true);        //
  M.setAutoStart(AUTO_START); // Ajuste del INICIO por OMISIÓN
  M.setTimeout(MENU_TIMEOUT); // Tiempo de expiración para accionar el MENÚ.

  //--- [Para el USO del RTC ]---
  //---[ AJUSTES del MEDIOAMBIENTE de la ALARMA1 del RTC ] ---
#if USE_POLLED
  // Nada más que hacer
#endif
#if USE_POLLED_CB
  RTC.setAlarm1Callback(alarmICB);
#endif
#if USE_INTERRUPT
  // Ajusta el hardware en la tarjeta Arduino.
  pinMode(PIN_INTERRUPT, INPUT_PULLUP);
  attachInterrupt(0, alarmICB, FALLING);
  // Ajusta los registros de interrupción del RTC.
  RTC.control(DS3231_A2_INT_ENABLE, DS3231_ON);
  RTC.control(DS3231_A1_INT_ENABLE, DS3231_ON);
  RTC.control(DS3231_INT_ENABLE, DS3231_ON);
  // "Apaga" la bandera de la Alarma1, en caso de que estuviera "Puesta"
  RTC.control(DS3231_A1_FLAG, DS3231_OFF);
#endif
  // Ahora se incializa la Alarma1 para actualizar la pantalla cada segundo.
  RTC.setAlarm1Type(DS3231_ALM_SEC);
}
//==============================================================================
// Loop()
//==============================================================================
void loop(void) {
  static bool prevMenuRun = true;
  static int Contador;

  // Detecta si se necesita iniciar la ejecución normal del código del usuario
  // ¿NO se está EJECUTANDO el MENÚ?
  if (!M.isInMenu()) {
    // --> INICIA el código NORMAL del USUARIO <--

#if USE_POLLED
    bShowTime = RTC.checkAlarm1();
#endif
#if USE_POLLED_CB
    RTC.checkAlarm1();
#endif
    // Si está "Puesta", actualiza pantalla y "Apaga" la bandera de muestra.
    if (bShowTime) {
#if USE_INTERRUPT
      RTC.control(DS3231_A1_FLAG, DS3231_OFF);  // "Apaga" bandera de "Alarma1".
#endif
      displayUpdate();
    }
    bShowTime = false;
    necesitaMenu();     // Verifica si se ha invocado el MENÚ.

    // --> CÓDIGO en PRUEBA
    // Secuencia temporizado: Timer0 --> Timer1 --> Timer0 --> Timer1 --> Timer1
    // _____________________-----------|__________|----------|__________1-------
    // Se desconoce el estado inicial del LED que se prende / apaga.

    actualMillis = millis();
    EdoInicial = HIGH; // Corresponde al estado que adopta la salida por Timer0.
    Timer0 = 500;
    Timer1 = 500;

    if (EdoLed == EdoInicial) {
      if (actualMillis - previoMillis > Timer0) {
        previoMillis = actualMillis;
        EdoLed = !EdoInicial;
      }
    } else {
      if (actualMillis - previoMillis > Timer1) {
        previoMillis = actualMillis;
        EdoLed = EdoInicial;
      }
    }
    digitalWrite(LED_BUILTIN, EdoLed);

    // CÓDIGO en PRUEBA <---
    // ¡OJO! --> DEBE sostenerse el pulsador de CNTL para entrar al MENÚ,
    // al menos uos tres segundos, ya luego funciona normalmente <-- ¡OJO!

    lcd.setCursor(0, 2);
    lcd.print("29-Marzo-20:33..");
    lcd.setCursor(0, 3);
    lcd.print("Matiz = ");
    lcd.print(Matiz, HEX);

    // --> CONCLUYE el código NORMAL del USUARIO <--

    necesitaMenu();     // Verifica si se ha invocado el MENÚ.
  }
  // Revisa si existe una condición para que se active la selección del MENÚ
  if (!M.isInMenu() && !AUTO_START){
    necesitaMenu();
  }
  // Se debe ejecutar de manera normal, ¡Siempre!
  M.runMenu();
}
//==============================================================================
