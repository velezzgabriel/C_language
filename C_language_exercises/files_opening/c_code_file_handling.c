

//////////////////////  FILE HANDLING



/*----------------- fopen
DESCRIPTION
       The fopen() function opens the file whose name is the string pointed to by pathname and associates a stream with it.

       The argument mode points to a string beginning with one of the following sequences (possibly followed by additional characters, as described below):

       r      Open text file for reading.  The stream is positioned at the beginning of the file.

       r+     Open for reading and writing.  The stream is positioned at the beginning of the file.

       w      Truncate file to zero length or create text file for writing.  The stream is positioned at the beginning of the file.

       w+     Open for reading and writing.  The file is created if it does not exist, otherwise it is truncated.  The stream is positioned at the beginning of the file.

       a      Open for appending (writing at end of file).  The file is created if it does not exist.  The stream is positioned at the end of the file.

       a+     Open for reading and appending (writing at end of file).  The file is created if it does not exist.  Output is always appended to the end of the file.  POSIX is silent on what the ini‐
              tial read position is when using this mode.  For glibc, the initial file position for reading is at the beginning of the file, but for Android/BSD/MacOS, the initial file position  for
              reading is at the end of the file.
*/







//-->  FGETC()
// cada vez que llamamos fgetc() movemos el stream un espacio a la derecha....

#include <stdio.h>
int main (int argc, char** argv){

    //fopen retorna un DESCRIPTOR a ese archivo. Este es un puntero
    FILE *temperaturas = fopen("temperaturas.data" , "r");
    // Comprobar si el puntero que devuelve está OK.
    if (!temperaturas) {
        printf ("No se ha abierto el archivo");
        return 1; 
    }

    // leer un caracter
    do{
        int leido = fgetc(temperaturas);
        if (!feof(temperaturas)){           //> replace with: "if (leido != EOF)"
            printf("%c" , (char) leido);    //> cast fgetc() return from int to char
        } else {
            printf(" === FIN === \n");
        }
    } while (!feof(temperaturas));
    // cerrar archivo
    fclose(temperaturas);
}

//-----------------------------------------
#include <stdio.h>

int main() {
    FILE* file = fopen("example.txt", "r");
    if (file == NULL) {
        // display error
        perror("Error opening file");
        return 1;
    }

    int character;
    while ((character = fgetc(file)) != EOF) {
        // Process the character, which is stored as an integer.
        printf("Character read: %c\n", (char)character);
    }

    fclose(file);
    return 0;
}






//-->   FTELL()  recibe descriptor, retorna un LONG INTEGER con la posicion del cursor.
        // returns (-1) cuando falla.
do {
    int car = fgetc(temperaturas);
    long pos = ftell(temperaturas);
    if (car != EOF){
        printf("%ld %c\n", pos, car);        
    } else {
        printf("%ld EOF\n", pos);
} while (!feof(temperaturas));

}


//-->   FSEEK(descriptor, offset (bytes), [SEEK_SET | SEEK_END | SEEK_CURR] )  
//          Sirve para posicionar el cursor 

SEEK_SET    : cursor se desplaza el OFFSET dado desde el principio del archivo.
SEEK_END    : cursor se desplaza desde el final del archivo. OFFSET debe ser NEGATIVO.
SEEK_CURR   : cursor se desplaza desde current position. OFFSET positivo o negativo.


//-- encontrar tamaño de archivo:
//  1) vete al final:
    fseek (temperaturas, 0, SEEK_END);

//  2) averigua position del stream:
    long tamanio = ftell(temperaturas);

//  3) vuelve al principio
    rewind(temperaturas);



///////////////////////////////////////////////////////

//--> FGETS()
//--> parametros ->  buffer, chars a leer, descriptor
//                      De los 80 chars a leer en este ejemplo, el ultimo es para EOF.                     
//--> fgets() devolverá un pointer a buffer, si hay error devuelve NULL. 
//      Deja de leer cuando se encuentra un salto de linea o EOF.
//      Si el primer caracter que trata de leer es EOF, devuelve error.
    
    char *ref = fgets(buffer, 80, temperaturas);
//> fgets() recibe: 
//(1) buffer variable donde se guarda la lectura
//(2) size del buffer
//(3) descriptor
//-----------------------------------------------------

int main (int argc, char **argv){


FILE *profes = fopen("/home/avanzatech/Downloads/file.bin","rb");

if (!profes){
    printf("file was not opened");
    return 1;
}

char buffer[80];

do {
    if (fgets(buffer, 80, profes)){
        printf("%s", buffer);
    }
} while (!feof(profes));

}


//--> FPUTC()
// Retorna INT si sale bien. 
// Si sale mal retorna EOF

int result = fputc('h', temperaturas);
if (result == EOF){
    printf("algo salió mal...");
} else {
    printf("hemos escrito %c\n" , result)
}



//--> FPUTS()
// Devuelve numero no negativo si salió bien. 

int result = fputs("hola como estas el dia de hoy", temperaturas);
if (result == EOF){
    printf("algo salió mal...");
} else {
    printf("hemos escrito ALGO \n");
}


