/*
  CODIGO PULSADOR DE 4 INYECTORES HECHO POR MIGUEL ANGEL CRUZ ALVARO
*/

//--LIBRERIAS
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define DIRECCION_MODULO_I2C 0x27 //--
#include <timer.h>
auto timer = timer_create_default();

LiquidCrystal_I2C lcd(DIRECCION_MODULO_I2C, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
//--

//--VARIABLES
//Inyectores
const int8_t INYECTOR_1 = 3; // CAMBIEN EL 2 POR EL NUMERO DEL PIN DESEADO
const int8_t INYECTOR_2 = 5; // CAMBIEN EL 3 POR EL NUMERO DEL PIN DESEADO
const int8_t INYECTOR_3 = 6; // CAMBIEN EL 4 POR EL NUMERO DEL PIN DESEADO
const int8_t INYECTOR_4 = 9; // CAMBIEN EL 5 POR EL NUMERO DEL PIN DESEADO
//Encoder
const int8_t ENCODER_DT_PIN = 11;
const int8_t ENCODER_CLK_PIN = 10;
const int8_t ENCODER_SW_PIN = 12;
//Generales
#define PRUEBA_DE_INYECCION_MODO_1 0
#define PRUEBA_DE_INYECCION_MODO_2 1
#define PRUEBA_BALANCE_ROCIADA 2

int8_t VALOR = 0;
int PULSO = 0;
int8_t LIMITE_PULSO = 0;
int8_t CICLOS = 0;
int8_t LIMITE_CICLOS = 0;
int8_t GUARDA_CICLOS = 0;

int8_t GUARDA_CICLOS_2 = 0;

int RPM = 0;
int PWM = 0;
float f_PWM = 0;

unsigned long ul_PREVIUS_TIME_DELAY = 0;
unsigned long ul_PREVIUS_TIME_DELAY_1 = 0;

void setup()
{
  VALOR = PRUEBA_DE_INYECCION_MODO_1;
  PULSO = 1;
  LIMITE_PULSO = 5; //MOVER AQUI PARA AJUSTAR EL VALOR MAXIMO DE DURACIÓN DE LOS PULSOS EN ON Y OFF
  CICLOS = 1;
  LIMITE_CICLOS = 20; //MOVER AQUI PARA AJUSTAR EL VALOR MAXIMO DE DURACIÓN DE LOS CICLOS QUE SE REPETIRAN
  GUARDA_CICLOS = 0;

  GUARDA_CICLOS_2 = 0;

  RPM = 1500;
  PWM = 10000;
  f_PWM = PWM / 1000.0;

  //Aqui empieza la secuencia de codigo
  Declaracion_de_pines();
  Presentacion_letras();
  VALOR = Seleccion_de_modos();
  Config_de_modos(VALOR);
  Pantalla_de_cuenta_regresiva();
  LCD_Correr_Modulos();

  if (VALOR == PRUEBA_DE_INYECCION_MODO_1)
    PULSO *= 1000;
}

void loop()
{

  while ((VALOR == PRUEBA_DE_INYECCION_MODO_1) && (GUARDA_CICLOS <= CICLOS))
  {
    digitalWrite(INYECTOR_1, HIGH);
    digitalWrite(INYECTOR_2, HIGH);
    digitalWrite(INYECTOR_3, HIGH);
    digitalWrite(INYECTOR_4, HIGH);
    Delay_prueba_de_inyeccion_modo_1(PULSO);
    digitalWrite(INYECTOR_1, LOW);
    digitalWrite(INYECTOR_2, LOW);
    digitalWrite(INYECTOR_3, LOW);
    digitalWrite(INYECTOR_4, LOW);
    Delay_prueba_de_inyeccion_modo_1(PULSO);

    GUARDA_CICLOS++;
    lcd.setCursor(14, 1);
    lcd.print("  ");
    lcd.setCursor(14, 1);
    lcd.print(CICLOS - GUARDA_CICLOS);

    if (GUARDA_CICLOS >= CICLOS)
    {
      lcd.clear();
      lcd.setCursor(5, 0); //First line
      lcd.print("CICLO");
      lcd.setCursor(3, 1); //First line
      lcd.print("FINALIZADO");
      Delay(3000);
      setup();
    }
  }

  while (VALOR == PRUEBA_DE_INYECCION_MODO_2)
  {
    digitalWrite(INYECTOR_1, HIGH);
    digitalWrite(INYECTOR_2, HIGH);
    digitalWrite(INYECTOR_3, HIGH);
    digitalWrite(INYECTOR_4, HIGH);
    Delay_prueba_de_inyeccion_modo_2(1000);
    GUARDA_CICLOS_2++;

    lcd.setCursor(13, 1);
    lcd.print("  ");
    lcd.setCursor(13, 1);
    lcd.print(15 - GUARDA_CICLOS_2);

    if (GUARDA_CICLOS_2 >= 15)
    {
      digitalWrite(INYECTOR_1, LOW);
      digitalWrite(INYECTOR_2, LOW);
      digitalWrite(INYECTOR_3, LOW);
      digitalWrite(INYECTOR_4, LOW);

      lcd.clear();
      lcd.setCursor(5, 0); //First line
      lcd.print("CICLO");
      lcd.setCursor(3, 1); //First line
      lcd.print("FINALIZADO");
      Delay(3000);
      setup();
    }
  }

  while (VALOR == PRUEBA_BALANCE_ROCIADA)
  {
    int final_ascendete = 200;
    int resta_ascendente = 2;
    for (int x = 0; x < 100; x++)
    {
      final_ascendete = (final_ascendete - resta_ascendente);

      for (int z = 0; z < 2; z++)
      {
        digitalWrite(INYECTOR_1, HIGH);
        delay(2);
        digitalWrite(INYECTOR_1, LOW);
        delay(final_ascendete);

        digitalWrite(INYECTOR_2, HIGH);
        delay(2);
        digitalWrite(INYECTOR_2, LOW);
        delay(final_ascendete);

        digitalWrite(INYECTOR_3, HIGH);
        delay(2);
        digitalWrite(INYECTOR_3, LOW);
        delay(final_ascendete);

        digitalWrite(INYECTOR_4, HIGH);
        delay(2);
        digitalWrite(INYECTOR_4, LOW);
        delay(final_ascendete);
      }
    }

    for (int y = 0; y < 1000; y++)
    {
      digitalWrite(INYECTOR_1, HIGH);
      delay(2);
      digitalWrite(INYECTOR_1, LOW);
      delay(2);

      digitalWrite(INYECTOR_2, HIGH);
      delay(2);
      digitalWrite(INYECTOR_2, LOW);
      delay(2);

      digitalWrite(INYECTOR_3, HIGH);
      delay(2);
      digitalWrite(INYECTOR_3, LOW);
      delay(2);

      digitalWrite(INYECTOR_4, HIGH);
      delay(2);
      digitalWrite(INYECTOR_4, LOW);
      delay(2);
    }

    int final_descendete = 0;
    int resta_descendente = 2;
    for (int x = 0; x < 100; x++)
    {
      final_descendete = (final_descendete + resta_descendente);

      for (int z = 0; z < 2; z++)
      {
        digitalWrite(INYECTOR_1, HIGH);
        delay(2);
        digitalWrite(INYECTOR_1, LOW);
        delay(final_descendete);

        digitalWrite(INYECTOR_2, HIGH);
        delay(2);
        digitalWrite(INYECTOR_2, LOW);
        delay(final_descendete);

        digitalWrite(INYECTOR_3, HIGH);
        delay(2);
        digitalWrite(INYECTOR_3, LOW);
        delay(final_descendete);

        digitalWrite(INYECTOR_4, HIGH);
        delay(2);
        digitalWrite(INYECTOR_4, LOW);
        delay(final_descendete);
      }
    }
    lcd.clear();
    lcd.setCursor(5, 0); //First line
    lcd.print("CICLO");
    lcd.setCursor(3, 1); //First line
    lcd.print("FINALIZADO");
    Delay(3000);
    setup();
  }
}
