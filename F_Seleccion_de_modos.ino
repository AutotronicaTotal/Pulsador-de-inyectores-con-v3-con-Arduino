int8_t Seleccion_de_modos()
{
  while (true)
  {
    bool Switch = false;
    if (VALOR == 0)
    {
      lcd.setCursor(0, 0); //First line
      //lcd.print("MODO 1 PRESIONE");
      lcd.print("   PRUEBA DE    ");
      lcd.setCursor(0, 1); //
      //lcd.print(" EL BOTON   --->");
      lcd.print("INYECCION MODO 1");
    }
    else if (VALOR == 1)
    {
      lcd.setCursor(0, 0);
      lcd.print("   PRUEBA DE    ");
      lcd.setCursor(0, 1);
      lcd.print("INYECCION MODO 2");
    }
    else if (VALOR == 2)
    {
      lcd.setCursor(0, 0);
      lcd.print("   PRUEBA DE    ");
      lcd.setCursor(0, 1);
      lcd.print("BALANCE/ROCIADA ");
    }
    
    int8_t Respaldo_VALOR = VALOR;
    while (Respaldo_VALOR == VALOR)
    {
      VALOR += Leer_encoder();
      if (digitalRead(ENCODER_SW_PIN) == LOW)
      {
        Delay(400);
        return Respaldo_VALOR;
      }
    }

    if (VALOR < 0)
      VALOR = 0;
    else if (VALOR >= 3)
      VALOR = 2;
  }
}
