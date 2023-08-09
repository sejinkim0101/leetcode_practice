// sol1 - GPT4 

int largestAltitude(int* gain, int gainSize) {
    int altitude = 0;  // Current altitude, starts at 0
    int max_altitude = 0;  // Maximum altitude, initialized with 0

    // Iterate through the gain array
    for (int i = 0; i < gainSize; i++) {
        altitude += gain[i];  // Add the gain to the current altitude
        if (altitude > max_altitude) {
            max_altitude = altitude;  // Update the maximum altitude if the new altitude is greater
        }
    }

    return max_altitude;
}
