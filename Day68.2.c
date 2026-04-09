#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26

char* alienOrder(char** words, int wordsSize) {
    
    int indegree[MAX] = {0};
    int adj[MAX][MAX] = {0};
    int present[MAX] = {0};

    // Mark characters present
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; words[i][j]; j++) {
            present[words[i][j] - 'a'] = 1;
        }
    }

    // Build graph
    for (int i = 0; i < wordsSize - 1; i++) {
        char *w1 = words[i];
        char *w2 = words[i + 1];

        int len1 = strlen(w1);
        int len2 = strlen(w2);
        int found = 0;

        // Invalid case
        if (len1 > len2 && strncmp(w1, w2, len2) == 0) {
            return "";
        }

        for (int j = 0; j < len1 && j < len2; j++) {
            if (w1[j] != w2[j]) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';

                if (!adj[u][v]) {
                    adj[u][v] = 1;
                    indegree[v]++;
                }
                found = 1;
                break;
            }
        }
    }

    // Queue
    int queue[MAX];
    int front = 0, rear = 0;

    // Push indegree 0
    for (int i = 0; i < MAX; i++) {
        if (present[i] && indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    char* result = (char*)malloc(27);
    int idx = 0;

    // BFS
    while (front < rear) {
        int node = queue[front++];
        result[idx++] = node + 'a';

        for (int i = 0; i < MAX; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    result[idx] = '\0';

    // Count unique chars
    int total = 0;
    for (int i = 0; i < MAX; i++) {
        if (present[i]) total++;
    }

    if (idx != total) return "";

    return result;
}