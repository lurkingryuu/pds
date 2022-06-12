#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    N * next;
}N;

void push(N** head_ref, int value){
    N* curr = (N*)malloc(sizeof(N));

    N* last = *head_ref;

    curr->value = value;
    curr->next = NULL;

    if (*head_ref == NULL){
        *head_ref = curr;
        return;
    }

    while (last->next != NULL)
        last = last->next;
    
    last->next = curr;
}

void print(N* head){
    N* temp = head;
    while (temp->next != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}


void concatenate(N* first, N* second){
    
    
}


int main(){
    N* list = NULL;

    push(&list, 0);
    push(&list, 1);    
    push(&list, 2);    
    push(&list, 3);

    return 0;
}