#include <stdio.h>
#include <string.h>


// ------------------------->  swap 

void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void swap2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}



// ------------------------->  string copy:
char *strcpy_custom(char *dest, const char *src) {
    char *original_dest = dest;
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // Null-terminate the destination string
    return original_dest;
}


// -------------------------> string length:
size_t strlen_custom(const char *str) {
    const char *s = str;
    while (*s) {
        s++;
    }
    return s - str;
}


// there are 2 compareString functions, one uses <string.h>, the other does not.
char *compareStrings(const char *str1, const char *str2) {
        int len1 = strlen(str1);
        int len2 = strlen(str2);

        if (len1 > len2) {
            return (char *)str1;
        } else if (len1 < len2) {
            return (char *)str2;
        } else {
            int cmp = strcmp(str1, str2);
            if (cmp >= 0) {  // if strings equal, returns pointer to str1
                return (char *)str1;
            } else {
                return (char *)str2;
            }
        }
    }

//-this is the second compareString function. This one does not use <string.h>
char *compareStrings2(const char *str1, const char *str2) {
    int len1 = 0;
    int len2 = 0;

    while (str1[len1] != '\0') {
        len1++;
    }

    while (str2[len2] != '\0') {
        len2++;
    }

    if (len1 > len2) {
        return (char *)str1;
    } else if (len1 < len2) {
        return (char *)str2;
    } else {
        int cmp = 0;
        for (int i = 0; i < len1; i++) {
            if (str1[i] != str2[i]) {
                cmp = str1[i] - str2[i];
                break;
            }
        }

        if (cmp >= 0) {
            return (char *)str1;
        } else {
            return (char *)str2;
        }
    }
}


// -----------------> string compare: returns greatest LEXICOGRAPHICALLY

int strcmp_custom(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
    //--> return *(unsigned char *)str1 - *(unsigned char *)str2;
}


// -------------------------> isalpha:
int isalpha_custom(int c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}


// -------------------------> isdigit:
int isdigit_custom(int c) {
    return c >= '0' && c <= '9';
}


/////////////////////////////////////////////////////////////////

int main() {
// -------------------------> swap 
    int x = 5;
    int y = 10;

    printf("Before swap: x = %d, y = %d\n", x, y);

    swap(&x, &y);

    printf("After swap: x = %d, y = %d\n", x, y);
// ------------------------->  string copy:
    char dest[50];
    const char *src = "Hello, World!";
    strcpy_custom(dest, src);
    printf("Copied string: %s\n", dest);


// -------------------------> string length:
    const char *str = "0000000009";
    int length = strlen_custom(str);
    printf("String length: %d\n", length);


//--->      string compare LONGEST, if same length, it returns greatest lexicographically
    const char *string1 = "applez";
    const char *string2 = "zbbbb";

    char *result = compareStrings(string1, string2);
    printf("Longest or lexicographically greater string: %s\n", result);


// -----------------> string compare: returns greatest LEXICOGRAPHICALLY
    const char *str1 = "zpplez";
    const char *str2 = "zbbbb";
    int result_compare = strcmp_custom(str1, str2);
    if (result_compare < 0) {
        printf("str1 is less than str2\n");
    } else if (result_compare > 0) {
        printf("str1 is greater than str2\n");
    } else {
        printf("str1 is equal to str2\n");
    }


// -------------------------> isalpha:
    int char_isalpha = '1';
    if (isalpha_custom(char_isalpha)) {
        printf("%c is an alphabet character.\n", char_isalpha);
    } else {
        printf("%c is not an alphabet character.\n", char_isalpha);
    }


// -------------------------> isdigit:
    int char_isdigit = '7';
    if (isdigit_custom(char_isdigit)) {
        printf("%c is a digit.\n", char_isdigit);
    } else {
        printf("%c is not a digit.\n", char_isdigit);
    }


}
