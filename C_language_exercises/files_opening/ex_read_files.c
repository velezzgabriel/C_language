
#include <stdio.h>

int main (int argc, char **argv)
{
    // FOPEN() nos devuelve un descriptor a ese archivo, que es un puntero, de tipo FILE
    FILE *profes = fopen("/home/avanzatech/Downloads/file.bin","rb");

    if (!profes){
        printf("file was not opened");
        return 1;
    }


    //FSEEK() acepta tres parametros: (descriptor, bytes a desplazarse, [SEEK_SET|SEEK_END|SEEK_CUR]);
    fseek(profes, 5, SEEK_SET);  //--> mueve cursor 5bytes a la DERECHA a partir del inicio.
    fseek(profes,-5, SEEK_CUR);  //--> mueve cursor 5bytes a la IZQUIERDA a partir del current position.
    fseek(profes, 0, SEEK_END);  //--> finds out last position = tamaño del archivo en BYTES.


    //REWIND(descriptor) sería lo mismo que ---> fseek(descriptor,0,SEEK_SET);
    rewind(profes);


    // FEOF() devuelve "1" si está al final del archivo o "0" si no es end of file.
    int feoff = feof(profes);
    printf("FEOF ------------ %d\n", feoff );

    //FTELL() devuelve un LONG con la posicion actual del cursor
    long first_position = ftell(profes);
    printf("el cursor està en position: %ld\n", first_position);

    // FGETC() devuelve un int, no char. 
    do {
    int leido = fgetc(profes);
    if(!feof(profes)){
    // se debe castear a char la variable devuelta por fgetc().
    printf("%d", (char) leido);
    }else {
        printf("\n===FIN===\n");
    }
    } while (!feof(profes)); 


long end_position = ftell(profes);
    printf("el cursor està en position: %ld\n", end_position);



    // importante cerrar el archivo
    fclose(profes);
}