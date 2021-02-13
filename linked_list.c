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
node_t *creat_new_node(int value)
{
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}
int main()
{
    node_t *head, *tmp;
    tmp = creat_new_node(23);
    head = tmp;
    tmp = creat_new_node(12);
    tmp->next = head;
    head = tmp;
    tmp = creat_new_node(45);
    tmp->next = head;
    head = tmp;

    printlist(head);
    return 0;
}