// sol1- GPT4

#include <string>

class Solution {
public:
    int maxVowels(std::string s, int k) {
        int vowelCount = 0;
        
        // Check if a character is a vowel
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        // Count the vowels in the first k characters
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) vowelCount++;
        }
        
        int maxVowels = vowelCount;

        // Slide the window over the string
        for (int i = k; i < s.size(); i++) {
            // Add the current character if it's a vowel
            if (isVowel(s[i])) vowelCount++;
            // Subtract the first character of the previous window if it's a vowel
            if (isVowel(s[i - k])) vowelCount--;
            
            // Update the maximum count if the new count is greater
            if (vowelCount > maxVowels) maxVowels = vowelCount;
        }

        return maxVowels;
    }
};
