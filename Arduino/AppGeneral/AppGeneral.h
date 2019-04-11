//******************************************************************************
// Archivo de cabecera para Aplicación Genérica [-----]
//******************************************************************************
#pragma once
//==============================================================================
// Resguardo para cuando se invoque más de una vez
#ifndef App02.h
#define App02.h
//==============================================================================
//-----[ ARCHIVOS OBLIGATORIOS ]-----
#include <stdint.h>         // Para poder usar diversos tipos de datos
//-----[ PLATAFORMAS de ARDUINO ]-----
#define ARDUINO_UNO   1
#define ARDUINO_MEGA  0
#define ARDUINO_NANO  0
#define ARDUINO_PRO   0
#define ARDUINO_OTRO  0
//==============================================================================
//-----[ ELEMENTOS {DES}HABILITADOS para la APLICACIÓN ]-----
#define USA_MENU     1   // Emplea "MD_Menu" para interacción con usuario
#define TIMERS       1   // Para Temporizados en la ejecución
#define PAROLA       1   // Despliegue en Matrices de LEDs 
#define LCD_I2C      1   // Pantalla de Cristal Líquido (20x4)
#define TFT          1   // Pantalla TFT, Paralelo, IL19486 /
#define fastLED      1   // Tira de LEDs WS2812
#define SONIDO       1   // Bocina para Avisos
#define I2C_PCF8254  0   // Para expansión de I/O
#define SPI_AD       0   // ¿?
#define DS3231       1   // Para RTC
#define XYZ          0   // Sensor de Distancia
#define XYZ1         0   // Sensor de Temperatura
#define XYZ2         0   // Sensor de Presencia / Ausencia
#define XYZ3         0   // Sensor de Pulso Cardíaco
#define OTRO_RECURSO 0   // Algo que se añadiera después
//==============================================================================
//-----[ DISPOSITIVOS de DESPLIEGUE / NAVEGACIÓN ]-----
// HARDWARE para el manejo del MENÚ (Elemento de SALIDA - Despliegue):
#define DISPLAY_SERIAL    0 // Monitor Serial (Pruebas)
#define DISPLAY_LCDSHIELD 1 // LCD con / sin I2C       
#define DISPLAY_PAROLA    0 // Tira(s) de Matrices de LEDs
#define DISPLAY_TFT       0 // Pantalla de TFT, 2.4" o 3.5"
//------------------------------------------------------------------------------
// HARDWARE para el manejo del MENÚ (Elemento de ENTRADA - Datos):
#define INPUT_SWITCH    0  // Interruptores mecánicos discretos
#define INPUT_TACTIL    0  // Interruptores táctiles (capacitivos)
#define INPUT_LCDSWITCH 0  // Interruptores en terminal Analógica      
#define INPUT_RENCODER  1  // Encodificador rotativo, Interruptor presión
#define INPUT_TOUCH     0  // Entrada por "Touch Screen"
//==============================================================================
//-----[ CONSTANTES que identifican RECURSOS de la APLICACIÓN ]-----
//-----[Generales]-----
const uint32_t BAUD_RATE = 115200;    // Velocidad del monitor Serial
//-----[ ESPECÍFICAS por Tipo de Tarjeta ]-----
//.....
//==============================================================================
//-----[ BIBLIOTECAS y RECURSOS de ELEMENTOS de la APLICACIÓN ]-----
//..............................................................................
#if USA_MENU
#include <MD_Menu.h>
const uint16_t MENU_TIMEOUT = 5000; // En millisegundos
const bool AUTO_START = true;       // Auto inicio del MENÚ, si está en "falso" 
                                    // EMPLEAR detección e inicio manual.
#endif
//..............................................................................
#if TIMERS
  #if ARDUINO_UNO 
const uint8_t Timer0Pin = 6;  // Terminal salida del TIMER0 [¡VERIFICAR!]
const uint8_t Timer1Pin = 7;  // Terminal salida del TIMER1
const uint8_t Timer2Pin = 8;  // Terminal salida del TIMER2
const uint8_t Timer3Pin = 9;  // Terminal salida del TIMER3
  #endif
  #if ARDUINO_MEGA 
