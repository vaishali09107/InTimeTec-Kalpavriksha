#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int length(char *string) {
    int i = 0, len = 0;
    while (string[i] != '\0') {
        len++;
        i++;
    }
    return len;
}

void stringCopy(char *dest, char *source) {
    while (*source != '\0') {
        *dest = *source;
        dest++;
        source++;
    }
    *dest = '\0';
}

int isAlnum(char ch) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
        return 1;  
    }
    return 0;
}

void longestWord(char *string, char **result) {
    char *current = (char *)malloc(100 * sizeof(char));
    *result = (char *)malloc(100 * sizeof(char));
    int currentLen = 0, maxLen = 0;
    int i = 0, j = 0;
    
    while (string[i] != '\0') {
        if (isAlnum(string[i])) {
            current[j++] = string[i];
        } else {
            if (j > 0) {
                current[j] = '\0';
                currentLen = length(current);
                if (currentLen > maxLen) {
                    maxLen = currentLen;
                    stringCopy(*result, current);
                }
                j = 0;
            }
        }
        i++;
    }
    
    if (j > 0) {
        current[j] = '\0';
        currentLen = length(current);
        if (currentLen > maxLen) {
            stringCopy(*result, current);
        }
    }
    
    free(current);
}

int main() {
    char *string = (char *)malloc(100 * sizeof(char));
    char *result = NULL;
    if (string == NULL) {
        return 1;
    }
    
    scanf("%[^\n]", string);
    printf("Input String: %s\n", string);
    if (string[0] == '\0') {
        return 1;
    }
    
    longestWord(string, &result);
    printf("Longest Word: %s\n", result);
    
    free(string);
    free(result);
    return 0;
}
