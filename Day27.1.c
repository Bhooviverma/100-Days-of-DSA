#include <stdio.h>
#include <stdlib.h>

struct node {
    int no;
    struct node *next;
} *new, *first1 = NULL, *first2 = NULL, *ptr, *temp;

void create_list(int n, int list_no) {
    for(int i = 0; i < n; i++) {
        new = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &new->no);
        new->next = NULL;

        if(list_no == 1) {
            if(first1 == NULL) {
                first1 = new;
                temp = first1;
            } else {
                temp->next = new;
                temp = new;
            }
        } else {
            if(first2 == NULL) {
                first2 = new;
                temp = first2;
            } else {
                temp->next = new;
                temp = new;
            }
        }
    }
}

int length(struct node *first) {
    int count = 0;
    ptr = first;
    while(ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

int main() {
    int n, m;

    scanf("%d", &n);
    create_list(n, 1);

    scanf("%d", &m);
    create_list(m, 2);

    int len1 = length(first1);
    int len2 = length(first2);

    struct node *ptr1 = first1;
    struct node *ptr2 = first2;

    int diff = abs(len1 - len2);

    if(len1 > len2) {
        for(int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for(int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    while(ptr1 != NULL && ptr2 != NULL) {
        if(ptr1->no == ptr2->no) {
            printf("%d", ptr1->no);
            return 0;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No Intersection");
    return 0;
}