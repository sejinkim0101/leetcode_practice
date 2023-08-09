// Sol1 - gpt4

#include <vector>
#include <algorithm>

class Solution {
public:
    int largestAltitude(std::vector<int>& gain) {
        int altitude = 0;  // Current altitude, starts at 0
        int max_altitude = 0;  // Maximum altitude, initialized with 0

        // Iterate through the gain array
        for (int g : gain) {
            altitude += g;  // Add the gain to the current altitude
            max_altitude = std::max(max_altitude, altitude);  // Update the maximum altitude
        }

        return max_altitude;
    }
};
