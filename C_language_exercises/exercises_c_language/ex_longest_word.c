#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[] = "??abc abcd, a-a\\&/(97) abcde abcdefh abcdefg zzzzz";

    char currentWord[100] = ""; // Store the current word
    char largestWord[100] = ""; // Store the longest word
    int i = 0; // Iterator for the string

    while (str[i] != '\0') {
        if (isalpha(str[i])) {
            // Found an alphabet character, add it to the current word
            int j = 0;
            while (isalpha(str[i])) {
                currentWord[j] = str[i];
                currentWord[j + 1] = '\0'; // Null-terminate the current word
                i++;
                j++;
            }
            // Compare the current word with the largest word
            if (strlen(currentWord) > strlen(largestWord) ||
                (strlen(currentWord) == strlen(largestWord) && strcmp(currentWord, largestWord) > 0)) {
                strcpy(largestWord, currentWord);
            }
        } else {
            i++; // Move to the next character
        }
    }

    printf("The lexicographically largest word in the string is: %s\n", largestWord);

    return 0;
}
