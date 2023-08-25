class Solution {
public:
    string reverseWords(string s) {
        string result;
        int i = s.size() - 1;

        // Iterate from the end of the string
        while (i >= 0) {
            while (i >= 0 && s[i] == ' ') i--; // Skip spaces
            if (i < 0) break; // Check if only spaces were found // 스페이스만 있던 경우는 아예 밖의 while문을 빠져나옴
            int end = i; // Mark the end of a word
            while (i >= 0 && s[i] != ' ') i--; // Find the start of the Current word
            result += s.substr(i + 1, end - i) + ' '; // Add the word and a space
                    // e. Extract and Add the Word: The line result += s.substr(i + 1, end - i) + ' '; extracts the word using the substr method and adds it to the result string along with a space. The word is extracted from i + 1 to end, and the space is appended to separate the words in the reversed string.
        }
        


        // Remove trailing space if present and result is not empty  // trailing은 leading의 반대로 마지막에 있는 스페이스
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
