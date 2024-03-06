#include <stdio.h>


int main(){
    int a[] ={5,16,7,89,45,32,23,10};
    int *p = &a[1], *q = &a[5];

    printf("%4d\n", *(p+3) );       //-->  45
    printf("%5d\n", *(q-3));        //-->    7
    printf("%6d\n", q - p );        //-->     4
    printf("%7d\n", p < q );        //-->      1
    printf("%8d\n", *p < *q);       //-->       1

printf("--------------------------------------------------\n");

    printf("%04hd\n", *(p+3) );     //-->0045
    printf("%05hd\n", *(q-3));      //-->00007
    printf("%06hd\n", q - p );      //-->000004
    printf("%07hd\n", p < q );      //-->0000001
    printf("%08hd\n", *p < *q);     //-->00000001

printf("--------------------------------------------------\n");

    printf("%04x\n", *(p+3) );      //-->002d
    printf("%05x\n", *(q-3));       //-->00007
    printf("%06x\n", q - p );       //-->000004
    printf("%07x\n", p < q );       //-->0000001
    printf("%08x\n", *p < *q);      //-->00000001

printf("--------------------------------------------------\n");
 


//--------------------  POST INCREMENT and PRE INCREMENT

int array[] ={0,1,2,3,4,5,6};
int *ptr = &array[0];

// First prints "ptr" value, then increment "ptr" by 1. 
// NOTE! "ptr" is ASSIGNED with a new address
printf("%d\n", *(ptr++));   //-->0
printf("%d\n", *(ptr));     //-->1

// This ADDS "1" to the address TEMPORARILY , then fetches the value at the address
// NOTE!! this one does NOT MODIFY the address because it is not assigning it.
printf("%d\n", *(ptr+1));   //-->2


// see that "ptr" value is different to the previous print, because in the previous print the address was not being assigned with a new value, it was being increased temporarily to fetch the value of the address located "1" spot ahead.
printf("%d\n", *ptr );      //-->1


// ptr address goes back "1" spot before fetching the value.
// this ASSIGNS "ptr" with a new address.
printf("%d\n", *(--ptr) );  //-->0
printf("%d\n", *ptr );      //-->0
printf("%d\n", *(++ptr) );  //-->1



printf("--------------------------------------------------\n");


//-------------------- SUM ELEMENTS OF AN ARRAY

int array2[] = {0,1,2,3,4,5,6};
int sum = 0;
int *ptr2;

for (ptr2 = &array2[0]; ptr2 <= &array2[6]; ptr2++){
    sum+= *ptr2;}

printf("sum of elements: %d\n", sum);  // output: sum of elements: 21



// do it with a dinamic array size, defined by N
#define N 3

int array3[N];
int *ptr3;

printf("Insert %d elements in the array\n", N);
for (ptr3 = array3; ptr3 <= array3+ N -1; ptr3++){
    scanf("%x", ptr3);
}

printf("Elements in reverse order:\n");
for (ptr3 = array3+N-1; ptr3 >= array3; ptr3--){
    printf("%d\n", *ptr3);
}



//-------------------------  FIND ADDRESS OF NESTED ARRAY element

/*
In a given array int array[5][5] , find the address of array[5][5]. 

Formula would be:
&*(*(parent_array_address + index_to_find_in_parent_array * size_of_nested_array * #_or_bytes_of_elements_in_nested_array ) + index_to_find_in_nested_array *  #_or_bytes_of_elements_in_nested_array)


--> In the array:   int array[5][5]
--> Find:           array[2][2]

&*(*(array+2)+2)

--> Assume array address is 1000

&*(*(1000 + 2*5*4) + 2*4 )

&*(*(1040) + 8)     //--> because of being a an array of arrays, dereferencing it will give us an address too.

&*(1048)

&array[2][2] = 1048
*/



//------------------------  NESTED ARRAYS
unsigned int x[4][3] = {{1,2,3}, {4,5,6},{7,8,9},{10,11,12}};

printf("%u,\n%u,\n%u\n", x+3, *(x+3), *(x+2)+3);

/*

Assume of x = 2000
x   --> points to the 1st one-dimensional array

x+3 --> points to the 4th  one-dimensional array 
x+3 --> 2000 + 3*12(size of each one-dimensional array)
x+3 = 2036

--> Since this is an array of arrays, we could say it is an array of pointers to arrays.
Meaning, when we dereference x+3, it will give us the address of the first element in the 4th one-dimensional array, which is the same than the 4th array itself.
*(x+3)
*(x+3) -> 2036


--> from the previous excercise, we know that dereferencing  *(x+2) will give us the address to the 1st element in the 3rd one-dimensional array and NOT A VALUE. We then only need to increase that address by 3.
*(x+2)+3

*(x+2) = 2000 + 2*12    -->(12 is the size of one-dimensional array)

(2000 + 2*12) + 3*4     -->(4 is the size of one element in a one-dimensional array)

2024 + 12

2036

*(x+2)+3 = 2036

*/


    return 0;
}




