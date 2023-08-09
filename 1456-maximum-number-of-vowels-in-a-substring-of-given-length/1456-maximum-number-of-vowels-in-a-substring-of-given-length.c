// sol1- GPT4

#include <stdbool.h>

// Function to check if a character is a vowel
bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int maxVowels(char *s, int k) {
    int vowelCount = 0;
    
    // Count the vowels in the first k characters
    for (int i = 0; i < k; i++) {
        if (isVowel(s[i])) vowelCount++;
    }
    
    int maxVowels = vowelCount;

    // Slide the window over the string
    for (int i = k; s[i]; i++) {
        // Add the current character if it's a vowel
        if (isVowel(s[i])) vowelCount++;
        // Subtract the first character of the previous window if it's a vowel
        if (isVowel(s[i - k])) vowelCount--;
        
        // Update the maximum count if the new count is greater
        if (vowelCount > maxVowels) maxVowels = vowelCount;
    }

    return maxVowels;
}

