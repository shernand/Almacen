#include <MD_Menu.h>
// #include "App00.h"
//******************************************************************************
//---[ Código "Callback" para atender a entrada de valores set/get del menú ]---
//******************************************************************************
// "CALLBACK" Value request callback for integers variables //
MD_Menu::value_t *mnuIValueRqst(MD_Menu::mnuId_t id, bool bGet) {
  // "id" = Ínidice de la variable accesada
  // "bGet" = Valor Booleano, "0" -> Se Seleccionó; "1" -> NO se Seleccionó
  // "vBuf.value" = Variable que RECIBE el cambio sugerido [actualizado]
  // Atiende Índices (id) del 20 al 26
  
  MD_Menu::value_t *r = &vBuf;  // VARIABLE que REGRESA el valor
                                // que se SELECCIONÓ (vBuf)
  RTC.readTime();   // SIEMPRE leer hora-tiempo-calendario para luego ajustar
  
  switch (id) {               //
    case 20:                  // 
      if (bGet) {             // SI NO se hubiera seleccionado el campo... 
        Horas = RTC.h;        //... Realiza lo siguiente...
        vBuf.value = Horas;   //...
      }
      else {                  // En caso contrario...
        Horas = vBuf.value;   // MODIFICA la variable asociada al valor
        RTC.h = Horas;        //... seleccionado
        RTC.writeTime();      //
      };
      break;
    case 21:
      if (bGet) {
        Minutos = RTC.m;
        vBuf.value = Minutos;
      }
      else {
        Minutos = vBuf.value;
        RTC.m = Minutos;
        RTC.writeTime();
      };
      break;
    case 22:
      if (bGet) {
        Segundos = RTC.s;
        vBuf.value = Segundos;
      }
      else {
        Segundos = vBuf.value;
        RTC.s = Segundos;
        RTC.writeTime();
      };
      break;
    case 23:
      if (bGet) {
        DiaSem = RTC.dow;
        vBuf.value = DiaSem;
      }
      else {
        DiaSem = vBuf.value;
        RTC.dow = DiaSem;
        RTC.writeTime();
      };
      break;
    case 24:
      if (bGet) {
        Mes = RTC.mm;
        vBuf.value = Mes;
      }
      else {
        Mes = vBuf.value;
        RTC.mm = Mes;
        RTC.writeTime();
      };
      break;
    case 25:
      if (bGet) {
        DiaMes = RTC.dd;
        vBuf.value = DiaMes;
      }
      else {
        DiaMes = vBuf.value;
        RTC.dd = DiaMes;
        RTC.writeTime();
      };
      break;
    case 26:
      if (bGet) {
        Ayo = RTC.yyyy;
        vBuf.value = Ayo;
      }
      else {
        Ayo = vBuf.value;
        RTC.yyyy = Ayo;
        RTC.writeTime();
      };
      break;
    // -----[ Contadores ]-----
    case 70:
      if (bGet) {
        vBuf.value = Contador1;
      }
      else {
        Contador1 = vBuf.value;
      };
      break;
    case 71:
      if (bGet) {
        vBuf.value = Distancia;
      }
      else {
        Distancia = vBuf.value;
      };
      break;
    case 72:
      if (bGet) {
        vBuf.value = Intensidad;
      }
      else {
        Intensidad = vBuf.value;
      };
      break;
    case 73:
      if (bGet) {
        vBuf.value = Iluminacion;
      }
      else {
        Iluminacion = vBuf.value;
      };
      break;
    case 74:
      if (bGet) {
        vBuf.value = Matiz;
      }
      else {
        Matiz = vBuf.value;
      };
      break;
    case 75:
      if (bGet) {
        vBuf.value = Sombreado;
      }
      else {
        Sombreado = vBuf.value;
      };
      break;
    case 76:
      if (bGet) {
        vBuf.value = Tonalidad;
      }
      else {
        Tonalidad = vBuf.value;
      };
      break;
    case 77:
      if (bGet) {
        vBuf.value = Transparencia;
      }
      else {
        Transparencia = vBuf.value;
      };
      break;
    case 78:
      if (bGet) {
        vBuf.value = Radio;
      }
      else {
        Radio = vBuf.value;
      };
      break;
    case 79:
      if (bGet) {
        vBuf.value = Contador2;
      }
      else {
        Contador2 = vBuf.value;
      };
      break;
    // -----
    default:
      r = nullptr;
      break;
  }
  return (r);
}
//------------------------------------------------------------------------------
MD_Menu::value_t *mnuSerialValueRqst(MD_Menu::mnuId_t id, bool bGet) {
  // "Callback" para valores índice de Listados. Los Índices deben ser GLOBALES.
  MD_Menu::value_t *r = &vBuf;
  switch (id) {
    case 30:
      if (bGet)
        vBuf.value = IndLista1;
      else {
        IndLista1 = vBuf.value;
      }
      break;
    case 31:
      if (bGet)
        vBuf.value = IndLista2;
      else {
        IndLista2 = vBuf.value;
      }
      break;
    case 32:
      if (bGet)
        vBuf.value = IndLista3;
      else {
        IndLista3 = vBuf.value;
      }
      break;
    case 33:
      if (bGet)
        vBuf.value = IndLista4;
      else {
        IndLista4 = vBuf.value;
      }
      break;
    case 34:
      if (bGet)
        vBuf.value = IndLista5;
      else {
        IndLista5 = vBuf.value;
      }
      break;
    case 35:
      if (bGet)
        vBuf.value = IndLista6;
      else {
        IndLista6 = vBuf.value;
      }
      break;
    case 36:
      if (bGet)
        vBuf.value = IndLista7;
      else {
        IndLista7 = vBuf.value;
      }
      break;
    case 37:
      if (bGet)
        vBuf.value = IndLista8;
      else {
        IndLista8 = vBuf.value;
      }
      break;
    case 38:
      if (bGet)
        vBuf.value = IndLista9;
      else {
        IndLista9 = vBuf.value;
      }
      break;
    case 39:
      if (bGet)
        vBuf.value = IndListaA;
      else {
        IndListaA = vBuf.value;
      }
      break;

    default:
      r = nullptr;
      break;
  }
  return (r);
}
//------------------------------------------------------------------------------
MD_Menu::value_t *myLEDCode(MD_Menu::mnuId_t id, bool bGet) {
  // "Callback" para ejecución de código. Aquí sólo se usa el índice.
  switch (id) {
    case 40:
      leds[0] = CRGB::Yellow;
      break;
    case 41:
      leds[0] = CRGB::Cyan;
      break;
    case 42:
      leds[0] = CRGB::White;
      break;
    case 43:
      leds[0] = CRGB::Green;
      break;
    case 44:
      leds[0] = CRGB::Red;
      break;
    // -----
    case 45:      // ERROR SIMPLE (Tratará de recuperarse...)
      do {      // AMARILLO (Parpadeo corto)
        leds[0] = CRGB::Yellow; FastLED.show(); delay(250);
        leds[0] = CRGB::Black;  FastLED.show(); delay(250);
        necesitaMenu();
      } while (navigation(dummy) != MD_Menu::NAV_SEL);
      break;
    case 46:      // ERROR GRAVE (Requiere atención para continuar...)
      do {        // ROJO (Parpadeo corto)
        leds[0] = CRGB::Red;    FastLED.show(); delay(250);
        leds[0] = CRGB::Black;  FastLED.show(); delay(250);
        necesitaMenu();
      } while (navigation(dummy) != MD_Menu::NAV_SEL);
      break;
    case 47:      // EN PROCESO (Está haciendo algo intermedio...)
      do {        // CYAN (Parpadeo medio)
        leds[0] = CRGB::Cyan;   FastLED.show(); delay(450);
        leds[0] = CRGB::Black;  FastLED.show(); delay(550);
        necesitaMenu();
      } while (navigation(dummy) != MD_Menu::NAV_SEL);
      break;
    case 48:      // EN ESPERA (Necesita datos, información...)
      do {        // AZUL (Parpadeo corto)
        leds[0] = CRGB::Blue;   FastLED.show(); delay(250);
        leds[0] = CRGB::Black;  FastLED.show(); delay(1000);
        necesitaMenu();
      } while (navigation(dummy) != MD_Menu::NAV_SEL);
      break;
    case 49:        // NORMAL (Todo bien...)
      do {          // VERDE (Parpadeo corto)
        leds[0] = CRGB::Green; FastLED.show(); delay(250);
        leds[0] = CRGB::Black;  FastLED.show(); delay(1500);
        necesitaMenu();
      } while (navigation(dummy) != MD_Menu::NAV_SEL);
      break;
    default:
      break;
  }
  FastLED.show();
  return (nullptr);
}
//------------------------------------------------------------------------------
MD_Menu::value_t *misSensores(MD_Menu::mnuId_t id, bool bGet) {
  // "Callback" para ejecución de código. Aquí sólo se usa el índice.
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("= S E N S O R E S =");
  lcd.setCursor(0, 1);

  switch (id) {
    case 50:
      lcd.print("Temperatura");
      break;
    case 51:
      lcd.print("Humedad");
      break;
    case 52:
      lcd.print("Presion");
      break;
    case 53:
      lcd.print("Velocidad");
      break;
    case 54:
      lcd.print("Posicion");
      break;
    case 55:
      lcd.print("Aceleracion");
      break;
    case 56:
      lcd.print("Iluminacion");
      break;
    case 57:
      lcd.print("Intensidal Luminosa");
      break;
    case 58:
      lcd.print("Intensidad Sonora");
      break;
    case 59:
      lcd.print("Masa");
      do {
        ;
        ;
        lcd.print("+--");
        ;
        ;
      } while (digitalRead(4) != LOW);  // Adecuar al tipo de Menú de Navegación
      // Teclado - Encoder - Analógico - Otro
      break;
    default:
      break;
  }
  lcd.setCursor(0, 3);

  for (int i = 0; i < 10; i++) {
    lcd.print(i, HEX);
    delay(100);
  }

  return (nullptr);
}
//------------------------------------------------------------------------------
// Para expander el menú. Se puede emplear para algún tipo de ensayo.
MD_Menu::value_t *misActuadores(MD_Menu::mnuId_t id, bool bGet) {

  lcd.clear();
  switch (id) {
    case 60:
      lcd.print("Ind Lista 1: ");
      lcd.print(IndLista1);
      break;
    case 61:
      lcd.print("Ind Lista 2: ");
      lcd.print(IndLista2);
      break;
    case 62:
      lcd.print("Ind Lista 3: ");
      lcd.print(IndLista3);
      break;
    case 63:
      lcd.print("Ind Lista 4: ");
      lcd.print(IndLista4);
      break;
    case 64:
      lcd.print("Ind Lista 5: ");
      lcd.print(IndLista5);
      break;
    case 65:
      lcd.print("Ind Lista 6: ");
      lcd.print(IndLista6);
      break;
    case 66:
      lcd.print("Ind Lista 7: ");
      lcd.print(IndLista7);
      break;
    case 67:
      lcd.print("Ind Lista 8: ");
      lcd.print(IndLista8);
      break;
    case 68:
      lcd.print("Ind Lista 9: ");
      lcd.print(IndLista9);
      break;
    case 69:
      lcd.print("Ind Lista A: ");
      lcd.print(IndListaA);
      do {
        lcd.print("...");
        ;
        ;
      } while (digitalRead(4) != LOW);
      break;
    default:
      break;
  }
  lcd.setCursor(0, 3);

  for (int i = 0; i < 10; i++) {
    lcd.print(i, HEX);
    delay(10);
  }

  return (nullptr);
}
//==============================================================================
