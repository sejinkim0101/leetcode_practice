class Solution {
public:
    string reverseWords(string s) {
        string result;
        int i = s.size() - 1;

        // Iterate from the end of the string
        while (i >= 0) {
            while (i >= 0 && s[i] == ' ') i--; // Skip spaces
            if (i < 0) break; // Check if only spaces were found
            int end = i; // Mark the end of a word
            while (i >= 0 && s[i] != ' ') i--; // Find the start of the word
            result += s.substr(i + 1, end - i) + ' '; // Add the word and a space
        }

        // Remove trailing space if present and result is not empty
        if (!result.empty()) {
            result.pop_back();
        }

        return result;
    }
};


// before modify
// class Solution {
// public:
//     string reverseWords(string s) {
//         string result;
//         int i = s.size() - 1;

//         // Iterate from the end of the string
//         while (i >= 0) {
//             while (i >= 0 && s[i] == ' ') i--; // Skip spaces
//             int end = i; // Mark the end of a word
//             while (i >= 0 && s[i] != ' ') i--; // Find the start of the word
//             result += s.substr(i + 1, end - i) + ' '; // Add the word and a space
//         }

//         // Remove trailing space if present
//         result.pop_back();

//         return result;
//     }
// };
