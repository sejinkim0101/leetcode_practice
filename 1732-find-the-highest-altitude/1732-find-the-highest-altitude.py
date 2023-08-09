# Sol1 - GPT4

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        altitude = 0  # Current altitude, starts at 0
        max_altitude = 0  # Maximum altitude, initialized with 0

        # Iterate through the gain array
        for g in gain:
            altitude += g  # Add the gain to the current altitude
            max_altitude = max(max_altitude, altitude)  # Update the maximum altitude

        return max_altitude
