#include <stdio.h> 
#include <stdlib.h> 
#include <stdint.h> 

// declare structs
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

// header info..
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

// -------------> DISTINCT YEARS ARRAY
    int *distinct_years = NULL;
    int distinctCount_year = 0;
    int max_years = 1; // initial size
    int length_distinct_years = max_years; //initial length

    distinct_years = (int*) malloc (max_years * sizeof(int));

    if (distinct_years == NULL){
        printf("Memory allocation failed. \n");
        return 1;
    }

    // Iterate through enrollment struct
    for (int i = 0; i < enrollment_count; i++) {
        int year = enrollment[i].year;
        int isDistinct = 1; // Assume the year is distinct
        // Check if year already exists in the distinct years array
        for (int j = 0; j < distinctCount_year; j++) {
            if (distinct_years[j] == year) {
                isDistinct = 0; // The year is not distinct
            }
        }

        // Check if we need to resize the dynamic array
        if (distinctCount_year >= max_years) {
            max_years *= 2; // Double the size
            distinct_years = (int *)realloc(distinct_years, max_years * sizeof(int));

            if (distinct_years == NULL) {
                printf("Memory reallocation failed.\n");
                return 1;
            }

            length_distinct_years = max_years; // Update length
        }

        // If the year is distinct, add it to the distinct years array
        if (isDistinct) {
            distinct_years[distinctCount_year] = year;
            distinctCount_year++;
        }
    }


// ------------->  DISTINCT SEMESTERS ARRAY
    int *distinct_semesters = NULL;
    int number_of_distinct_semesters = 0;
    int max_semesters = 1; // initial size 
    int length_distinct_semesters = max_semesters; // initial length

    distinct_semesters = (int *)malloc(max_semesters * sizeof(int));

    if (distinct_semesters == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Iterate through enrollments to find distinct semesters
    for (int i = 0; i < enrollment_count; i++) {
        int semester = enrollment[i].semester;
        int isDistinct = 1; // Assume the semester is distinct

        // Check if the semester already exists in the dynamic array
        for (int j = 0; j < number_of_distinct_semesters; j++) {
            if (distinct_semesters[j] == semester) {
                isDistinct = 0; // semester is not distinct
                break;
            }
        }

        // Check if we need to resize the dynamic array
        if (number_of_distinct_semesters >= max_semesters) {
            max_semesters *= 2; // Double the size
            distinct_semesters = (int *)realloc(distinct_semesters, max_semesters * sizeof(int));

            if (distinct_semesters == NULL) {
                printf("Memory reallocation failed.\n");
                return 1;
            }

            length_distinct_semesters = max_semesters; // Update the length variable
        }

        // Add distinct semester to the dynamic array
        if (isDistinct) {
            distinct_semesters[number_of_distinct_semesters] = semester;
            number_of_distinct_semesters++;
        }
    }

// Create a struct to store the total_students_year_semester of distinct student IDs per year per semester
struct DistinctStudentCount {
    int year;
    int semester;
    int student_id_struct;
};

// Create an array to store the total_students_year_semester of distinct student IDs per year per semester
struct DistinctStudentCount* distinctStudentCounts = (struct DistinctStudentCount*)malloc(distinctCount_year * number_of_distinct_semesters * sizeof(struct DistinctStudentCount));

if (distinctStudentCounts == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
}

int distinct_structArray_index = 0;

//print header of the table for task 3
printf("Year  Semester  Male Undergrad  Female Undergrad  Male Postgrad  Female Postgrad\n");

// Iterate through each distinct year and semester combination
for (int i = 0; i < distinctCount_year; i++) {
        int year = distinct_years[i];

    for (int j = 0; j < number_of_distinct_semesters; j++) {
        
        free(distinctStudentCounts);
        struct DistinctStudentCount* distinctStudentCounts = (struct DistinctStudentCount*)malloc(distinctCount_year * number_of_distinct_semesters * sizeof(struct DistinctStudentCount));

        if (distinctStudentCounts == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        int semester = distinct_semesters[j];
        int male_underg = 0;
        int female_underg = 0;
        int male_postg = 0 ;
        int female_postg = 0 ;

       // Iterate through enrollment to find distinct student IDs
        for (int k = 0; k < enrollment_count; k++) {
            if (enrollment[k].year == year && enrollment[k].semester == semester) {
                                
                int studentID_enrollment = enrollment[k].student_id;
                int isDistinct = 1;                         // Assume student ID is distinct

                // Check if the student ID already exists in the array of distinct structs
                for (int l = 0; l < distinct_structArray_index; l++) {
                    if (distinctStudentCounts[l].year == year && distinctStudentCounts[l].semester == semester) {
                        if (studentID_enrollment == distinctStudentCounts[l].student_id_struct) {
                            isDistinct = 0; // Student ID is not distinct
                        }
                    }
                }

                if (isDistinct) {
                    distinctStudentCounts[distinct_structArray_index].year = year;
                    distinctStudentCounts[distinct_structArray_index].semester = semester;
                    distinctStudentCounts[distinct_structArray_index].student_id_struct = studentID_enrollment;
                    distinct_structArray_index++;
                
                    int gender;
                    int status;
                    gender = (student[studentID_enrollment-1].flags >> 7) & 1;  // Gender is 0 for Male and 1 for Female
                    status = (student[studentID_enrollment-1].flags >> 6) & 1;  // Status is 0 for Undergraduated and 1 for Postgraduated

                    switch (gender){
                        case 0:
                            // if to count approved and not approved males
                            if(status == 0){
                                male_underg++;
                            }else{
                                male_postg++;
                            }
                            break;

                        case 1:
                            // if to count approved and not approved females
                            if(status == 0){
                                female_underg++;
                            }else{
                                female_postg++;
                            }
                            break;
                    }
                }
            }
        }
        //print year,semester and flags values
        printf("%-8d %-12d %-15d %-17d %-15d %-14d\n", year, semester, male_underg, female_underg, male_postg, female_postg);
    }
}

// Free dynamic arrays 
free(distinctStudentCounts);
free(distinct_years);
free(distinct_semesters);

// close 
fclose(input_file);
return 0;
}