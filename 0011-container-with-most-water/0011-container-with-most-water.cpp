// SOL1 ) - GPT4
#include <vector>
#include <algorithm> // Include this header for using std::min and std::max functions

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max_water = 0; // Initialize the variable to store the maximum water that can be held
        int left = 0;      // Initialize the left pointer
        int right = height.size() - 1; // Initialize the right pointer
        
        // Continue the loop as long as the left pointer is less than the right pointer
        while (left < right) {
            // Calculate the current height of the container, which is the minimum of the two lines
            int current_height = std::min(height[left], height[right]);
            
            // Calculate the current width of the container
            int current_width = right - left;
            
            // Calculate the area (water) for the current container and update max_water if this area is greater
            max_water = std::max(max_water, current_height * current_width);
            
            // If the left line is shorter than the right line, move the left pointer to the right
            // Otherwise, move the right pointer to the left
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        // Return the maximum water that can be held
        return max_water;
    }
};



// SOL2) - Leetcode Discussion 

// https://leetcode.com/problems/container-with-most-water/discuss/1915172/JavaC%2B%2B-Easiest-Explanations
// 코드 원래에 대한 설명 매우 자세

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int left = 0;
//         int right = height.size() - 1;
//         int maxi = 0;
//         while(left < right){
//             int w = right - left;
//             int h = min(height[left], height[right]);
//             int area = h * w;
//             maxi = max(maxi, area);
//             if(height[left] < height[right]) left++;
//             else if(height[left] > height[right]) right--;
//             else {
//                 left++;
//                 right--;
//             }
//         }
//         return maxi;
//     }
// };