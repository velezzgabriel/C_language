//--------------------- fgets(variable to read into, number of chars, where to read from)

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char text[100]; // Declare an array to store characters
//     printf("Type a line of text here...");

//     fgets(text, 100, stdin);
//     int len = strlen(text); 
//     // text[len-1] = '\0'; // Remove the newline character

//     int i;
//     for (i = 0; i <= strlen(text); i++) {
//         printf("%c", text[i]); // Use "%d " to print ASCII values with spaces as separators
//     }

//     return 0;
// }



// --------->  fgets()  receives multiple lines of text....

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char text[100];
//     int line_number = 1;

//     printf("Enter multiple lines of text (Ctrl+D or Ctrl+Z to exit):\n");
    
//     while (fgets(text, 100, stdin) != NULL) {
//         int len = strlen(text); 
//         // text[len-1] = '\0'; // Remove the newline character
//         printf("Line %d: %s\n", line_number, text);
//         line_number++;
//     }

//     return 0;
// }




//------------------>  fgets()  read a .txt file

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char text[100];
//     int line_number = 1;

//     FILE *file = fopen("sample.txt", "r");
//     if (file == NULL) {
//         printf("Error opening the file.\n");
//         return 1;
//     }

//     while (fgets(text, 100, file) != NULL) {
//         int len = strlen(text); 
//         //text[len-1] = '\0'; // Remove the newline character
//         printf("Line %d: %s\n", line_number, text);
//         line_number++;
//     }

//     fclose(file);
//     return 0;
// }


