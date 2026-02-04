void Delay_prueba_de_inyeccion_modo_2(int i_tiempo)
{
  ul_PREVIUS_TIME_DELAY = millis();

  while ((millis() - ul_PREVIUS_TIME_DELAY) < i_tiempo)
  {
    ;
  }
}
