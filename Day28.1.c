#include <stdio.h>
#include <stdlib.h>
int count=0;    // to count the number of nodes in list

struct node{
    int no;
    struct node* next;
} *new, *ptr, *temp, *first=NULL;

void get_element(){
    new = (struct node*)malloc(sizeof(struct node));   // DMA

    if(new == NULL){
        printf("DMA unsuccessful! Try again later.\n");
        exit(0);
    }

    printf("Enter data to insert: ");
    scanf("%d", &new->no);
    new->next = NULL;
}

void create_list(){   // Insert at End (Circular)
    int n;
    printf("Enter number of elements to be inserted: ");
    scanf("%d", &n);

    count = count + n;

    for(int i=1; i<=n; i++){
        get_element();   // create new node

        if(first == NULL){
            first = new;
            new->next = first;   // self-link (circular)
        }
        else{
            for(ptr = first; ptr->next != first; ptr = ptr->next);
            ptr->next = new;
            new->next = first;   // maintain circular link
        }

        printf("Element-%d inserted in List.\n", i);
    }
}