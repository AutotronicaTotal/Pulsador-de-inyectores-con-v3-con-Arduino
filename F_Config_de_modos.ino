void Config_de_modos (int8_t Valor)
{
  bool Flag_tiempo = true;
  bool Flag_ciclos = true;
  bool _ChangeRPM = false;

  //lcd.print("0123456789ABCDEF");
  if ((Valor == PRUEBA_DE_INYECCION_MODO_1))
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("> INY.ON/OFF:");
    lcd.setCursor(14, 0);
    lcd.print(PULSO);
    lcd.setCursor(15, 0);
    lcd.print("S");

    lcd.setCursor(2, 1);
    lcd.print("CICLOS:");
    lcd.setCursor(11, 1);
    lcd.print(CICLOS);

    int8_t Respaldo_PULSO = PULSO;
    while (Flag_tiempo)
    {
      PULSO += Leer_encoder();
      if (Respaldo_PULSO != PULSO)
      {
        if (PULSO < 1)
          PULSO = 1;
        else if (PULSO >= LIMITE_PULSO)
          PULSO = LIMITE_PULSO;

        lcd.setCursor(14, 0);
        lcd.print(PULSO);
        Respaldo_PULSO = PULSO;
      }
      else if (digitalRead(ENCODER_SW_PIN) == LOW)
      {
        Flag_tiempo = false;
        lcd.setCursor(0, 0);
        lcd.print(" ");
        lcd.setCursor(0, 1);
        lcd.print(">");
        Delay(400);
      }
    }

    int8_t Respaldo_CICLOS = CICLOS;
    while (Flag_ciclos)
    {
      CICLOS += Leer_encoder();
      if (Respaldo_CICLOS != CICLOS)
      {
        if (CICLOS < 1)
          CICLOS = 1;
        else if (CICLOS >= LIMITE_CICLOS)
          CICLOS = LIMITE_CICLOS;

        lcd.setCursor(11, 1);
        lcd.print("  ");
        lcd.setCursor(11, 1);
        lcd.print(CICLOS);
        Respaldo_CICLOS = CICLOS;
      }
      else if (digitalRead(ENCODER_SW_PIN) == LOW)
      {
        Delay(400);
        Flag_ciclos = false;
      }
    }
    return 0;
  }
  else if (Valor == PRUEBA_DE_INYECCION_MODO_2)
  {
    lcd.setCursor(0, 0);
    lcd.print(" SE MANTENDRAN  ");
    lcd.setCursor(0, 1);
    lcd.print("  ABIERTOS LOS  ");
    Delay(2500);

    lcd.setCursor(0, 0);
    lcd.print(" INYECTORES POR ");
    lcd.setCursor(0, 1);
    lcd.print("  15 SEGUNDOS   ");
    Delay(2500);
  }
  else if (Valor == PRUEBA_BALANCE_ROCIADA)
  {
    lcd.setCursor(0, 0);
    lcd.print(" LOS INYECTORES ");
    lcd.setCursor(0, 1);
    lcd.print("PULSARAN DURANTE");
    Delay(2500);

    lcd.setCursor(0, 0);
    lcd.print("   3 MINUTOS    ");
    lcd.setCursor(0, 1);
    lcd.print("  CONSECUTIVOS  ");
    Delay(2500);
  }
}
