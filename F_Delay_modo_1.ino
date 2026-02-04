void Delay_prueba_de_inyeccion_modo_1(int i_tiempo)
{
  bool Start = false;
  ul_PREVIUS_TIME_DELAY = millis();

  while ((millis() - ul_PREVIUS_TIME_DELAY) < i_tiempo)
  {
    if ((digitalRead(ENCODER_SW_PIN) == LOW) && (Start == false))
    {
      Start = true;
      Delay(350);//delay
    }
    else if ((digitalRead(ENCODER_SW_PIN) == HIGH) && (Start == true))
    {
      ul_PREVIUS_TIME_DELAY = millis();
    }
    else if ((digitalRead(ENCODER_SW_PIN) == LOW) && (Start == true))
    {
      Start = false;
      Delay(350);
    }
  }
}
