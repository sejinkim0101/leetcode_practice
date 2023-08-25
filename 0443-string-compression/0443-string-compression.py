class Solution:
    def compress(self, chars: List[str]) -> int:
        write = read = 0
        n = len(chars)

        while read < n:
            currentChar = chars[read]
            count = 0

            # Count consecutive repeating characters
            while read < n and chars[read] == currentChar:
                read += 1
                count += 1

            # Write the character
            chars[write] = currentChar
            write += 1

            # Write the count if greater than 1
            if count > 1:
                for digit in str(count):
                    chars[write] = digit
                    write += 1

        return write
