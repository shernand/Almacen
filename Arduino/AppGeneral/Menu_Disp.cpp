//##############################################################################
#include "AppGeneral.h"
// Rutinas para el hardware de despliegue de datos específico, definiendo: 
// Archivos de encabezado específicos; Definiciones de circuitería; 
// Objetos de librería globales; Funciones "callback" para el desplegador.
//******************************************************************************
#if DISPLAY_SERIAL
// Despliega la salida de datos en un monitor serial. Útil para la depuración y 
// búsqueda de errores en la definición de la estructura del menú sin 
// interactuar con el dispositivo final.

bool display(MD_Menu::userDisplayAction_t action, char *msg){
  switch (action){
    case MD_Menu::DISP_INIT:
      Serial.begin(BAUD_RATE);
      break;
    case MD_Menu::DISP_CLEAR:
      Serial.print("\n-> CLS");
      break;
    case MD_Menu::DISP_L0:
      Serial.print("\n0> ");
      Serial.print(msg);
      break;
    case MD_Menu::DISP_L1:
      Serial.print("\n1> ");
      Serial.print(msg);
      break;
  }
  return (true);
}
#endif
//******************************************************************************
#if DISPLAY_LCDSHIELD
// Salida para una pantalla LCD de UNA, DOS o CUATRO líneas.
// --> Para una LCD de una sola línea, comentar el código que maneja L0. <--
// Antes de mostrar el mensaje que se imprime se limpia la pantalla (espacios).
// --> Se inicializa (crea OBJETO) en el archivo *.h

bool display(MD_Menu::userDisplayAction_t action, char *msg) {
  static char szLine[LCD_COLS + 1] = { '\0' };  // Para "limpieza" zona de la LCD

  switch (action) {
    case MD_Menu::DISP_INIT:
      lcd.init();
      lcd.backlight();
      lcd.clear();
      memset(szLine, ' ', LCD_COLS);
      break;
    case MD_Menu::DISP_CLEAR:
      lcd.clear();
      break;
    case MD_Menu::DISP_L0:
      lcd.setCursor(0, 0);
      lcd.print(szLine);
      lcd.setCursor(0, 0);
      lcd.print(msg);
      break;
    case MD_Menu::DISP_L1:
      lcd.setCursor(0, 1);
      lcd.print(szLine);
      lcd.setCursor(0, 1);
      lcd.print(msg);
      break;
  }
  return (true);
}
#endif
//******************************************************************************
#if DISPLAY_PAROLA
// Salida simple para una Matriz LEDs (Una línea) para la librería Parola.

#include <MD_MAX72XX.h>
#include <MD_Parola.h>
#include <SPI.h>

// Define el número de dispositivos matrices e interface de hardware.
// NOTA: Verificar que coincida el número de los pines con la circuitería. 
// Falta el tipo de display: FC16_HW, GENERIC_HW, PAROLA_HW, ICSTATION_HW
#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW 
#define MAX_DEVICES 16
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

// Conexión al SPI por Hardware:
MD_Parola P = MD_Parola(CS_PIN, MAX_DEVICES);

bool display(MD_Menu::userDisplayAction_t action, char *msg) {
  switch (action) {
    case MD_Menu::DISP_INIT:
      P.begin();
      break;
    case MD_Menu::DISP_CLEAR:
      P.displayClear();
      break;
    case MD_Menu::DISP_L0:
      // Trabajar esta parte para hacer 2 "Zonas" de desplegado, ésta es una
      // P.print(msg);    // Solamente se emplea una zona, no existe "Línea 0"
      break;
    case MD_Menu::DISP_L1:
      P.print(msg);
      break;
  }
  return (true);
}
#endif
//##############################################################################
