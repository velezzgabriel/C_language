#include <stdio.h> 
#include <stdlib.h> 
#include <stdint.h> 

/// @brief //////////////////////////////////   TASK 3 BACKUP
struct student {
    int32_t student_id;
    int8_t flags;
    char student_name [23];
    int32_t student_age;
};

struct course {
    int32_t course_id;
    char course_name[32];
    int32_t credit_hours;
};

struct enrollment {
    int32_t student_id;
    int32_t course_id;
    int32_t year;
    int32_t semester;
};



int main (int argc, char *argv[]){

// check arguments being passed in the command line
if (argc != 2){
    printf("Number of arguments passed are not correct\n");
    return 1;
}


// open file into input_file
FILE *input_file = fopen("sample_data.bin", "rb");
    if(input_file == NULL) {
        printf("Error while opening the file.\n");
    }


// Header info..
uint16_t magic_string;
uint32_t student_count; 
uint32_t courses_count; 
uint32_t enrollment_count;
fread(&magic_string, sizeof(uint16_t), 1, input_file);
fread(&student_count, sizeof(int32_t), 1, input_file);
fread(&courses_count, sizeof(int32_t), 1, input_file);
fread(&enrollment_count, sizeof(int32_t), 1, input_file);


// student struct instance
struct student student[student_count];
int reads_estudiante = fread(student, sizeof(struct student), student_count, input_file);  
        if (reads_estudiante != student_count){
            printf("Error when reading into STUDENT STRUCT, please do it again.");
        }

// course struct instance
struct course course[courses_count];
int reads_course = fread(course, sizeof(struct course), courses_count, input_file);  
        if (reads_course != courses_count){
            printf(" Error when reading into COURSES STRUCT, please do it again.");
        }

// enrollment struct instance
struct enrollment enrollment[enrollment_count];
int reads_enrollment = fread(enrollment, sizeof(struct enrollment), enrollment_count,input_file);
    if (reads_enrollment != enrollment_count){
        printf("Error when reading into ENROLLMENT STRUCT, please do it again");
    }



// -----> generate an array with distinct years
    int distinct_years[12];
    int distinctCount_year = 0;
    // Iterate through enrollment struct
    for (int i = 0; i < enrollment_count; i++) {
        int year = enrollment[i].year;
        int isDistinct = 1; // Assume the year is distinct
        // Check if the year already exists in the distinct years array
        for (int j = 0; j < distinctCount_year; j++) {
            if (distinct_years[j] == year) {
                isDistinct = 0; // The year is not distinct
            }
        }
        // If the year is distinct, add it to the distinct years array
        if (isDistinct) {
            distinct_years[distinctCount_year] = year;
            distinctCount_year++;
        }
    }
    // Print the distinct years
    printf("Distinct years: ");
    for (int i = 0; i < distinctCount_year; i++) {
        printf("%d ", distinct_years[i]);
    }
    printf("\n");

    int length_distinct_years = sizeof(distinct_years) / sizeof(distinct_years[0]);
    printf("length_distinct_years:  %d\n", length_distinct_years);
    printf("length_distinct_years:  %d\n", distinct_years[10]);



// -----> generate an array with distinct semesters
    int distinctSemesters[4];
    int distinctCount_semester = 0;
    // Iterate through enrollment struct
    for (int i = 0; i < enrollment_count; i++) {
        int semester = enrollment[i].semester;
        int isDistinct = 1; // Assume the year is distinct
        // Check if the year already exists in the distinct years array
        for (int j = 0; j < distinctCount_semester; j++) {
            if (distinctSemesters[j] == semester) {
                isDistinct = 0; // The year is not distinct
            }
        }
        // If the year is distinct, add it to the distinct years array
        if (isDistinct) {
            distinctSemesters[distinctCount_semester] = semester;
            distinctCount_semester++;
        }
    }
    // Print the distinct semesters
    printf("Distinct semesters: ");
    for (int i = 0; i < distinctCount_semester; i++) {
        printf("%d ", distinctSemesters[i]);
    }
    printf("\n");






// int gender;
// int status;

// gender = (student[i].gender_status >> 7) & 1;  // Gender is 0 for Male and 1 for Female
// status = (student[i].gender_status >> 6) & 1;  // Status is 0 for Undergraduated and 1 for Postgraduated


fclose(input_file);
return 0;
}


