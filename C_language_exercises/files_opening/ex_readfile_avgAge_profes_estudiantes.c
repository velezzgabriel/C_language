
//////////          //////////          //////////          //////////          
/*
this script intends to print out:
     Header 
     AVG age estudiantes 
     
     AVG age profesores
*/
//////////          //////////          //////////          //////////          


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create structs for each of the sections of the file to be read...
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


// generate a print function for each of the structs that will be printed
// if the struct is only one, meaning it is not an array of structs, we dont need to create a function.

// generate a function to PRINT ESTUDIANTE
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
           edad, nombre, apellido, grado, (gender == 1) ? "Male" : "Female", (status == 1) ? "Approved" : "Not Approved");
}


// generate a function to PRINT PROFESOR
void print_profesor(struct profesores *profesor){
    // Extract gender and status using bitwise operations
    unsigned char gender = (profesor -> gender >> 7) & 1;  // Extract the MSB (7th bit)

    printf("Edad: %-2d  Nombre: %-10s  Apellido: %-10s  Grado: %-2d  gender: %s\n",
            (*profesor).edad, profesor-> nombre, profesor-> apellido, profesor-> grado, (gender ==1) ? "Male" : "Female");
}




int main(int argc, char** argv) {

printf("---------------------------- MAIN ------------------------------------------\n");
    
    //open the binary file into a descriptor of type FILE*...
    FILE *input_file = fopen("/home/avanzatech/Downloads/file.bin", "rb");
    if (input_file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    //HEADER: read file DESCRIPTOR into header struct, then print it.
    //NO need of loop as header is only one struct to print
    struct header header;
    fread(&header, sizeof(struct header), 1, input_file);
    printf("Header -->  total_estudiantes: %d,  total_profesores: %d\n", header.total_estudiantes, header.total_profesores);




printf("----------------------------  ESTUDIANTES  -----------------------------------------\n");

    //create struct ESTUDIANTE, then read file into ESTUDIANTE, then print it with a loop
    struct estudiantes estudiante[100];
    int reads_estudiante = fread(estudiante, sizeof(struct estudiantes), 100, input_file);
        if (reads_estudiante != 100){
            printf("no se pudo leer estudiantes");
        }

    // printing AVG age for estudiantes...
    int counter_estudiantes = 0;
    int sum_ages_est = 0;
    for (int i = 0; i< 100; i++){
        sum_ages_est += estudiante[i].edad;
        counter_estudiantes++;
    }
    printf("This is the avg age per STUDENT: %d\n",  sum_ages_est/counter_estudiantes);


    // printing both approved and not approved males and females
    unsigned char gender;
    unsigned char status;
    int male_approved = 0;
    int male_notApproved = 0;
    int female_approved = 0;
    int female_notApproved = 0;


    // males and females per grado
    int males_per_grado[6] = {0}; // Assuming grado between 6 and 11
    int females_per_grado[6] = {0}; // Assuming grado between 6 and 11
    int grad = 0;

    for (int i = 0; i< 100; i++){
        gender = (estudiante[i].gender_status >> 7) & 1;  // Extract the MSB (7th bit)
        status = (estudiante[i].gender_status >> 6) & 1;  // Extract the bit next to the MSB (6th bit)

        switch (gender){
            case 0:
                // if to count approved and not approved males
                if(status == 0){
                    male_notApproved++;
                }else{
                    male_approved++;
                }

                // if to count males per year...
                grad = estudiante[i].grado;
                if (grad >= 6 && grad <= 11) {
                    males_per_grado[grad-6]++;
                }
                break;

            case 1:
                // if to count approved and not approved females
                if(status == 0){
                    female_notApproved++;
                }else{
                    female_approved++;
                }

                // if to count females per year...
                grad = estudiante[i].grado;
                if (grad >= 6 && grad <= 11) {
                    females_per_grado[grad-6]++;
                }
                break;
        }


    }

    // print males & females, approved & not approved
    printf("Male Approved: %d\nMale Not Approved: %d\nFemale Approved: %d\nFemale Not Approved: %d\n", 
            male_approved,male_notApproved,female_approved,female_notApproved);

    // print males and females per grado
    const char *grados_estudiantes[] = {"Sexto", "Septimo", "Octavo", "Noveno", "Decimo", "Once"};
        for (int i = 0; i < 6; i++) {
            printf("grado: %-10s: males: %-8d  females: %-8d\n",
            grados_estudiantes[i], males_per_grado[i],females_per_grado[i]);
        }


    // printing ALL estudiantes......
    for (int i = 0; i< 100; i++){
        print_estudiante(&estudiante[i]);
    }


printf("-----------------------------  PROFESORES  ---------------------------------------------\n");


    //create struct PROFESOR, then read file into PROFESOR, then print it with a loop
    struct profesores profesor[100];
    int reads_profesor = fread(&profesor, sizeof(struct profesores), 100, input_file);
        if (reads_profesor != 100){
            printf("no se pudo leer estudiantes");
        }
    
    // printing (AVG AGE for profesores && prof_per_grado)
    int counter_profesores = 0;
    int sum_ages_prof = 0;

    int prof_per_grado[6] = {0}; // Assuming grado between 6 and 11

    for (int i = 0; i< 100; i++){
        sum_ages_prof += profesor[i].edad;
        counter_profesores++;
        int grado = profesor[i].grado;
        if (grado >= 6 && grado <= 11) {
            prof_per_grado[grado-6]++;
        }
    }
    printf("This is the avg age per PROFESOR: %.2f\n", (float)sum_ages_prof/counter_estudiantes);

    // --> FIRST way to print the profesores per year is   ----------------
    // printf("Profesores per grado...\nSexto: %d\nSeptimo: %d\nOctavo: %d\nNoveno: %d\nDecimo: %d\nOnce: %d\n",
    //             prof_per_grado[0],prof_per_grado[1],prof_per_grado[2],prof_per_grado[3],prof_per_grado[4],prof_per_grado[5],prof_per_grado[6]);
    
    // --> SECOND way to print the profesores per year is  ----------------
    const char *grados[] = {"Sexto", "Septimo", "Octavo", "Noveno", "Decimo", "Once"};
    for (int i = 0; i < 6; i++) {
        printf("%-10s: %d\n", grados[i], prof_per_grado[i]);
    }
    

    //printing ALL profesores...
    for (int i = 0; i< 100; i++){
        print_profesor(&profesor[i]);
    }


    // close files opened (input and output files)
    fclose(input_file);
    return 0;
}
