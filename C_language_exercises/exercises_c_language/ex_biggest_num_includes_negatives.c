#include <stdio.h>
#include <ctype.h>
#include <limits.h>

int main() {
    // char str[] = "-1,-2,asdf,,-99,asdfasgadg";
    char str[] = "The largest number in -1234 is -5678 and -999 is larger than -12345";

    int maxNumber = INT_MIN;  // Initialize to the smallest possible integer value
    int currentNumber = 0;  // Variable to store the current number being processed

    int i = 0;  // Iterator for the string

    while (str[i] != '\0') {
        if (isdigit(str[i]) || (str[i] == '-' && isdigit(str[i + 1]))) {
            // Found a digit or a negative number
            int isNegative = 0;
            if (str[i] == '-') {
                isNegative = 1;
                i++;  // Move past the '-' sign
            } 
            
            // Start building the currentNumber
            currentNumber = 0;
            while (isdigit(str[i])) {
                currentNumber = currentNumber * 10 + (str[i] - '0');
                i++;
            }
            
            // Apply the negative sign if necessary
            if (isNegative) {
                currentNumber = -currentNumber;
            }

            // Check if the current number is larger than the maxNumber
            if (currentNumber > maxNumber) {
                maxNumber = currentNumber;
            }
        } else {
            i++;  // Move to the next character
        }
    }

    if (maxNumber == INT_MIN) {
        printf("No valid numbers found in the string.\n");
    } else {
        printf("The largest number in the string is: %d\n", maxNumber);
    }

    return 0;
}
