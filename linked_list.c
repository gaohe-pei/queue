#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int value;
    struct node *next;
}node_t;

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
node_t *insert_at_head(node_t **head, node_t *node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
    //printf("%p-%p  ", *head, head);
    return node_to_insert;
}

void insert_after_node(node_t *node_to_insert_after, node_t *newnode)
{
    newnode->next = node_to_insert_after->next;
    node_to_insert_after->next = newnode;
}

node_t *find_node(node_t *head, int value)
{
    node_t *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value == value)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

int main()
{
    node_t *head = NULL, *tmp;

    for (int i = 0; i < 25; i++)
    {
        tmp = creat_new_node(i);
        insert_at_head(&head, tmp);
        //printf("%p-%p\n", &head, head);
    }
    tmp=find_node(head,15);
    insert_after_node(tmp,creat_new_node(86));
    printlist(head);
    return 0;
}