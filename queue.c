#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_EMPTY INT_MIN

typedef struct node
{
    int value;
    struct node *next;
} node;

typedef struct
{
    node *head;
    node *tail;
} queue;

void init_queue(queue *q)
{
    q->head = NULL;
    q->tail = NULL;
}

bool enqueue(queue *q, int value)
{
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL)
        return false;
    newnode->value = value;
    newnode->next = NULL;
    if (q->tail != NULL)
    {
        q->tail->next = newnode;
    }
    
    q->tail = newnode;
    
    if (q->head == NULL)
    {
        q->head = newnode;
    }   
    return true;
}
int dequeue(queue *q)
{
    if (q->head == NULL)
        return QUEUE_EMPTY;
    node *tmp = q->head;
    int result = tmp->value;
    q->head = q->head->next;
    if (q->head == NULL)
    {
        q->tail = NULL;
    }
    
    free(tmp);
    return result;
}
int main()
{
    queue q1, q2, q3;

    init_queue(&q1);
    init_queue(&q2);
    init_queue(&q3);

    enqueue(&q2, 56);
    enqueue(&q2, 78);
    enqueue(&q2, 23);
    enqueue(&q2, 988);
    enqueue(&q2, 13);

    int t;
    while ((t = dequeue(&q2)) != QUEUE_EMPTY)
    {
        printf("t=%d\n", t);
    }
}