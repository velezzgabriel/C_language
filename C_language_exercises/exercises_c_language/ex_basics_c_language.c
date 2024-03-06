/* 
///////////////////// PREPROCESADOR
Lee linea a linea el contenido del archivo, lo que lee influye como se comporta a partir de ese momento. 
Generalmente se inicia con #
 "stdio.h" entre comillas, buscará un archivo llamado así en la misma carpeta donde está "main.c".


/////////////////////   HEADER  //////////////////////
////////////        CABECERA --> ARCHIVOS FORANEOS
NO importar un archivo .C dentro de otro .C  --> Esto puede traer problemas con identificadores duplicados.

la solucion en importar una version simplificada del .C que incluye definiciones de estructuras y prototipos
estos archivos son los  .H , van en el archivo cabecera 


//////////// GUARDS
Evitan que una region de codigo se compile mas de una vez.  

--> lo que debemos hacer es usar #ifndef para verificar que no esté definido, luego lo definimos. Recordar cerrar el if con #endif

#ifndef SUELDOS
#define SUELDOS

#include "empleados.h"

void pagar_sueldo(Empleado* e);

#endif





////////////        #DEFINE and  #UNDEF  del preprocesador

#DEFINE   "nombre" "valor"
 --> type of global variable....... 
 --> cada vez que el preprocesador encuentre el "nombre" lo reemplazará por "valor" 


-----------MACROS
--> esto es una macro que ayuda en dispositivos como en una validadora de billetes.
-->  una funcion sencilla que se repite muchas veces.
-->  ayuda en dispositivos donde el procesador es muy pequeño.
-------------------------------
#DEFINE  AREA_RECTANGULO (x,y) (x*y)  
int main(){
    int ancho=5, alto=4;
    printf("el area de un rectangulo %d x %d = %d.\n", ancho, alto, AREA_RECTANGULO(ancho,alto));
    return 0;
}
------------------------------
#UNDEF  "nombre"
--> desdefine lo que se habia definido con #DEFINE 

    #UNDEF AREA_RECTANGULO



#IF
los IF del preprocesador se resuelven en tiempo de compilacion, no en tiempo de ejecucion.
Por lo tanto, si un IF no se cumple, esa parte del codigo nisiquiera se compilarà.

--> del siguiente codigo solo se compilará lo que se cumpla en el IF... 

Ex1:
-------------------------------
#if LIMITE < 50
    printf("limite por debajo de 50\n");
#elif LIMITE < 100
    printf("limite por debajo de 100\n");
#else
    printf("limite de 100 o más\n");
#endif

Ex2:
#define PREMIUM
------------------------------
#if defined(PREMIUM)
    printf("estas usando la version premium\n");
#else
    printf("estas usando la version gratuita\n");
#endif

------------------------------
#ifdef PREMIUM
    printf("estas usando la version premium\n");
#endif







------------>           #include <stdlib.h>
NOS PERMITIRÁ TRABAJAR CON MEMORIA DINAMICA. 

------------>           #include <stdio.h>
DESCRIPTION
       The  standard  I/O  library  provides a simple and efficient buffered stream I/O interface.  Input and output is mapped into logical data streams and the physical I/O characteristics are con‐
       cealed.  The functions and macros are listed below; more information is available from the individual man pages.

       A stream is associated with an external file (which may be a physical device) by opening a file, which may involve creating a new file.  Creating an existing file causes its  former  contents
       to  be  discarded.   If a file can support positioning requests (such as a disk file, as opposed to a terminal), then a file position indicator associated with the stream is positioned at the
       start of the file (byte zero), unless the file is opened with append mode.  If append mode is used, it is unspecified whether the position indicator will be placed at the start or the end  of
       the  file.   The  position  indicator  is maintained by subsequent reads, writes and positioning requests.  All input occurs as if the characters were read by successive calls to the fgetc(3)
       function; all output takes place as if all characters were written by successive calls to the fputc(3) function.

       A file is disassociated from a stream by closing the file.  Output streams are flushed (any unwritten buffer contents are transferred to the host environment) before the stream is  disassoci‐
       ated from the file.  The value of a pointer to a FILE object is indeterminate after a file is closed (garbage).

       A  file  may be subsequently reopened, by the same or another program execution, and its contents reclaimed or modified (if it can be repositioned at the start).  If the main function returns
       to its original caller, or the exit(3) function is called, all open files are closed (hence all output streams are flushed) before program termination.  Other methods of program  termination,
       such as abort(3) do not bother about closing files properly.

       At  program  startup,  three text streams are predefined and need not be opened explicitly: standard input (for reading conventional input), standard output (for writing conventional output),
       and standard error (for writing diagnostic output).  These streams are abbreviated stdin, stdout, and stderr.  When opened, the standard error stream is not fully buffered; the standard input
       and output streams are fully buffered if and only if the streams do not refer to an interactive device.

       Output  streams  that refer to terminal devices are always line buffered by default; pending output to such streams is written automatically whenever an input stream that refers to a terminal
       device is read.  In cases where a large amount of computation is done after printing part of a line on an output terminal, it is necessary to fflush(3) the standard output  before  going  off
       and computing so that the output will appear.

       The stdio library is a part of the library libc and routines are automatically loaded as needed by cc(1).  The SYNOPSIS sections of the following manual pages indicate which include files are
       to be used, what the compiler declaration for the function looks like and which external variables are of interest.


       Function         Description
       ──────────────────────────────────────────────────────────────────────
       clearerr(3)      check and reset stream status
       fclose(3)        close a stream
       fdopen(3)        stream open functions
       feof(3)          check and reset stream status
       ferror(3)        check and reset stream status
       fflush(3)        flush a stream
       fgetc(3)         get next character or word from input stream
       fgetpos(3)       reposition a stream
       fgets(3)         get a line from a stream
       fileno(3)        return the integer descriptor of the argument stream
       fopen(3)         stream open functions
       fprintf(3)       formatted output conversion
       fpurge(3)        flush a stream
       fputc(3)         output a character or word to a stream
       fputs(3)         output a line to a stream
       fread(3)         binary stream input/output
       freopen(3)       stream open functions
       fscanf(3)        input format conversion
       fseek(3)         reposition a stream
       fsetpos(3)       reposition a stream
       ftell(3)         reposition a stream
       fwrite(3)        binary stream input/output
       getc(3)          get next character or word from input stream
       getchar(3)       get next character or word from input stream
       gets(3)          get a line from a stream
       getw(3)          get next character or word from input stream
       mktemp(3)        make temporary filename (unique)
       perror(3)        system error messages
       printf(3)        formatted output conversion
       putc(3)          output a character or word to a stream
       putchar(3)       output a character or word to a stream
       puts(3)          output a line to a stream
       putw(3)          output a character or word to a stream
       remove(3)        remove directory entry
       rewind(3)        reposition a stream
       scanf(3)         input format conversion
       setbuf(3)        stream buffering operations
       setbuffer(3)     stream buffering operations
       setlinebuf(3)    stream buffering operations
       setvbuf(3)       stream buffering operations
       sprintf(3)       formatted output conversion
       sscanf(3)        input format conversion
       strerror(3)      system error messages
       sys_errlist(3)   system error messages
       sys_nerr(3)      system error messages
       tempnam(3)       temporary file routines
       tmpfile(3)       temporary file routines
       tmpnam(3)        temporary file routines
       ungetc(3)        un-get character from input stream
       vfprintf(3)      formatted output conversion
       vfscanf(3)       input format conversion
       vprintf(3)       formatted output conversion
       vscanf(3)        input format conversion
       vsprintf(3)      formatted output conversion
       vsscanf(3)       input format conversion


------------>           #include <stdstrings.h>
#include <strings.h>
    The string functions perform operations on null-terminated strings.  See the individual man pages for descriptions of each function.

       Function         Description
       ──────────────────────────────────────────────────────────────────────
       int strcasecmp(const char *s1, const char *s2);
              Compare the strings s1 and s2 ignoring case.

       int strncasecmp(const char *s1, const char *s2, size_t n);
              Compare the first n bytes of the strings s1 and s2 ignoring case.

       char *index(const char *s, int c);
              Return a pointer to the first occurrence of the character c in the string s.

       char *rindex(const char *s, int c);
              Return a pointer to the last occurrence of the character c in the string s.



------------>           #include <string.h>
#include <string.h>
    The string functions perform operations on null-terminated strings.  See the individual man pages for descriptions of each function.

       Function         Description
       ──────────────────────────────────────────────────────────────────────
       char *stpcpy(char *dest, const char *src);
              Copy a string from src to dest, returning a pointer to the end of the resulting string at dest.

       char *strcat(char *dest, const char *src);
              Append the string src to the string dest, returning a pointer dest.

       char *strchr(const char *s, int c);
              Return a pointer to the first occurrence of the character c in the string s.

       int strcmp(const char *s1, const char *s2);
              Compare the strings s1 with s2.

       int strcoll(const char *s1, const char *s2);
              Compare the strings s1 with s2 using the current locale.

       char *strcpy(char *dest, const char *src);
              Copy the string src to dest, returning a pointer to the start of dest.

       size_t strcspn(const char *s, const char *reject);
              Calculate the length of the initial segment of the string s which does not contain any of bytes in the string reject,

       char *strdup(const char *s);
              Return a duplicate of the string s in memory allocated using malloc(3).

       char *strfry(char *string);
              Randomly swap the characters in string.

       size_t strlen(const char *s);
              Return the length of the string s.
        
       size_t strspn(const char *s, const char *accept);
              Calculate the length of the starting segment in the string s that consists entirely of bytes in accept.

       char *strstr(const char *haystack, const char *needle);
              Find the first occurrence of the substring needle in the string haystack, returning a pointer to the found substring.

       char *strtok(char *s, const char *delim);
              Extract tokens from the string s that are delimited by one of the bytes in delim.

       size_t strxfrm(char *dest, const char *src, size_t n);
              Transforms src to the current locale and copies the first n bytes to dest.






//////////////   IF STATEMENT  //////////////
int main (parametros){
    int x = 20;
     if (/*condition1 && condition2*/){
        //instructions if IF is TRUE ;
     } else if (/*condition3 || condition4*/){
        //more instructions;
     } else {
        //instructions;
     }
}


