//##############################################################################
#include "AppGeneral.h"
// Rutinas para circuitería específica para dispositivos de navegación
// (introducción de datos para indicaciones de acciones en la selección del
// menú), definiendo: Archivos de encabezados; Definciones de circuitería;
// Objetos de librerías globales; Funciones de "callback" de navegación.
//==============================================================================
#if INPUT_SWITCH
// Implementación de 3 interruptores momentaneos, uno para INCrementos, otro
// para DECrementos, otro para la SELección (un "click") y uno final para el
// ESCape ("presionado largo").
//------------------------------------------------------------------------------
#include <MD_UISwitch.h>
const uint8_t INC_PIN = 2;
const uint8_t DEC_PIN = 3;
const uint8_t CTL_PIN = 4;
const uint8_t ESC_PIN = 5;  // Agregado, mejora el acceso al teclado básico.
uint8_t pins[] = {INC_PIN, DEC_PIN, CTL_PIN, ESC_PIN}; // Arreglo Interruptores

MD_UISwitch_Digital swNav(pins, ARRAY_SIZE(pins), LOW); // "swNav" == Todos
void setupNav(void) {                                   // los Interruptores
  swNav.begin();              //... Inciados
  swNav.enableRepeat(false);  //... Sin Repeticiones 
}
//-----[ RUTINA para LECTURA de la NAVEGACIÓN ]-----
MD_Menu::userNavAction_t navigation(uint16_t &incDelta) {
  MD_Menu::userNavAction_t nav = MD_Menu::NAV_NULL; // Variable "nav" regresa el
                                                    // "COMANDO de Navegación"
  switch (swNav.read()) {             // Verificar si no debiera ser:
    case MD_UISwitch::KEY_PRESS: {    // "case MD_UISwitch::KEY_LONGPRESS:"
        Serial.print(swNav.getKey()); // Lectura de la tecla
        switch (swNav.getKey()) {     // Verifica cuál tecla se leyó
          // Versión MD_UISwitch [ACTUAL], se analiza el valor del "pin":
          case INC_PIN: nav = MD_Menu::NAV_INC; break;
          case DEC_PIN: nav = MD_Menu::NAV_DEC; break;
          case CTL_PIN: nav = MD_Menu::NAV_SEL; break;
          case ESC_PIN: nav = MD_Menu::NAV_ESC; break;
        }
      }
      break;
  }
  incDelta = 1;
  return (nav);
}
#endif
//------------------------------------------------------------------------------
#if INPUT_LCDSWITCH
// Empleo de interruptores momentáneos encontrados en "LCD shield". Las teclas
// "up" y "down" se asocian con INC y DEC, mientras "izquierda" y "derecha"
// se asocian a ESC y SEL.
//------------------------------------------------------------------------------
#include <MD_UISwitch.h>

#define LCD_KEYS_PIN A0

// Estos valores funcionan para la mayoría de los casos:
MD_UISwitch_Analog::uiAnalogKeys_t kt[] = {
  {  10, 10, 'R' },  // Derecha
  { 140, 15, 'U' },  // Arriba
  { 315, 15, 'D' },  // Abajo
  { 490, 15, 'L' },  // Izquierda
  { 725, 15, 'S' },  // Selecciona
};

MD_UISwitch_Analog lcdKeys(LCD_KEYS_PIN, kt, ARRAY_SIZE(kt));

void setupNav(void) {
  lcdKeys.begin();
}
//-----[ RUTINA para LECTURA de la NAVEGACIÓN ]-----
MD_Menu::userNavAction_t navigation(uint16_t &incDelta) {
  incDelta = 1;
  if (lcdKeys.read() == MD_UISwitch::KEY_PRESS)
  {
    switch (lcdKeys.getKey())
    {
      case 'D': return (MD_Menu::NAV_DEC);
      case 'U': return (MD_Menu::NAV_INC);
      case 'R': return (MD_Menu::NAV_SEL);
      case 'S':
      case 'L': return (MD_Menu::NAV_ESC);
    }
  }
  return (MD_Menu::NAV_NULL);
}
#endif
//------------------------------------------------------------------------------
#if INPUT_RENCODER
// Implementado con encodificador rotativo e interruptor de presión integrado.
// Una rotación en el sentido horario, INC; en sentido contrario a DEC.
// Presionando interruptor central equivale a SEL ("press") o ESC ("long press").
//
// Si se estuviera editando un valor, el encodificador rotatorio también
// aplicará un factor de que que tan rápido es rotado para incrementar la tasa
// de variación del cambio del valor. Esto aplicará en entradas numéricas.

#include <MD_REncoder.h>
#include <MD_UISwitch.h>

extern MD_Menu M;

const uint8_t RE_A_PIN = 2;
const uint8_t RE_B_PIN = 3;
const uint8_t CTL_PIN = 4;
const uint8_t ESC_PIN = 5;  // Agregado, mejora el acceso al teclado básico.

uint8_t pins[] = {CTL_PIN, ESC_PIN};

MD_REncoder  RE(RE_A_PIN, RE_B_PIN);
MD_UISwitch_Digital swNav(pins, ARRAY_SIZE(pins), LOW);

void setupNav(void) {
  RE.begin();
  swNav.begin();
  swNav.enableRepeat(false);
  swNav.setPressTime(150);
  swNav.setLongPressTime(600);

  /*
const uint16_t KEY_PRESS_TIME = 150;    //Default key press [milliseconds]
const uint16_t KEY_DPRESS_TIME = 250;   //Default double press [milliseconds]
const uint16_t KEY_LONGPRESS_TIME = 600;  //Default long press [milliseconds]
const uint16_t KEY_REPEAT_TIME = 300;   //Default between repeats [milliseconds]
const uint8_t  KEY_ACTIVE_STATE = LOW;  ///
   */
}
//-----[ RUTINA para LECTURA de la NAVEGACIÓN ]-----
MD_Menu::userNavAction_t navigation(uint16_t &incDelta) {
  MD_Menu::userNavAction_t nav = MD_Menu::NAV_NULL;
  uint8_t re = RE.read();

  if (re != DIR_NONE) {
    incDelta = (M.isInEdit() ? (1 << abs(RE.speed() / 10)) : 1);
    return (re == DIR_CCW ? MD_Menu::NAV_DEC : MD_Menu::NAV_INC);
  }

  switch (swNav.read()) {
    case MD_UISwitch::KEY_LONGPRESS: {
        Serial.print(swNav.getKey());
        switch (swNav.getKey()) {
          case CTL_PIN: nav = MD_Menu::NAV_SEL; break;
          case ESC_PIN: nav = MD_Menu::NAV_ESC; break;
        }
      }
      break;
  }
  return (nav);
}
#endif
//##############################################################################