const uint8_t Timer0Pin = 6;  // Terminal salida del TIMER0 [¡VERIFICAR!]
const uint8_t Timer1Pin = 7;  // Terminal salida del TIMER1
const uint8_t Timer2Pin = 8;  // Terminal salida del TIMER2
const uint8_t Timer3Pin = 9;  // Terminal salida del TIMER3
  #endif
  #if ARDUINO_NANO
const uint8_t Timer0Pin = 6;  // Terminal salida del TIMER0 [¡VERIFICAR!]
const uint8_t Timer1Pin = 7;  // Terminal salida del TIMER1
const uint8_t Timer2Pin = 8;  // Terminal salida del TIMER2
const uint8_t Timer3Pin = 9;  // Terminal salida del TIMER3
  #endif
#endif
//..............................................................................
#if PAROLA
// ¿#include <MD_MAX72XX.h>?
#include <MD_MAXPanel.h>
#include <MD_Parola.h>
#include <SPI.h>
#endif
//..............................................................................
#if LCD_I2C
// Definiciones LCD que se empleará en esta aplicación, con comunicación I2C:
#define  LCD_ROWS  4
#define  LCD_COLS  20
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
static LiquidCrystal_I2C lcd(0x3F, LCD_COLS, LCD_ROWS); // Otra dirección: 0x27
#endif
//..............................................................................
#if TFT
#include <Adafruit_GFX.h>     // Librería para gráficas 
#include <MCUFRIEND_kbv.h>    // Librería para la pantalla
#endif
//..............................................................................
#if fastLED
#include <FastLED.h>
#define NUM_LEDS 30
#if ARDUINO_UNO
  #define DATA_PIN 6
#elif ARDUINO_MEGA
  #define DATA_PIN 33      // ¡VERIFICAR!
#endif
#endif
//..............................................................................
#if SONIDO
#endif
//..............................................................................
#if  DS3231
#include <MD_DS3231.h>
// Selecciona el modo de operación de la librería del RTC DS3231.
// Sólo Modo Interrogatorio ("Polled Mode"), revisa retorno checkAlarm()
#define USE_POLLED      1 
// Modo Interrogatorio + "Callback". Si checkAlarm() activa, invocar "Callback"
#define USE_POLLED_CB   0 
// Interrupción externa, se debe ajustar el pin PIN_INTERRUPT para Arduino.
#define USE_INTERRUPT   0 
// Pin para manejar la Interrupción generada por el RTC DS3231.
#define PIN_INTERRUPT   2
#endif
//..............................................................................
#if OTRO_RECURSO
//... Biblioteca...
//... Terminales o Recursos Asignados ...
//... Instancia de Objetos asociados ...
//... 
#endif
//==============================================================================
// Prototipos de Funciones para Navegación / Display:
//==============================================================================
void setupDisp(void);
void setupNav(void);
bool display(MD_Menu::userDisplayAction_t, char* = nullptr);
MD_Menu::userNavAction_t navigation(uint16_t &incDelta);
//==============================================================================
// Prototipos de Funciones Variables "get / set"
//==============================================================================
// Distribuidas para simplificación de uso, podrían estar en una misma función.
MD_Menu::value_t *mnuLValueRqst(MD_Menu::mnuId_t id, bool bGet);
MD_Menu::value_t *mnuBValueRqst(MD_Menu::mnuId_t id, bool bGet);
MD_Menu::value_t *mnuIValueRqst(MD_Menu::mnuId_t id, bool bGet);
MD_Menu::value_t *mnuSerialValueRqst(MD_Menu::mnuId_t id, bool bGet);
//==============================================================================
// --> Funciones agregadas al sistema de MENÚ <---:
//==============================================================================
MD_Menu::value_t *myLEDCode(MD_Menu::mnuId_t id, bool bGet);
MD_Menu::value_t *misSensores(MD_Menu::mnuId_t id, bool bGet);
MD_Menu::value_t *misActuadores(MD_Menu::mnuId_t id, bool bGet);
//==============================================================================
#endif
//******************************************************************************
