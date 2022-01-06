#include <stdlib.h>
#include <stdio.h>
#include "../include/queue.h"

// Create a queue
queue* create_queue(int size)
{
    queue* q = (queue*)malloc(sizeof(queue));
    q->items = (int*)malloc(sizeof(int)*size);
    q->front = -1;
    q->rear = -1;
    q->size = size;
    return q;
}

// Check if the queue is empty
int isEmpty(queue* q)
{
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

// Adding elements into queue
void enqueue(queue* q, int value)
{
    if (q->rear == q->size - 1)
        printf("\nQueue is Full!!");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Removing elements from queue
int dequeue(queue* q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Queue is empty");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// free allocated queue
void free_queue(queue* q)
{
    if (q != NULL)
    {
        if (q->items != NULL)
            free(q->items);

        free(q);
    }
}


