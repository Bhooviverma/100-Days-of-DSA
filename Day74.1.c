#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000
#define LEN 50

// Comparator for qsort (lexicographical order)
int cmp(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    char votes[MAX][LEN];

    // Input votes
    for(int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    // Sort votes
    qsort(votes, n, sizeof(votes[0]), cmp);

    char winner[LEN];
    int maxVotes = 1, count = 1;

    strcpy(winner, votes[0]);

    // Count frequencies
    for(int i = 1; i < n; i++) {
        if(strcmp(votes[i], votes[i - 1]) == 0) {
            count++;
        } else {
            if(count > maxVotes) {
                maxVotes = count;
                strcpy(winner, votes[i - 1]);
            }
            count = 1;
        }
    }

    // Check last candidate
    if(count > maxVotes) {
        maxVotes = count;
        strcpy(winner, votes[n - 1]);
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}