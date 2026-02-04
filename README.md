# Pulsador-de-inyectores-con-v3-con-ArduinoEste proyecto es para realizar el pulsador de inyectores utilizando un arduino nano y transistores, el pulsador de inyectores cuenta con 3 modos de operación básicos, este pulsador de inyectores fue hecho con la colaboracion de mi amigo Jonathan Nuno.

1. MODO 1:
  INY.ON/OFF: 1S:
    Aqui se configura cuantos segundos durara el inyector abierto y cuantos segundos durar cerrado, el tiempo minimo es de 1 segundo y el maximo es de 5 segundos, el tiempo que      se coloque sera el mismo para inyector abierto e inyector cerrado.
  CILOS: 1:
    Aqui se configura cuantas ciclos realizara la apertura y cierra de los inyectores.

2. MODO 2:
   En este modo los inyectores se mantendran abiertos por 15 segundos y despues se cerraran.

3. MODO 3:
  PRUEBA DE BALANCE/ROCIADA:
    Este modo de funcionamiento hace pulsar a los inyectores de forma consecutiva del 1 al 4. El tiempo de apetura de cada inyector es fijo y es de 2 milisegundos, lo que cambia     es el tiempo de cierre que inicia con 1 segundo y va reduciendose hasta quedar en 2 milisegundos de cierre, este proceso toma como 3 minutos de funcionamiento.

Al finalizar cada modo de operacion el arduino se resetea y vuelve a iniciar desde el principio del programa.

MATERIALES
1 arduino uno/nano
1 pantalla lcd 16x2 con i2c
1 encoder rotativo ky040 para arduino
Etapa de potencia con 4 transistores (en esta parte hay bastantes materiales pero estan en el diagrama, ahi los pueden sacar)

De igual forma se sube el codigo fuente y las librerias que son necesarias para poder hacerlo funcionar.
Aqui puedes ver el video del funcionamiento:
https://youtu.be/xQ3hgYKpZLE
