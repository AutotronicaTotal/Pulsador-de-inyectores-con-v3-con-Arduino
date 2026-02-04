void Declaracion_de_pines()
{
  pinMode(INYECTOR_1, OUTPUT);
  pinMode(INYECTOR_2, OUTPUT);
  pinMode(INYECTOR_3, OUTPUT);
  pinMode(INYECTOR_4, OUTPUT);
  pinMode(13, OUTPUT);

  pinMode(ENCODER_CLK_PIN, INPUT_PULLUP);
  pinMode(ENCODER_DT_PIN, INPUT_PULLUP);
  pinMode(ENCODER_SW_PIN, INPUT_PULLUP);
}
