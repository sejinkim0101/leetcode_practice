#include <string.h>

char* reverseWords(char* s) {
    int n = strlen(s);
    char* result = (char*)malloc((n + 1) * sizeof(char));
    result[n] = '\0';
    int i = n - 1, j = 0;

    // Iterate from the end of the string
    while (i >= 0) {
        while (i >= 0 && s[i] == ' ') i--; // Skip spaces
        int end = i; // Mark the end of a word
        while (i >= 0 && s[i] != ' ') i--; // Find the start of the word
        for (int k = i + 1; k <= end; k++) result[j++] = s[k]; // Copy the word
        if (i >= 0) result[j++] = ' '; // Add a space after the word
    }

    // Remove trailing space if present
    if (j > 0 && result[j - 1] == ' ') j--;
    result[j] = '\0';

    return result;
}
