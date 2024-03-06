/*------------  COMPILATION

Se compilan los archivos .C, no los .H


gcc -pedantic -Wall -Wextra -o  compiled_file_name  file_c_language.c  lib/calculadora.a (customed shared lib)

gcc -g -pedantic -Wall -Wextra -o  my_program   my_program.c

gcc -g : genera un poco mas de info para poder depurar.
------------  DEPURADOR  GDB




ETAPAS de compilacion con gcc
-> Preprocesa el programa --> PREPROCESADO
    *Retira comentarios y resuelve los comandos del preprocesador (#).
    cpp (C Pre Processor): este comando lo que hace recibe el archivo y su output es el codigo preprocesado.
                            se eliminan espacios. incluye todos los archivos que se le hayan indicado en el script.
    cpp < hello.c | less

    *otra forma de hacer lo mismo es a traves de gcc:
    gcc -E hello.c

-> Traduccion a ensamblador --> ENSAMBLADOR
    *Aqui se produce un archivo con el mismo programa que hemos escrito pero en lenguage ensamblador:
        gcc -S hello.c    -->  output:  hello.s

-> Compilado o Ensamblado --> BINARIO
    *Se obtiene archivo de codigo OBJETO, con el codigo traducido a lenguage máquina (BINARIO)
    gcc -c hello.c    ---> output: hello.o

-> Enlazado --> ESTRUCTURADO
    * lo realiza otro programa llamado "ld". 
      consiste en enlazar los diferentes archivos .O que quieren ser enlazados. 
      no puedo ejecutar archivos .O, por lo cual debo darle la estructura requerida por el kernel en el que estoy trabajando. 
    * esto lo obtengo con el comando gcc 

---------> los siguientes comandos hacen la compilacion completa, realizan las 4 etapas al tiempo:::
gcc hello.c  empleados.c  main.c  sueldos.c   ---> archivo compilado = a.out
gcc -o hello hello.c  empleados.c  main.c   sueldos.c    ---> archivo compilado = hello

-->La etapa de la compilacion que mas tiempo de CPU tarda es la de pasar el codigo fuente a CODIGO OBJETO.
--> por lo tanto se recomienda usar codigo intermedio..
Osea, compilar a codigo objeto los archivos independientemente....
De esta forma, si necesitamos hacer algun cambio en el futuro, no necesitamos recompilar a codigo objeto todos los archivos.

gcc -c sueldos.c        -> output: sueldos.o
gcc -c empleados.c      -> output: empleados.o
gcc -c main.c           -> output: main.o

--> luego ya podremos obtener el programa final así:
gcc -o empleados sueldos.o  sueldos.o  empleados.o

--> para ejecutar el archivo output:
./a.out
./empleados



