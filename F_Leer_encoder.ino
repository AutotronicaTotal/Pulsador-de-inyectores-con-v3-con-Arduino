int Leer_encoder()
{
  static int oldA = HIGH; 
  static int oldB = HIGH;
  int8_t result = 0;
  int8_t newA = digitalRead(ENCODER_CLK_PIN);
  int8_t newB = digitalRead(ENCODER_DT_PIN);
  if (newA != oldA || newB != oldB)
  {
    // something has changed
    if (oldA == HIGH && newA == LOW)
    {
      result = (oldB * 2 - 1);
    }
  }
  oldA = newA;
  oldB = newB;
  return result;
}
