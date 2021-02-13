#include <stdlib.h>
#include <stdio.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node node_t;

void printlist(node_t *head)
{
    node_t *tmp = head;
    while (tmp != NULL)
    {
        printf("%d - ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

int main()
{
    node_t n1, n2, n3;
    node_t *head;
    n1.value = 32;
    n2.value = 10;
    n3.value = 68;
    head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next=NULL;
    
    printlist(head);
    return 0;
}