class Solution:
    def simplifyPath(self, path: str) -> str:

        ## leetcode sol)
        
        # Initialize a stack
        stack = []

        # Split the input string on "/" as the delimiter and process each portion one by one
        for portion in path.split("/"):

            # If the current component is a "..", then we pop an entry from the stack if it's non-empty
            if portion == "..":
                if stack:
                    stack.pop()
            elif portion == "." or not portion: 
                ## need to think of this case as well
                # A no-op for a "." or an empty string
                continue
            else:
                # Finally, a legitimate directory name, so we add it to our stack
                stack.append(portion)

        # Stich together all the directory names together
        final_str = "/" + "/".join(stack) ## Need understanding for join function
        return final_str