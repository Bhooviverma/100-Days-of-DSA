int canShip(int* weights, int n, int days, int capacity) {
    int requiredDays = 1;
    int currentLoad = 0;

    for (int i = 0; i < n; i++) {
        if (currentLoad + weights[i] <= capacity) {
            currentLoad += weights[i];
        } else {
            requiredDays++;
            currentLoad = weights[i];

            if (requiredDays > days) return 0;
        }
    }
    return 1;
}

int shipWithinDays(int* weights, int weightsSize, int days) {
    int low = 0, high = 0;

    // find max and sum
    for (int i = 0; i < weightsSize; i++) {
        if (weights[i] > low) low = weights[i];
        high += weights[i];
    }

    int answer = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canShip(weights, weightsSize, days, mid)) {
            answer = mid;
            high = mid - 1;   // try smaller capacity
        } else {
            low = mid + 1;    // increase capacity
        }
    }

    return answer;
}