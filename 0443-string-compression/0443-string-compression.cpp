// sol1 - GPT4
class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0, read = 0, n = chars.size();

        while (read < n) {
            char currentChar = chars[read];
            int count = 0;

            // Count consecutive repeating characters
            while (read < n && chars[read] == currentChar) {
                read++;
                count++;
            }

            // Write the character
            chars[write++] = currentChar;

            // Write the count if greater than 1
            if (count > 1) {
                for (char digit : to_string(count)) {
                    chars[write++] = digit;
                }
            }
        }

        return write;
    }
};
