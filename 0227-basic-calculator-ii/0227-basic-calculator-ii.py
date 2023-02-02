class Solution:
    def calculate(self, s: str) -> int:
        
        # sol from leetcode discussion
        
        s = s.replace(" ", "")
        s += '+'
        st = []
        num = 0
        op = '+'

        for i in s:
            if i.isdigit():
                num = (num*10)+int(i)
                
            else:
                num = int(num)
                if op == '+':
                    st.append(num)
                elif op == '-':
                    st.append(-num)
                elif op == '*':
                    st.append(st.pop()*num)
                elif op == '/':
                    st.append(int(st.pop()/num))

                num = 0
                op = i
        return sum(st)
        
        
#         stack_op = []
#         num = 0 
#         result = 0
#         prev_type_is_num = True 
        
#         tmp_s = s.replace(" ", "")
        
#         if tmp_s == "" return 0
        
#         nums_list = []
        
#         import re
#         splited_tmp_s = re.split('+|-|*|/', tmp_s)
        
#         for
        
        ###  --- another failed version
#         # split the +, - first
#         for ch in tmp_s:
#             if ch.isdigit():
#                 if prev_type_is_num:
#                     num = 10 * num + ch
                    
#                 else:
#                     prev_type_is_num = False
#                     if ch is "+" or "-":
#                         result += ch  
#                         num = 0
                    
            
            
#             else: # when prev type is operation