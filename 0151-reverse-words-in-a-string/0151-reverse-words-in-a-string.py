# SOL1) -gpt4

class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.strip().split() # Split the string into words
        return ' '.join(reversed(words)) # Reverse the order of the words and join them
    
    
    
#     s.strip(): This method removes any leading and trailing whitespace characters from the string s. Whitespace characters include spaces, tabs, and newline characters.

# .split(): This method splits the string into a list of substrings based on a specified delimiter. By default, if no delimiter is provided, it splits the string using any consecutive whitespace characters (including spaces, tabs, and newlines) as the delimiter.


# s = "  hello world  "
# words = s.strip().split()
# print(words)  # Output: ['hello', 'world']

# First, s.strip() removes the leading and trailing spaces, resulting in "hello world".
# Then, .split() splits the string at the space between "hello" and "world", resulting in the list ['hello', 'world'].