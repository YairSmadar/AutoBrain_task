#ifndef AUTOBRAIN_QUEUE_H
#define AUTOBRAIN_QUEUE_H

typedef struct
{
    int *items;
    int front;
    int rear;
    int size;
} queue;

queue* create_queue(int size);
void enqueue(queue* q, int);
int dequeue(queue* q);
int isEmpty(queue* q);
void free_queue(queue* q);

#endif //AUTOBRAIN_QUEUE_H