//////////////   SWITCH  //////////////


void imprimir_dia (int numero_de_dia){
    switch (numero_de_dia){
        case 1:
        case 2: 
        case 3:
        case 4:
        case 5:
            printf("Día de semana");
            break;
        case 6:
        case 7:
            printf("Fin de semana");
            break;
        default:
            print("number must be between 1 and 7");
            break;
    }
} 



//////////////   WHILE LOOP  //////////////
 
int main (){
    int k = 10;
    while (k < 20){
        printf("k vale %d \n" , k);
        k++;
    }
}


-----------------------------------
int main(){
    int valor;
    while (1){
        scanf("%d", &valor);
        if (valor == 0){
            break;
        }
        printf(" > has insertado %d \n", valor );
    }
}

//////////////  DO WHILE LOOP  //////////////

int main(){
    int k = 10;
    do{
        printf("k value is: %d", k);
    } while (k<20);
}



//////////////  FOR LOOP  //////////////

//  FOR (initialization; condition; iteration){
//      "código_______________"
//  }

/*  PASOS
1- ejecutar inicializacion.
2- evalua condiciòn, si no se cumple...fin.
3- ejecutar codigo del bucle.
4- ejecutar "iteracion".
5- volver al paso 2.
*/


int main(){
    for (int i=0 ; i<5 ; i++){
        printf("i value is: %d", i);
    }

}





