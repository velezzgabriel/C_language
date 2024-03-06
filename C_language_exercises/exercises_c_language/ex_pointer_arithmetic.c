#include <stdio.h>


int main(){

        printf("-------------------------------------------1\n");
//1. Exercise (Little Endian):
        int num = 0x41424344;    // ASCII for 'ABCD'
        unsigned char *p = (unsigned char *)&num;
        printf("%c\n", *p);         //output: D

        printf("--------------------------------------------2\n");
//2. Exercise (Big Endian):
        // int num2 = 0x41424344;      // ASCII for 'ABCD'
        int num2 = 0x44434241;         // flipped to simulate big endian
        unsigned char *p2 = (unsigned char *)&num2;
        printf("%c\n", *p2);           //output: A
    
        printf("--------------------------------------------3\n");
//3. Exercise (Little Endian):
        int num3  =   0x45464748;         // ASCII for 'EFGH'
        unsigned char *p3 = (unsigned char *)&num3 + 2;
        printf("%c\n", *p3);                //output: F

        printf("--------------------------------------------4\n");
//4.Exercise (Big Endian):
        // int num4 = 0x45464748;      // ASCII for 'EFGH'
        int num4 = 0x48474645;      // flipped to simulate big endian
        unsigned char *p4 = (unsigned char *)&num4 + 1;
        printf("%c\n", *p4);                //output: F

        printf("--------------------------------------------5\n");
//5. Exercise (Little Endian):
        int num5 = 0x494A4B4C;            // ASCII for 'IJLK'
        unsigned char *p5 = (unsigned char *)&num5 + 3;
        printf("%c\n", *p5);                //output: I

        printf("--------------------------------------------6\n");
//6. Exercise (Big Endian):
        // int num6 = 0x494A4B4C;  // ASCII for 'IJLK'
        int num6 = 0x4C4B4A49;  // flipped to simulate big endian
        unsigned char *p6 = (unsigned char *)&num6 + 2;
        printf("%c\n", *p6);                //output: K

        printf("--------------------------------------------7\n");
//7. Exercise (Big Endian):
        // int num7 = 0x12345678;
        int num7 = 0x78563412;      // flipped to simulate big endian
        unsigned char *p7 = (unsigned char *)&num7;
        printf("%x\n", *p7);                    //output: 12

        printf("--------------------------------------------7_2\n");
// 7_2.What is printed to the console in a little-endian system?
        int num7_2 = 0x12345678;    
        unsigned char *p7_2 = (unsigned char *)&num7_2;
        printf("%x\n", *p7_2);                  //output: 78

        printf("--------------------------------------------8\n");
//8. Exercise (Little Endian):
    // this is an array so the elements are saved in the same order but their bits are the ones written backwards in memory.
    int arr[5] = {10, 20, 30, 40, 50}; 
    int *p8 = arr;
    printf("%d\n", *(p8 + 4 - 2));          //output: 30



//9. practica CON PUNTERO = CHAR
printf("--------------------------------------------9\n");
    typedef struct {
    int first_number;
    int second_number;
    } MyStruct;

    MyStruct my_struct;
    char *ptr = (char*) &my_struct;

    my_struct.first_number = 0x11223344;

    // my_struct.second_number = 0xAABBCCDD;       //output: FFFFFFAA
    // my_struct.second_number = 0xFFBBCCDD;       //output: FFFFFFFF
    // my_struct.second_number = 0x7FBBCCDD;       //output: 7F
    // my_struct.second_number = 0x99BBCCDD;       //output: FFFFFF99
    // my_struct.second_number = 0x11BBCCDD;        //output: 11
    my_struct.second_number = 0xAABBCCDD;        //output: FFFFFFAA
    printf("%02X\n", *(ptr + 7));             


    my_struct.first_number = 0x11223344;
    my_struct.second_number = 0xAABBCCDD;        //output: FFFFFFBB
    printf("%02X\n", *(ptr + 6));             


    my_struct.first_number = 0x11223344;
    my_struct.second_number = 0xAABBCCDD;        //output: 33
    printf("%02X\n", *(ptr + 1)); 

    my_struct.first_number = 0x11223380;
    my_struct.second_number = 0xAABBCCDD;        //output: FFFFFF80
    printf("%02X\n", *(ptr)); 


// 9_2.   practica CON PUNTERO = SHORT
printf("--------------------------------------------9_2\n");
    MyStruct my_struct_2;

    short *ptr2 = (short*) &my_struct_2;


// next ones DONT fit within the positive numbers of the short type. > 0x7FFF
    my_struct_2.first_number = 0x8000EEFF;
    my_struct_2.second_number = 0xAABBCCDD;       
    printf("%02X\n", *(ptr2 + 0));      //output: FFFFEEFF
    printf("%02X\n", *(ptr2 + 1));      //output: FFFF8000
    printf("%02X\n", *(ptr2 + 2));      //output: FFFFCCDD       
    printf("%02X\n", *(ptr2 + 3));      //output: FFFFAABB


// next ones all fit within the positive numbers of the short type. < 0x7FFF
    my_struct_2.first_number = 0x7F6F5F4E;
    my_struct_2.second_number = 0x7D7C7B7A;   
    printf("%02X\n", *(ptr2 + 0));      //output: 5F4E 
    printf("%02X\n", *(ptr2 + 1));      //output: 7F6F
    printf("%02X\n", *(ptr2 + 2));      //output: 7B7A 
    printf("%02X\n", *(ptr2 + 3));      //output: 7D7C      



    my_struct_2.first_number = 0x11223344;
    my_struct_2.second_number = 0xAABBCCDD;        //output: FFFFCCDD
    printf("%02X\n", *(ptr2 + 2));             

    my_struct_2.first_number = 0x11223344;
    my_struct_2.second_number = 0xAABBCCDD;        //output: FFFFAABB
    printf("%02X\n", *(ptr2 + 3)); 

    my_struct_2.first_number = 0x11223380;
    my_struct_2.second_number = 0xAABBCCDD;        //output: 3380
    printf("%02X\n", *(ptr2)); 



// 9_3.   practica CON PUNTERO = INTEGER
printf("--------------------------------------------9_3\n");
    MyStruct my_struct_3;

    unsigned char *ptr3 = (unsigned char*) &my_struct_3;


// next ones DONT fit within the positive numbers of the int type. > 0x7FFFFFFF
    my_struct_3.first_number = 0x8000EEFF;
    my_struct_3.second_number = 0xAABBCCDD;       
    printf("%02X\n", *(ptr3 + 0));      //output: 8000EEFF
    printf("%02X\n", *(ptr3 + 1));      //output: AABBCCDD


// next ones all fit within the positive numbers of the int type. < 0x7FFFFFFF
    my_struct_3.first_number = 0x7F6F5F4E;
    my_struct_3.second_number = 0x7D7C7B7A;   
    printf("%02X\n", *(ptr3 + 0));      //output:  7F6F5F4E
    printf("%02X\n", *(ptr3 + 1));      //output:  7D7C7B7A



    my_struct_3.first_number = 0x80000000;
    my_struct_3.second_number = 0x7FFFFFFF;        
    printf("%02X\n", *(ptr3 + 0));       //output: 80000000
    printf("%02d\n", *(ptr3 + 0));       //output: -2147483648 

    my_struct_3.first_number = 0x80000000;
    my_struct_3.second_number = 0x7FFFFFFF;        //output: 
    printf("%02X\n", *(ptr3 + 1));       //output: 7FFFFFFF
    printf("%02d\n", *(ptr3 + 1));       //output: 2147483647


//10. pointer as CHAR
printf("--------------------------------------------10\n");
    typedef struct {
        char a;
        int b;
        short c;
    } MyNewStruct;


    MyNewStruct s;

    s.a = 0x7F;    
    s.b = 0x11223344;
    s.c = 0x8001;   

    char *ptr4 = (char*) &s;
//     // printf("%02X\n", (int)*(short*)(ptr4 + 5));   //output: 2233
//     // printf("ex:  %02X\n", (short)*(int*)(ptr4 + 4));   //output: 3344
//     // printf("ex: %02x\n", (int)*(int*)(ptr4 + 1));   //output: 44000000
//     // printf("ex: %02x\n", (int)*(int*)(ptr4 + 6));   //output: 80011122

// printf("UNSIGNED CHAR...........\n");
//    unsigned char *ptr4 = (char*) &s;
    printf("%02X\n", (int)*(short*)(ptr4 + 5));   //output: 2233
    printf("ex:  %02X\n", (short)*(int*)(ptr4 + 4));   //output: 3344
    printf("ex: %02x\n", (int)*(int*)(ptr4 + 1));   //output: 44010000
    printf("ex: %02x\n", (int)*(int*)(ptr4 + 6));   //output: 80011122


//10_2 pointer as SHORT
printf("--------------------------------------------10_2\n");

    MyNewStruct s2;
    short *ptr5 = (short*) &s2;

    s2.a = 0x80;        //char
    s2.b = 0x11223344;  //int
    s2.c = 0x8001;      //short

//------------------- cast from SHORT to SHORT to INT    
    printf("%02X\n", (int)*(short*)(ptr5 + 0));   //output: 80

//------------------- cast from SHORT to INT to SHORT    
    printf("%02X\n", (short)*(int*)(ptr5 + 1));   //output: 00

//------------------- cast from SHORT to INT to INT   
    printf("%02x\n", (int)*(int*)(ptr5 + 0));   //output: 80
    printf("%02x\n", (int)*(int*)(ptr5 + 1));   //output: 33440000





    return 0;
    
}