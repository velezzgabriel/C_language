#include <stdio.h>
#include <stdlib.h>

void reverseArray(int **array, int *max_size) {
    int start = 0;
    int end = max_size - 1;

    while (start < end) {
        // Swap the elements at the start and end indices
        int temp = (*array)[start];
        (*array)[start] = (*array)[end];
        (*array)[end] = temp;

        start++;
        end--;
    }
}

void realloc_for_insert (int **array, int *max_size){
    // The array is full; let's increase its size
    *max_size *= 2;

    // Use realloc to resize the array
    int *new_array = (int *)realloc(*array,*max_size * sizeof(int));
    if (new_array == NULL) {
        // Handle realloc failure
        printf("Realloc failed. No memory available.\n");
    }

    *array = new_array; // Update the pointer to the new memory block
}

//--------------------------------------------------------

void realloc_for_delete (int **array, int *max_size){

    *max_size = *max_size / 2;

    int *new_array = (int *)realloc(*array, (*max_size) * sizeof(int));
    if (new_array == NULL) {
        printf("Realloc failed. No memory available.\n");
    }

    *array = new_array;

}


//--------------------------------------------------------
void insert_beg_dinamic(int **array, int *curr_size_dinamic, int *max_size, int value) {
    if (*curr_size_dinamic >= *max_size) {

        realloc_for_insert(array, max_size);
    }

    // Shift the existing elements to the right to make space for the new value
    for (int i = *curr_size_dinamic; i > 0; i--) {
        (*array)[i] = (*array)[i - 1];
    }

    // Insert the new value at the beginning
    (*array)[0] = value;

    // Update the size of the array

    (*curr_size_dinamic)++;
}


//--------------------------------------------------------
void insert_end_dinamic(int **array, int *curr_size_dinamic, int *max_size, int value) 
{
    // Check if the array is already full
    if (*curr_size_dinamic >= *max_size) {
        realloc_for_insert(array, max_size);

    // The array is full; let's increase its size
        // *max_size *= 2;
    }

    // Insert the value at the end of the array
    (*array)[*curr_size_dinamic] = value;

    // Increment the size of the array
    (*curr_size_dinamic)++;
}


//--------------------------------------------------------
void insert_index_dinamic(int **array, int *curr_size_dinamic, int *max_size, int value, int position) 
{
    
    // Check if the array is already full
    if (*curr_size_dinamic >= *max_size) {
        realloc_for_insert(array, max_size);

        // *max_size *= 2;
    }

    if (position < 0 || position > *max_size) {
        printf("Invalid position for insertion.\n");
        return;
    }

    // Shift elements to the right to make space for the new value
    int i;
    for (i = *curr_size_dinamic; i > position; i--) {
        (*array)[i] = (*array)[i - 1];
    }

    // Insert the new value at the specified position
    (*array)[position] = value;

    // Increment the size of the array
    (*curr_size_dinamic)++;
}



//--------------------------------------------------------
void delete_beg_dinamic(int **array, int *curr_size_dinamic, int *max_size) {

    if (*curr_size_dinamic <= 0) {
        printf("Array is empty. Cannot delete from an empty array.\n");
        return;
    }

    // Shift elements to the left to remove the first element
    for (int i = 0; i < *curr_size_dinamic - 1; i++) {
        (*array)[i] = (*array)[i + 1];
    }

    // Decrement the size of the array
    (*curr_size_dinamic)--;

    
    // Downsize array if the current size fits in half the size of max_size
    if (*max_size / 2 > *curr_size_dinamic ){
        realloc_for_delete(array, max_size);
    }
}



//--------------------------------------------------------
void delete_end_dinamic(int **array, int *curr_size_dinamic, int *max_size) {

    if (*curr_size_dinamic <= 0) {
        printf("Array is empty. Cannot delete from an empty array.\n");
        return;
    }

    // Decrement the size of the array to remove the last element
    (*curr_size_dinamic)--;

    // Downsize array if the current size fits in half the size of max_size
    if (*max_size / 2 > *curr_size_dinamic ){
        realloc_for_delete(array, max_size);
    }
}


