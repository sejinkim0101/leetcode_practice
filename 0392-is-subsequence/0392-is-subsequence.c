// SOL1) - GPT4

bool isSubsequence(char * s, char * t) {
    int i = 0; // Initialize pointer for iterating through string s
    int j = 0; // Initialize pointer for iterating through string t
    
    // Iterate through both strings
    while (s[i] != '\0' && t[j] != '\0') { // 이 줄 작동 방식 정확히 알기...! (while 문이면서 i++ 과 j++ 이 모두 들어가있으니 괜찮은 것)
        // If characters match, move to the next character in string s
        if (s[i] == t[j]) {
            i++;
        }
        // Always move to the next character in string t // 매칭 여부와 상관없이 이동하는 것
        j++;
    }
    
    // If we've reached the end of string s, that means every character in s was found in t, in order
    return s[i] == '\0';
}

//SOL2) Leetcode Discussion

// https://leetcode.com/problems/is-subsequence/discuss/2473010/Very-Easy-oror-100-oror-Fully-Explained-oror-Java-C%2B%2B-Python-JS-C-Python3-(Two-Pointers-Approach)

// bool isSubsequence(char * s, char * t){
//     // Initialize two pointers i and j storing the last indices of both the strings...
//         int i = strlen(s) , j = strlen(t);
//         i-- , j--;
//         // Iterate until either of them becomes zero...
//         while(i >= 0 && j >= 0) {
//             // Compare characters...
//             if(s[i] == t[j])
//                 i-- , j--;
//             else
//                 j--;
//         }
//         // If i (pointer of the first string) is greater than or equal to 0...
//         // we have not been able to traverse the first string completely...
//         // Hence, it is not a subsequence of the second...
//         if(i >= 0)
//             return false;
//         return true;        // Otherwise, return true...
// }