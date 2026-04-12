#include <stdio.h>

#define EMPTY -1

int main() {
    int m, q;
    
    // Input size of hash table
    scanf("%d", &m);
    
    int table[m];
    
    // Initialize table
    for(int i = 0; i < m; i++)
        table[i] = EMPTY;
    
    // Number of operations
    scanf("%d", &q);
    
    while(q--) {
        char op[10];
        int key;
        
        scanf("%s %d", op, &key);
        
        // INSERT operation
        if(op[0] == 'I') {
            int h = key % m;
            int i = 0;
            
            while(i < m) {
                int idx = (h + i * i) % m;
                
                if(table[idx] == EMPTY) {
                    table[idx] = key;
                    break;
                }
                i++;
            }
        }
        
        // SEARCH operation
        else if(op[0] == 'S') {
            int h = key % m;
            int i = 0;
            int found = 0;
            
            while(i < m) {
                int idx = (h + i * i) % m;
                
                if(table[idx] == key) {
                    found = 1;
                    break;
                }
                
                if(table[idx] == EMPTY)
                    break;
                
                i++;
            }
            
            if(found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }
    
    return 0;
}