
#include <stdio.h>
#include <ctype.h>

// WATCH OUT!! negative numbers will be taken as positive numbers in this function.

int main() {
    char str[] = "-1,-2,0,1";
    // char str[] = "2024,4,25,1,22,7,10,0,333,2028";
    // char str[] = "The largest number in 1234 is 5678 and 999 is larger than 12345.";

    int maxNumber = 0;  // Variable to store the largest number
    int currentNumber = 0;  // Variable to store the current number being processed

    int i = 0;  // Iterator for the string

    while (str[i] != '\0') {
        if (isdigit(str[i])) {
            // Found a digit, start building the currentNumber
            currentNumber = 0;
            while (isdigit(str[i])) {
                currentNumber = currentNumber * 10 + (str[i] - '0');
                i++;
            }
            // Check if the current number is larger than the maxNumber
            if (currentNumber > maxNumber) {
                maxNumber = currentNumber;
            }
        } else {
            i++;  // Move to the next character
        }
    }

    printf("The largest number in the string is: %d\n", maxNumber);

    return 0;
}
