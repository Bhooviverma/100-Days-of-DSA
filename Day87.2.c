int minEatingSpeed(int* piles, int pilesSize, int h) {
    int left = 1, right = 0;

    // Find maximum pile (upper bound)
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > right)
            right = piles[i];
    }

    while (left < right) {
        int mid = left + (right - left) / 2;

        long hours = 0;

        // Calculate total hours needed at speed = mid
        for (int i = 0; i < pilesSize; i++) {
            hours += (piles[i] + mid - 1) / mid; // ceil division
        }

        if (hours <= h)
            right = mid;       // try smaller speed
        else
            left = mid + 1;   // increase speed
    }

    return left;
}