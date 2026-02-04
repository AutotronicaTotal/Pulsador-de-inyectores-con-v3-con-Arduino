void Presentacion_letras()
{
  lcd.begin(16, 2);  // iInit the LCD for 16 chars 2 lines
  lcd.backlight();   // Turn on the backligt (try lcd.noBaklight() to turn it off)

  //lcd.setCursor(0/*FILA*/, 0 /*COLUMNA*/);
  lcd.setCursor(0, 0); //First line
  lcd.print("   AUTOTRONICA  ");
  lcd.setCursor(0, 1); //
  lcd.print("      TOTAL     ");
  Delay(2000);
  lcd.clear();

  lcd.setCursor(1, 0); //First line
  lcd.print("LABORATORIO DE");
  lcd.setCursor(3, 1); //
  lcd.print("INYECTORES");
  Delay(2000);
  lcd.clear();
}
