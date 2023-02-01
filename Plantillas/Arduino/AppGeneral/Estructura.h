// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//-----[ ENCABEZADOS del MENÚ ]-----
const PROGMEM MD_Menu::mnuHeader_t mnuHdr[] = {
  // Letrero que se muestra al presionar SELect
  { 10, "M E N U",  10, 15, 0 },  // Direcciona a: -[ ELEMENTOS del MENÚ ]- [15]
  // ENCABEZADOS del MENÚ RAÍZ (Principales)
  { 11, "RELOJ",    20, 26, 0 },  // Reloj de Tiempo Real - Hora - Min ...
  { 12, "LISTAS",   30, 39, 0 },  // Listas de Opciones
  { 13, "LEDs",     40, 49, 0 },  // Acciones Directas con Salidas
  { 14, "SENSORES", 50, 59, 0 },  // Acciones de Toma de Datos
  { 15, "VaLoReS",  60, 69, 0 },  // Para verificar Índices de Listas
  { 16, "DaToS",    70, 79, 0 },  // Entradas de Datos Numéricos
};
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//-----[ ELEMENTOS del MENÚ ]----- Menu Items -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const PROGMEM MD_Menu::mnuItem_t mnuItm[] = {
  // INICIO del MENÚ Raíz (Principales Opciones de Selección)
  { 10, "RTC",          MD_Menu::MNU_MENU, 11 },  // Salta a sección anterior.
  { 11, "LISTADOS",     MD_Menu::MNU_MENU, 12 },  // Encabezados de las... 
  { 12, "LED's",        MD_Menu::MNU_MENU, 13 },  // ...Opciones que se...
  { 13, "SENSORES",     MD_Menu::MNU_MENU, 14 },  // ...emplean.
  { 14, "MONITOR",      MD_Menu::MNU_MENU, 15 },  // 
  { 15, "DATOS",        MD_Menu::MNU_MENU, 16 },  // 
  //................................................
  // Entrada de DATOS de SUB-MENÚS ->  "RELOJ"
  //................................................
  { 20, "Horas",      MD_Menu::MNU_INPUT, 20 }, //
  { 21, "Minutos",    MD_Menu::MNU_INPUT, 21 }, // 
  { 22, "Segundos",   MD_Menu::MNU_INPUT, 22 }, // 
  { 23, "Dia - Sem",  MD_Menu::MNU_INPUT, 23 }, // 
  { 24, "Mes",        MD_Menu::MNU_INPUT, 24 }, // 
  { 25, "Dia - Mes",  MD_Menu::MNU_INPUT, 25 }, // 
  { 26, "A#o",        MD_Menu::MNU_INPUT, 26 }, // 
  //................................................
  // Entrada de DATOS de SUB-MENÚS ->  "Listados"
  //................................................
  { 30, "Lista - 01", MD_Menu::MNU_INPUT, 30 },
  { 31, "Lista - 02", MD_Menu::MNU_INPUT, 31 },
  { 32, "Lista - 03", MD_Menu::MNU_INPUT, 32 },
  { 33, "Lista - 04", MD_Menu::MNU_INPUT, 33 },
  { 34, "Lista - 05", MD_Menu::MNU_INPUT, 34 },
  { 35, "Lista - 06", MD_Menu::MNU_INPUT, 35 },
  { 36, "Lista - 07", MD_Menu::MNU_INPUT, 36 },
  { 37, "Lista - 08", MD_Menu::MNU_INPUT, 37 },
  { 38, "Lista - 09", MD_Menu::MNU_INPUT, 38 },
  { 39, "Lista - 0A", MD_Menu::MNU_INPUT, 39 },
  //................................................
  // Entrada de DATOS de SUB-MENÚS ->  "LED's"
  //................................................
  { 40, "Amarillo",     MD_Menu::MNU_INPUT, 40 },
  { 41, "Cyan",         MD_Menu::MNU_INPUT, 41 },
  { 42, "Blanco",       MD_Menu::MNU_INPUT, 42 },
  { 43, "Verde",        MD_Menu::MNU_INPUT, 43 },
  { 44, "Rojo",         MD_Menu::MNU_INPUT, 44 },
  { 45, "ERROR SIMPLE", MD_Menu::MNU_INPUT, 45 },
  { 46, "ERROR GRAVE",  MD_Menu::MNU_INPUT, 46 },
  { 47, "EN PROCESO",   MD_Menu::MNU_INPUT, 47 },
  { 48, "EN ESPERA",    MD_Menu::MNU_INPUT, 48 },
  { 49, "NORMAL",       MD_Menu::MNU_INPUT, 49 },
  //................................................
  // Entrada de DATOS de SUB-MENÚS ->  "SENSORES"
  //................................................
  { 50, "Temperatura",  MD_Menu::MNU_INPUT, 50 },
  { 51, "Humedad",      MD_Menu::MNU_INPUT, 51 },
  { 52, "Presion",      MD_Menu::MNU_INPUT, 52 },
  { 53, "Velocidad",    MD_Menu::MNU_INPUT, 53 },
  { 54, "Posicion",     MD_Menu::MNU_INPUT, 54 },
  { 55, "Aceleracion",  MD_Menu::MNU_INPUT, 55 },
  { 56, "Iluminacion",  MD_Menu::MNU_INPUT, 56 },
  { 57, "Intensidad L", MD_Menu::MNU_INPUT, 57 },
  { 58, "Intensidad S", MD_Menu::MNU_INPUT, 58 },
  { 59, "Masa",         MD_Menu::MNU_INPUT, 59 },

  { 60, "Lista 1",  MD_Menu::MNU_INPUT, 60 },
  { 61, "Lista 2",  MD_Menu::MNU_INPUT, 61 },
  { 62, "Lista 3",  MD_Menu::MNU_INPUT, 62 },
  { 63, "Lista 4",  MD_Menu::MNU_INPUT, 63 },
  { 64, "Lista 5",  MD_Menu::MNU_INPUT, 64 },
  { 65, "Lista 6",  MD_Menu::MNU_INPUT, 65 },
  { 66, "Lista 7",  MD_Menu::MNU_INPUT, 66 },
  { 67, "Lista 8",  MD_Menu::MNU_INPUT, 67 },
  { 68, "Lista 9",  MD_Menu::MNU_INPUT, 68 },
  { 69, "Lista A",  MD_Menu::MNU_INPUT, 69 },

  { 70, "Contador 1",     MD_Menu::MNU_INPUT, 70 },
  { 71, "Distancia",      MD_Menu::MNU_INPUT, 71 },
  { 72, "Intensidad",     MD_Menu::MNU_INPUT, 72 },
  { 73, "Iluminacion",    MD_Menu::MNU_INPUT, 73 },
  { 74, "Matiz",          MD_Menu::MNU_INPUT, 74 },
  { 75, "Sombreado",      MD_Menu::MNU_INPUT, 75 },
  { 76, "Tonalidad",      MD_Menu::MNU_INPUT, 76 },
  { 77, "Transparencia",  MD_Menu::MNU_INPUT, 77 },
  { 78, "Radio",          MD_Menu::MNU_INPUT, 78 },
  { 79, "Contador 2",     MD_Menu::MNU_INPUT, 79 },
};
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Elementos (Items) de Entrada para LISTAS ---------
const PROGMEM char list01[] = "COM1|COM2|COM3|COM4|COM5|COM6|COM7";
const PROGMEM char list02[] = "Der|Izq|Arr|Aba|Par|Ini|Son";
const PROGMEM char list03[] = "S|E|R|G|I|O|-|M|I|C|R|O|S|*";
const PROGMEM char list04[] = "SI|NO";
const PROGMEM char list05[] = "Velocidad|Posicion|Masa|Sonido|Musica|Temperatura";
const PROGMEM char list06[] = "0|1|2|3|4|5|6|7|8|9|A|B|C|D|E|F";
const PROGMEM char list07[] = "A|I|D";
const PROGMEM char list08[] = "SI|NO|??|!!|**";
const PROGMEM char list09[] = "57|25|36|17|61|30|45";
const PROGMEM char list0A[] = "PIC|AVR|TTL|CMOS|RTL|VHDL|RF|RAD|FAB|OSC";
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const PROGMEM MD_Menu::mnuInput_t mnuInp[] = {

  { 20, "Horas",    MD_Menu::INP_INT, mnuIValueRqst,    2,    0, 0,   23, 0, 10, nullptr }, 
  { 21, "Minutos",  MD_Menu::INP_INT, mnuIValueRqst,    2,    0, 0,   59, 0, 10, nullptr },
  { 22, "Segundos", MD_Menu::INP_INT, mnuIValueRqst,    2,    0, 0,   59, 0, 10, nullptr },
  { 23, "Dia Sem",  MD_Menu::INP_INT, mnuIValueRqst,    2,    1, 0,    7, 0, 10, nullptr },
  { 24, "Mes",      MD_Menu::INP_INT, mnuIValueRqst,    2,    1, 0,   12, 0, 10, nullptr },
  { 25, "Dia Mes",  MD_Menu::INP_INT, mnuIValueRqst,    2,    1, 0,   31, 0, 10, nullptr },
  { 26, "A#o",      MD_Menu::INP_INT, mnuIValueRqst,    4, 2018, 0, 2020, 0, 10, nullptr },

  { 30, "COM ->",  MD_Menu::INP_LIST, mnuSerialValueRqst, 4, 0, 0, 0, 0, 0, list01 },
  { 31, "Dir ->",  MD_Menu::INP_LIST, mnuSerialValueRqst, 3, 0, 0, 0, 0, 0, list02 },
  { 32, "Let ->",  MD_Menu::INP_LIST, mnuSerialValueRqst, 1, 0, 0, 0, 0, 0, list03 },
  { 33, "Opc ->",  MD_Menu::INP_LIST, mnuSerialValueRqst, 2, 0, 0, 0, 0, 0, list04 },
  { 34, "Sen ->",  MD_Menu::INP_LIST, mnuSerialValueRqst, 11, 0, 0, 0, 0, 0, list05 },
  { 35, "Num ->",  MD_Menu::INP_LIST, mnuSerialValueRqst, 1, 0, 0, 0, 0, 0, list06 },
  { 36, "Alt ->",  MD_Menu::INP_LIST, mnuSerialValueRqst, 1, 0, 0, 0, 0, 0, list07 },
  { 37, "Pre ->",  MD_Menu::INP_LIST, mnuSerialValueRqst, 2, 0, 0, 0, 0, 0, list08 },
  { 38, "Dig ->",  MD_Menu::INP_LIST, mnuSerialValueRqst, 2, 0, 0, 0, 0, 0, list09 },
  { 39, "Mic ->",  MD_Menu::INP_LIST, mnuSerialValueRqst, 4, 0, 0, 0, 0, 0, list0A },
  // Lo siguiente se prueba usando el ÍNDICE de cada selección: 
  { 40, "Listo", MD_Menu::INP_RUN, myLEDCode, 0, 0, 0, 0, 0, 10, nullptr },
  { 41, "Listo", MD_Menu::INP_RUN, myLEDCode, 0, 0, 0, 0, 0, 10, nullptr },
  { 42, "Listo", MD_Menu::INP_RUN, myLEDCode, 0, 0, 0, 0, 0, 10, nullptr },
  { 43, "Listo", MD_Menu::INP_RUN, myLEDCode, 0, 0, 0, 0, 0, 10, nullptr },
  { 44, "Listo", MD_Menu::INP_RUN, myLEDCode, 0, 0, 0, 0, 0, 10, nullptr },
  { 45, "Listo", MD_Menu::INP_RUN, myLEDCode, 0, 0, 0, 0, 0, 10, nullptr },
  { 46, "Listo", MD_Menu::INP_RUN, myLEDCode, 0, 0, 0, 0, 0, 10, nullptr },
  { 47, "Listo", MD_Menu::INP_RUN, myLEDCode, 0, 0, 0, 0, 0, 10, nullptr },
  { 48, "Listo", MD_Menu::INP_RUN, myLEDCode, 0, 0, 0, 0, 0, 10, nullptr },
  { 49, "Listo", MD_Menu::INP_RUN, myLEDCode, 0, 0, 0, 0, 0, 10, nullptr },
  
  { 50, "", MD_Menu::INP_RUN, misSensores, 0, 0, 0, 0, 0, 10, nullptr },
  { 51, "", MD_Menu::INP_RUN, misSensores, 0, 0, 0, 0, 0, 10, nullptr },
  { 52, "", MD_Menu::INP_RUN, misSensores, 0, 0, 0, 0, 0, 10, nullptr },
  { 53, "", MD_Menu::INP_RUN, misSensores, 0, 0, 0, 0, 0, 10, nullptr }, 
  { 54, "", MD_Menu::INP_RUN, misSensores, 0, 0, 0, 0, 0, 10, nullptr },
  { 55, "", MD_Menu::INP_RUN, misSensores, 0, 0, 0, 0, 0, 10, nullptr },
  { 56, "", MD_Menu::INP_RUN, misSensores, 0, 0, 0, 0, 0, 10, nullptr }, 
  { 57, "", MD_Menu::INP_RUN, misSensores, 0, 0, 0, 0, 0, 10, nullptr },
  { 58, "", MD_Menu::INP_RUN, misSensores, 0, 0, 0, 0, 0, 10, nullptr },
  { 59, "", MD_Menu::INP_RUN, misSensores, 0, 0, 0, 0, 0, 10, nullptr },
  
  { 60, "", MD_Menu::INP_RUN, misActuadores, 0, 0, 0, 0, 0, 10, nullptr },
  { 61, "", MD_Menu::INP_RUN, misActuadores, 0, 0, 0, 0, 0, 10, nullptr },
  { 62, "", MD_Menu::INP_RUN, misActuadores, 0, 0, 0, 0, 0, 10, nullptr },
  { 63, "", MD_Menu::INP_RUN, misActuadores, 0, 0, 0, 0, 0, 10, nullptr },
  { 64, "", MD_Menu::INP_RUN, misActuadores, 0, 0, 0, 0, 0, 10, nullptr },
  { 65, "", MD_Menu::INP_RUN, misActuadores, 0, 0, 0, 0, 0, 10, nullptr },
  { 66, "", MD_Menu::INP_RUN, misActuadores, 0, 0, 0, 0, 0, 10, nullptr },
  { 67, "", MD_Menu::INP_RUN, misActuadores, 0, 0, 0, 0, 0, 10, nullptr },
  { 68, "", MD_Menu::INP_RUN, misActuadores, 0, 0, 0, 0, 0, 10, nullptr },
  { 69, "", MD_Menu::INP_RUN, misActuadores, 0, 0, 0, 0, 0, 10, nullptr },

  { 70, "Contador 1",     MD_Menu::INP_INT, mnuIValueRqst,    2,    0, 0,   99, 0, 10, nullptr }, 
  { 71, "Distancia",      MD_Menu::INP_INT, mnuIValueRqst,    3,    0, 0,  999, 0, 10, nullptr },
  { 72, "Intensidad",     MD_Menu::INP_INT, mnuIValueRqst,    3,  100, 0,  700, 0, 10, nullptr },
  { 73, "Iluminacion",    MD_Menu::INP_INT, mnuIValueRqst,    2,   20, 0,   90, 0, 10, nullptr },
  { 74, "Matiz",          MD_Menu::INP_INT, mnuIValueRqst,    1,    1, 0,   99, 0, 10, nullptr },
  { 75, "Sombreado",      MD_Menu::INP_INT, mnuIValueRqst,    2,    1, 0,   50, 0, 10, nullptr },
  { 76, "Tonalidad",      MD_Menu::INP_INT, mnuIValueRqst,    2,   45, 0,   75, 0, 10, nullptr },
  { 77, "Transparencia",  MD_Menu::INP_INT, mnuIValueRqst,    2,    1, 0,   12, 0, 10, nullptr },
  { 78, "Radio",          MD_Menu::INP_INT, mnuIValueRqst,    3,    1, 0,  999, 0, 10, nullptr },
  { 79, "Contador 2",     MD_Menu::INP_INT, mnuIValueRqst,    4,    0, 0,  500, 0, 16, nullptr },

};
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
