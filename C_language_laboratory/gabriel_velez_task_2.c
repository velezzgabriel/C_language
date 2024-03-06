#include <stdio.h> 
#include <stdlib.h> 
#include <stdint.h> 


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



// TABLE RELATIONS

int course_student_count [50];
int course_age_sum [50];

for (int i=0; i < courses_count; i++){
    course_student_count[i] = 0;
    course_age_sum [i] = 0;

    for (int j=0; j<enrollment_count; j++){
        if (course[i].course_id == enrollment[j].course_id){
            
            for (int k=0; k< student_count; k++){
                if (enrollment[j].student_id == student[k].student_id ){
                course_student_count[i]++;
                course_age_sum [i] += student[k].student_age;
                    
                }
            }
        }
    }
}


    printf("%-32s Average Age\n", "Course Name");
    for (int i = 0; i < courses_count; i++) {
            float averageAge = (float)course_age_sum[i] / course_student_count[i];
            printf("%-32s %.2f\n", course[i].course_name, averageAge);
    }



fclose(input_file);
return 0;
}


