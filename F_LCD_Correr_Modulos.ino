void LCD_Correr_Modulos(void)
{
  if (VALOR == PRUEBA_DE_INYECCION_MODO_1)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("INYECCION MODO 1");
    lcd.setCursor(0, 1);
    lcd.print("SEG.");
    lcd.setCursor(5, 1);
    lcd.print(PULSO);
    lcd.setCursor(7, 1);
    lcd.print("CICLO:");
    lcd.setCursor(14, 1);
    lcd.print(CICLOS - GUARDA_CICLOS);
  }
  else if (VALOR == PRUEBA_DE_INYECCION_MODO_2)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("INYECCION MODO 2");
    lcd.setCursor(0, 1);
    lcd.print("FINALIZA EN: 15 ");
  }
  else if (VALOR == PRUEBA_BALANCE_ROCIADA)
  {    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  APERTURA DEL  ");
    lcd.setCursor(0, 1);
    lcd.print("INYECTOR EN 2 mS");
  }
}
