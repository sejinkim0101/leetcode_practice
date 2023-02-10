class Solution:
    def firstUniqChar(self, s: str) -> int:
        my_dict = dict()
        for ch in s:
            if ch in my_dict:
                my_dict[ch] = my_dict[ch] + 1
            else:
                my_dict[ch] = 1
                
        for i in range(len(s)):
            if my_dict[s[i]] == 1:
                return i
        
        return -1
                
        