#include <stdio.h> 
#include <stdlib.h> 
#include <stdint.h> 


struct student {
    int32_t student_id;
    int8_t flags;
    char student_name [23];
    int32_t student_age;
};


// generate a function to PRINT STUDENT
void print_student(struct student *student){
    // Extract gender and status using bitwise operations
    unsigned char gender = (student -> flags >> 7) & 1;  // Extract the MSB (7th bit)
    unsigned char postgraduate = (student -> flags >> 6) & 1;  // Extract the MSB (7th bit)

    printf("%-23s %-5d %-8s\n",
            (*student).student_name, student-> student_age,(gender ==1) ? "Female" : "Male");
}




int main (int argc, char *argv[]){

//check arguments being passed in the command line
if (argc != 4){
    printf("Number of arguments passed are not correct.\n");
    return 1;
}


// Obtain arguments passed in the command line
char min_age = atoi(argv[2]);  
char max_age = atoi(argv[3]);
if (min_age > max_age || min_age <= 0 || max_age <= 0 || min_age > 100 || max_age > 100 ){
    printf ("Error: Please re-evaluate the ages passed as arguments.\n");
    return 1;
}


// open file into input_file
FILE *input_file = fopen("sample_data.bin", "rb");
    if(input_file == NULL) {
        printf("Error while opening the file.\n");
    }



// Header
uint16_t magic_string;
uint32_t student_count; 
uint32_t courses_count; 
uint32_t enrollment_count;
fread(&magic_string, sizeof(uint16_t), 1, input_file);
fread(&student_count, sizeof(int32_t), 1, input_file);
fread(&courses_count, sizeof(int32_t), 1, input_file);
fread(&enrollment_count, sizeof(int32_t), 1, input_file);


// print header for table in task 1
// variables to assign widths in between columns
int nameWidth = 24;
int ageWidth = 6;
int genderWidth = 8;
printf("%-*s%-*s%-*s\n", nameWidth, "Name", ageWidth, "Age", genderWidth, "Gender");
   

// Student struct instance
struct student student[student_count];
int reads_estudiante = 0;  


//read file and print students meeting the age gap given in the command line
while ((fread(student, sizeof(struct student), 1, input_file) == 1) && reads_estudiante <= student_count) {
    if (student->student_age >= min_age && student->student_age <= max_age) {
        print_student(student);
    }

    // add one to the counter to compare results with peers. (DELETE AFTER!!)
    reads_estudiante++;  

}


// close file
fclose(input_file);
return 0;
}