//--> FWRITE()  -> devuelve int con el numero de veces que pudo escribir el buffer.
//      buffer = zona de bytes en memoria que representan una informacion.
//-> fwrite(puntero a donde empieza el buffer, tamanio de bytes del buffer, 
//           cantidad de buffers a escribir, puntero a archivo que acabo de abrir)


#include <stdio.h>

struct medicion {
    unsigned short anio;
    unsigned char mes;
    unsigned char dia;
    float temperatura;
    unsigned char uv;
    unsigned char viento;
};

void print_medicion(struct medicion *medicion) {
    printf("Fecha: %d-%d-%d, Registro %.1f°C. UV %d, Viento %d km/h\n",
           medicions->anio, medicions->mes, medicions->dia,
           medicions->temperatura, medicions->uv, medicions->viento);
}

int main() {
    struct medicion medida = {
        .anio = 2020, .mes = 11, .dia = 9,
        .temperatura = 12.5, .uv = 4, .viento = 15
    };

    FILE *fp = fopen("temperatura.bin", "wb");  // Use "wb" for binary write mode

    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Total should be equal to the number of times you want to write the buffer
    size_t total = fwrite(&medida, sizeof(struct medicion), 1, fp);
    if (total != 1) {
        printf("Error writing to the file\n");
        fclose(fp); // Close the file before exiting
        return 1;
    }

    fclose(fp);

    // Print the written measurement
    print_medicion(&medida);

    return 0;
}


-------------------------------------------
//     ARRAY en el ejercicio
#include <stdio.h>

struct medicion {
    unsigned short anio;
    unsigned char mes;
    unsigned char dia;
    float temperatura;
    unsigned char uv;
    unsigned char viento;
};

void print_medicion(struct medicion *medicion) {
    printf("Fecha: %d-%d-%d, Registro %.1f°C. UV %d, Viento %d km/h\n",
           medicions->anio, medicions->mes, medicions->dia,
           medicions->temperatura, medicions->uv, medicions->viento);
}

int main(int argc, char** argv){
    struct medicion medidas[] = {
    {
        .anio = 2020, .mes = 11, .dia = 9,
        .temperatura = 15, .uv = 4, .viento = 15
    },
    {
        .anio = 2020, .mes = 11, .dia = 8,
        .temperatura = 10, .uv = 2, .viento = 25
    },
    {
        .anio = 2020, .mes = 11, .dia = 7,
        .temperatura = 20, .uv = 5, .viento = 12
    },
    {
        .anio = 2020, .mes = 7, .dia = 24,
        .temperatura = 40, .uv = 8, .viento = 0
    },
    {
        .anio = 2020, .mes = 1, .dia = 3,
        .temperatura = -3, .uv = 1, .viento = 80
    },
        {
        .anio = 2020, .mes = 1, .dia = 1,
        .temperatura = -30, .uv = 11, .viento = 11
    }
    };

    FILE *fp = fopen("temperatura.bin", "w");
    
    int total = fwrite(&medidas, sizeof(struct medicion), 5 , fp);
    if (total != 5){
        printf("algo ha salido mal \n");
    }
    fclose(fp);

    for (int i= 0; i < 5; i++){
        print_medicion(&medidas[i]);
    }
}



//--> FREAD() 
// devuelve INT de cuantas veces se leyó el archivo
//parametros: fread(puntero a buffer, tamanio de buffer, # de veces a leer, puntero a archivo a abrir);    )

#include <stdio.h>

struct medition {
    unsigned short anio;
    unsigned char mes;
    unsigned char dia;
    float temperatura;
    unsigned char uv;
    unsigned char viento;
};

void print_medicion(struct medicion *medicion) {
    printf("Fecha: %d-%d-%d, Registro %.1f°C. UV %d, Viento %d km/h\n",
           meditions->anio, meditions->mes, meditions->dia,
           meditions->temperatura, meditions->uv, meditions->viento);
}


int main (int argc, char** argv){
    
    struct medicion medida;

    print_medicion(&medida);

    FILE *fp = fopen("temperatura.bin" , "r");
    
    int total = fread(&medida, sizeof(struct medicion), 1, fp );
    if(total != 1){
        printf("hemos tenido un problema");
    }
    fclose(fp);

    print_medicion(&medida);
}






//--> PUTC()


//--> PUTS()


//--> GETCHAR()



//--> SCANF()




//--> PRINTF()

/*
PLACEHOLDERS:

Integer Format Specifiers:

%d: Signed integer.
%u: Unsigned integer.
%ld: Long signed integer.
%lu: Long unsigned integer.
%lld: Long long signed integer.
%llu: Long long unsigned integer.
%x or %X: Hexadecimal integer.
Floating-Point Format Specifiers:

%f: Float or double (decimal notation).
%e or %E: Float or double (exponential notation).
%g or %G: Float or double (use %f or %e, whichever is shorter).
Character Format Specifiers:

%c: Character.
%s: String (null-terminated character array).
Pointer Format Specifier:

%p: Pointer.
Special Format Specifiers:

%%: Literal % (used to print the % character).
Width and Precision Specifiers:

%[width]d: Minimum width for integer (e.g., %5d).
%.[precision]f: Number of decimal places for floating-point (e.g., %.2f).
Size Modifiers:

%h: Short integer.
%hh: Signed char.
%l: Long integer.
%ll: Long long integer.
*/