//--------------------------------------------------------
void delete_index_dinamic(int **array, int *curr_size_dinamic, int position, int *max_size) {

    if (*curr_size_dinamic <= 0) {
        printf("Array is empty. Cannot delete from an empty array.\n");
        return;
    }

    if (position < 0 || position >= *curr_size_dinamic) {
        printf("Invalid position for deletion.\n");
        return;
    }

    // Shift elements to the left to remove the element at the specified position
    for (int i = position; i < *curr_size_dinamic - 1; i++) {
        (*array)[i] = (*array)[i + 1];
    }

    // Decrement the size of the array
    (*curr_size_dinamic)--;

        // Downsize array if the current size fits in half the size of max_size
    if (*max_size / 2 > *curr_size_dinamic ){
        realloc_for_delete(array, max_size);
    }
}


//--------------------------------------------------------
void update_dinamic(int *array, int *curr_size_dinamic, int position, int value) {

    if (position < 0 || position >= *curr_size_dinamic) {
        printf("Invalid position for update.\n");
        return;
    }

    // Update the element at the specified position with the new value
    array[position] = value;
}


//--------------------------------------------------------
void print_dinamic(int *array, int *curr_size_dinamic) {

    if (*curr_size_dinamic <= 0) {
        printf("Array is empty. Nothing to print.\n");
        return;
    }

    printf("Array elements: \n");
    for (int i = 0; i < *curr_size_dinamic; i++) {
        printf("%d \n", array[i]);
    }
    printf("\n");
}



//--------------------------------------------------------
int search_dinamic(int *array, int *curr_size_dinamic, int target) {

    for (int i = 0; i < *curr_size_dinamic; i++) {
        if (array[i] == target) {
            printf("Index of target = %d\n", i);
            return i;  // Element found, return its index
        }
    }
    printf("Element %d not found\n", target);
    return -1;  // Element not found, return -1 to indicate failure
}




//////////////////////////////////////////////////////////////////////////
int main()
{

// array definition...................................
int* buffer_array_1 ;
int curr_size_dinamic1 = 0;
int max_size1;



printf ("What is the max_size1 for array_1?");
    scanf("%d", &max_size1);

    buffer_array_1 = (int*) malloc(max_size1 * sizeof(int));

    if (buffer_array_1 == NULL){
        printf("memory was not allocated");
        return 1;
    }

//---------------------------------------------------------

int cuantos = 10;
for (int i=0 ; i<cuantos; i++){
    insert_beg_dinamic(&buffer_array_1, &curr_size_dinamic1, &max_size1 , i);
}

// for (int i=0 ; i<cuantos; i++){
//     insert_end_dinamic(&buffer_array_1, &curr_size_dinamic1, &max_size1 , i);
// }

// for (int i=0 ; i<cuantos; i++){
//     insert_index_dinamic(&buffer_array_1, &curr_size_dinamic1, &max_size1 , i, i);
// }


//--------------------------------------------------------

int borrar_cuantos = 125;
// for (int i=0 ; i<borrar_cuantos; i++){
//     delete_beg_dinamic(&buffer_array_1, &curr_size_dinamic1, &max_size1);
// } 

// for (int i=0 ; i<borrar_cuantos; i++){
//     delete_end_dinamic(&buffer_array_1, &curr_size_dinamic1, &max_size1);
// } 

// for (int i=0 ; i<borrar_cuantos; i++){
//     delete_index_dinamic(&buffer_array_1, &curr_size_dinamic1, i ,&max_size1);
// } 

//--------------------------------------------------------

// update_dinamic (buffer_array_1, &curr_size_dinamic1, 0, 1);
// update_dinamic (buffer_array_1, &curr_size_dinamic1, 1, 2);
// update_dinamic (buffer_array_1, &curr_size_dinamic1, 2, 3);
// update_dinamic (buffer_array_1, &curr_size_dinamic1, 3, 4);
// update_dinamic (buffer_array_1, &curr_size_dinamic1, 4, 5);
    
search_dinamic (buffer_array_1, &curr_size_dinamic1, 1);


//---------------------------------------------------------
// print testing
print_dinamic (buffer_array_1, &curr_size_dinamic1);
printf("\n");
printf("current size:  %d\n\n", curr_size_dinamic1);
printf("current max_size:  %d\n\n", max_size1);

//---------------------------------------------------------


reverseArray(buffer_array_1,&curr_size_dinamic1);


//---------------------------------------------------------
// print testing
print_dinamic (buffer_array_1, &curr_size_dinamic1);
printf("\n");
printf("current size:  %d\n\n", curr_size_dinamic1);
printf("current max_size:  %d\n\n", max_size1);
//---------------------------------------------------------

    

free(buffer_array_1);
return 0;

}
