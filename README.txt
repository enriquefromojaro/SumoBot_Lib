# SumoBot_Lib
SumoBot-Lib
Librería pensada para el taller de Sumobot de 2014-2015 de AETEL en el Campus Sur.
Permite programar el robot a través de objetos, evitando tener que pensar cómocodificar cosas básicas
  Ejemplo:
    puedes poner esto:
      dist.distance();
    En lugar de esto:
      16746.73 * float(pow(analogRead(pin),-1.2134));
NOTA: Falta por comentar, porbar a fondo, ejemplos y unas cuantas cosillas, cuando pueda las añadiré y lo mejoraré

ACTUALIZACIÓN 17/1/2015
--------------------------
- Añadida la clase Led para manejarlo (está comentada)

- Los métodos analogVoltage y digitalVoltage de las clases DistanceSensor y LightSensor ahora se llaman anRead y digRead,
respectivamente para mayor claridad (no se puede poner digitalRead ni analogRead porque se confunde con los comandos de arduino
dentro de los metodos)

- Añadidos los pines del SumoBot según el manual (a falta de comprobar) en la clase SumoBot. Falta que la clase SumoBot
pueda manejar objetos de las clases de los componentes

- El exponente y el coeficiente del sensor de distancia se pueden configurar

NOTA: Para añadir la librería hay que 
1) Meter los archivos SumoBot_Lib.cpp, SumoBot_Lib.h y keywords.txt (por lo menos) en una carpeta llamada "SumoBot_Lib", 
si la carpeta no se llama igual que el .h y el .cpp no funcionará. 
2) Ahora tenéis 2 opciones:
  2.1) AUTOMÁTICA: crear un.zip de la carpeta y utilizar la funcionalidad del IDE para importar librerías
  2.2) MANUAL: meter la carpeta dentro de la carpeta "libraries" donde tengais instalado el IDE
