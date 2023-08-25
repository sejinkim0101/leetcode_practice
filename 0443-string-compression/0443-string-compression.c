// SOL1) -GPT4

int compress(char* chars, int charsSize) {
    int write = 0, read = 0;

    while (read < charsSize) {
        char currentChar = chars[read];
        int count = 0;

        // Count consecutive repeating characters
        while (read < charsSize && chars[read] == currentChar) {
            read++;
            count++;
        }

        // Write the character
        chars[write++] = currentChar;

        // Write the count if greater than 1
        if (count > 1) {
            int len = 0, tempCount = count;

            // Calculate the length of the count
            while (tempCount) {
                len++;
                tempCount /= 10;
            }

            // Write the digits in reverse order
            int position = write + len - 1;
            while (count) {
                chars[position--] = (count % 10) + '0';
                count /= 10;
            }

            write += len; // Move the write pointer
        }
    }

    return write;
}


// before modify


// int compress(char* chars, int charsSize) {
//     int write = 0, read = 0;

//     while (read < charsSize) {
//         char currentChar = chars[read];
//         int count = 0;

//         // Count consecutive repeating characters
//         while (read < charsSize && chars[read] == currentChar) {
//             read++;
//             count++;
//         }

//         // Write the character
//         chars[write++] = currentChar;

//         // Write the count if greater than 1
//         if (count > 1) {
//             sprintf(chars + write, "%d", count);
//             write += strlen(chars + write);
//         }
//     }

//     return write;
// }