/////////////////  STRUCT
similar a una clase
--> se debe poner punto y coma al final de la struct, despues de la llave que cierra la STRUCT
--> la debo instanciar para usarla



///////////////// UNION
Parecido a structs. Aunque en UNION, todos los campos que comparten una union tiene la misma direccion.
Tambien funciona como una clase, osea que la debo instanciar para usarla.
union mi_union {
    int entero;
    float flotante;
};   --> se debe terminar la construccion de UNION con punto y coma despues de cerrar llave.

//instanciacion
union mi_union u;
u.entero = 123456
u.flotante = 2.54E26




///////////////// ENUMERADORES
--despues de crear mi ENUM, debo instanciarlo
--> sirven para construir conjunto de identificadores
--> enum retornará por default el digito de la posicion del nombre de la variable en enum.
// NOTE! la declaracion de un enum debe terminar con punto y coma.
enum diasemana {lunes, martes, miercoles , jueves, viernes, sabado, domingo };

int main(){
    enum diasemana dia;

    dia = lunes;
    printf("%d \n", dia);   //  it will print 0 for lunes, 1 for martes, 2 for miercoles 

    return 0;
}

--> tambien puedo asignarle un valor especifico a cada nombre en enum. 
enum diasemana {lunes=000, martes=111, miercoles=222 , jueves=333, viernes=444, sabado=555, domingo=666 };

int main(){
    enum diasemana dia;

    dia = lunes;
    printf("%d \n", dia);   //  it will print 000 for lunes, 111 for martes, 222 for miercoles 

    return 0;
}


//////////////// TYPE DEFINITION
//No es tan buena practica porque estoy contaminando el espacio de nombres global.
//Las palabras que uso con "typedef" se convierte en una palabra reservada. 

//-->aquí podré usar "entero" en vez de "int" en mi codigo
typedef int entero;

//-->aquí puedo usar "Tipo" en vez de "enum tipo_empleado" para instanciar variables de tipo "enum tipo_empleado". 
typedef enum tipo_empleado Tipo;
 




