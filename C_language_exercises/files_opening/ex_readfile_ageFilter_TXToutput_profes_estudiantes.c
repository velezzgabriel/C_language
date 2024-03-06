

//////////          //////////          //////////          //////////          
/*
this script outputs .TXT file with the header, estudiantes and profesores, it also uses filters
*/
//////////          //////////          //////////          //////////      



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct header {
    int total_estudiantes;
    int total_profesores;
};

struct estudiantes {
    int edad;
    char nombre[10];
    char apellido[10];
    int grado;
    unsigned char gender_status;
};

struct profesores {
    int edad;
    char nombre[10];
    char apellido[10];
    int grado;
    unsigned char gender;
};


    
void print_estudiante(struct estudiantes *estudiante){

    int edad = estudiante->edad;
    char *nombre = estudiante->nombre;
    char *apellido = estudiante->apellido;
    int grado = estudiante->grado;
    unsigned char gender_status = estudiante->gender_status;

    // Extract gender and status using bitwise operations
    unsigned char gender = (estudiante -> gender_status >> 7) & 1;  // Extract the MSB (7th bit)
    unsigned char status = (estudiante -> gender_status >> 6) & 1;  // Extract the bit next to the MSB (6th bit)

    printf("Edad: %-2d  Nombre: %-10s  Apellido: %-10s  Grado: %-2d  Gender: %-8s  Status: %s\n",
           edad, nombre, apellido, grado, (gender == 0) ? "Male" : "Female", (status == 1) ? "Approved" : "Not Approved");
}


void print_profesor(struct profesores *profesor){
    // Extract gender and status using bitwise operations
    unsigned char gender = (profesor -> gender >> 7) & 1;  // Extract the MSB (7th bit)

    printf("Edad: %-2d  Nombre: %-10s  Apellido: %-10s  Grado: %-2d  gender: %s\n",
            profesor-> edad, profesor-> nombre, profesor-> apellido, profesor-> grado, (gender ==0) ? "Male" : "Female");
}



int main(int argc, char** argv) {
    //open the binary file...
    FILE *inputFile = fopen("/home/avanzatech/Downloads/file.bin", "rb");
    if (inputFile == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // open a file where I am writing the info that I want
    FILE *outputFile = fopen("my_second_file.txt", "w");
    if (outputFile == NULL) {
        printf("Error creating/opening the output file.\n");
        return 1;
    }


    //read file into HEADER, then print it.
    //print header. NO need of loop as it is only one element to print
    struct header header;
    fread(&header, sizeof(struct header), 1, inputFile);
    
    printf("%d, %d\n", header.total_estudiantes ,header.total_profesores);

    // fprintf(outputFile, "%d,  %d\n", header.total_estudiantes, header.total_profesores);


    //create struct ESTUDIANTE, then read file into ESTUDIANTE, then print it with a loop
    struct estudiantes estudiante[100];
    int reads_estudiante = 0;  
    while ((fread(estudiante, sizeof(struct estudiantes), 1, inputFile) == 1) && reads_estudiante <= 100) {
        if (estudiante->edad >= 13 && estudiante->edad <= 15) {
            print_estudiante(estudiante);
            // ---> write into "output" file
            // fprintf(outputFile, "Edad: %d Nombre: %s Apellido: %s Grado: %d Gender: %s Status: %s\n",
            //         estudiante->edad, estudiante->nombre, estudiante->apellido, estudiante->grado,
            //         (estudiante->gender_status >> 7) & 1 ? "Male" : "Female",
            //         (estudiante->gender_status >> 6) & 1 ? "Approved" : "Not Approved");
            // reads_estudiante++;
        }
        reads_estudiante++;  

    }
    struct profesores profesor[100];
    int reads_profesor = 0;  
    while ((fread(profesor, sizeof(struct profesores), 1, inputFile) == 1)&& reads_profesor<=100) {
        if (profesor-> edad >= 10 && profesor-> edad <= 60) {
            print_profesor(profesor);
            // --> write into "output" file
            // fprintf(outputFile, "Edad: %d Nombre: %s Apellido: %s Grado: %d Gender: %s\n",
            //         profesor->edad, profesor->nombre, profesor->apellido, profesor->grado,
            //         (profesor->gender >> 7) & 1 ? "Male" : "Female");
            // reads_profesor++;  
        }
        reads_profesor++;  

    }



    

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
