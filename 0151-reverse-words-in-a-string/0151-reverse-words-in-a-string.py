# SOL1) -gpt4

class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.strip().split() # Split the string into words
        return ' '.join(reversed(words)) # Reverse the order of the words and join them
