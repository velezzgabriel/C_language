

#include <stdio.h>

#define MAX_SIZE 301

void insert_beg(int *array, int *ptr_curr_size_array, int value)
{   
    // Check if the array is already full
    if (*ptr_curr_size_array >= MAX_SIZE) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }

    // Shift the existing elements to the right to make space for the new value
    for (int i = *ptr_curr_size_array; i > 0; i--) {
        array[i] = array[i - 1];
    }

    // Insert the new value at the beginning
    array[0] = value;

    // Update the size of the array
    (*ptr_curr_size_array)++;
}

//--------------------------------------------------------------------------

void insert_end(int *array, int *ptr_curr_size_array, int value) {
    
    int curr_size = *ptr_curr_size_array;

    // Check if the array is already full
    if (curr_size >= MAX_SIZE) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }

    // Insert the value at the end of the array
    array[curr_size] = value;

    // Increment the size of the array
    (*ptr_curr_size_array)++;
}


//--------------------------------------------------------------------------

void insert_index(int *array, int *ptr_curr_size_array, int value, int position) 
{
    int curr_size = *ptr_curr_size_array;

    if (curr_size >= MAX_SIZE) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }

    if (position < 0 || position > curr_size) {
        printf("Invalid position for insertion.\n");
        return;
    }

    // Shift elements to the right to make space for the new value
    for (int i = curr_size; i > position; i--) {
        array[i] = array[i - 1];
    }

    // Insert the new value at the specified position
    array[position] = value;

    // Increment the size of the array
    (*ptr_curr_size_array)++;
}


//--------------------------------------------------------------------------


void delete_beg(int *array, int *ptr_curr_size_array) {
    int curr_size = *ptr_curr_size_array;

    if (curr_size <= 0) {
        printf("Array is empty. Cannot delete from an empty array.\n");
        return;
    }

    // Shift elements to the left to remove the first element
    for (int i = 0; i < curr_size - 1; i++) {
        array[i] = array[i + 1];
    }

    // Decrement the size of the array
    (*ptr_curr_size_array)--;
}


//--------------------------------------------------------------------------



void delete_end(int *array, int *ptr_curr_size_array) {
    int curr_size = *ptr_curr_size_array;

    if (curr_size <= 0) {
        printf("Array is empty. Cannot delete from an empty array.\n");
        return;
    }

    // Decrement the size of the array to remove the last element
    (*ptr_curr_size_array)--;
}


//--------------------------------------------------------------------------


void delete_index(int *array, int *ptr_curr_size_array, int position) {
    int curr_size = *ptr_curr_size_array;

    if (curr_size <= 0) {
        printf("Array is empty. Cannot delete from an empty array.\n");
        return;
    }

    if (position < 0 || position >= curr_size) {
        printf("Invalid position for deletion.\n");
        return;
    }

    // Shift elements to the left to remove the element at the specified position
    for (int i = position; i < curr_size - 1; i++) {
        array[i] = array[i + 1];
    }

    // Decrement the size of the array
    (*ptr_curr_size_array)--;
}

//--------------------------------------------------------------------------

void update(int *array, int *ptr_curr_size_array, int position, int value) {
    int curr_size = *ptr_curr_size_array;

    if (position < 0 || position >= curr_size) {
        printf("Invalid position for update.\n");
        return;
    }

    // Update the element at the specified position with the new value
    array[position] = value;
}


//--------------------------------------------------------------------------



void print_custom(int *array, int *ptr_curr_size_array) {
    int curr_size = *ptr_curr_size_array;

    if (curr_size <= 0) {
        printf("Array is empty. Nothing to print_custom.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < curr_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}


//--------------------------------------------------------------------------


int search(int *array, int *ptr_curr_size_array, int target) {
    int curr_size = *ptr_curr_size_array;

    for (int i = 0; i < curr_size; i++) {
        if (array[i] == target) {
            printf("indexof target = %d\n", i);
            return i;  // Element found, return its index
        }
    }
    return -1;  // Element not found, return -1 to indicate failure
}


//--------------------------------------------------------------------------

int main()
{

#include <stdio.h>

#define MAX_SIZE 301

// definitions of the arrays......
int array1[MAX_SIZE] = {99};
int curr_size = 1;

//
printf("array1.......... \n");
print_custom (array1, &curr_size);
printf("\n");



// print_custom testing
int cuantos = 300;
for (int i=0 ; i<cuantos; i++){
    insert_beg(array1,&curr_size,i);
}

for (int i=0 ; i<cuantos; i++){
    insert_end(array1,&curr_size,i+50);
}


for (int i=0 ; i<cuantos; i++){
    insert_index(array1,&curr_size,i+100,i);
}



//-----------------------------------------------------
int borrar_cuantos = 50;
for (int i=0 ; i<borrar_cuantos; i++){
    delete_beg(array1,&curr_size);
} 

for (int i=0 ; i<borrar_cuantos; i++){
    delete_end(array1,&curr_size);
} 

for (int i=0 ; i<borrar_cuantos; i++){
    delete_index(array1,&curr_size,i);
} 

//-----------------------------------------------------


update (array1, &curr_size, 0, 1);
    
    
search (array1, &curr_size, 1);


//---------------------------------
// print_custom testing
printf("array1.......... \n");
print_custom (array1, &curr_size);
printf("\n");


    return 0;
}
