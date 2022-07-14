#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

//오류함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}


//초기화함수
void init_queue(QueueType *q)
{
    q -> rear = -1;
    q -> front = -1;
}

//큐를 보여주는 함수
void queue_print(QueueType *q)
{
    for(int i = 0; i < MAX_QUEUE_SIZE; i++)
    {
        if(i <= q -> front || i > q -> rear)
            printf(" | ");
        else
            printf("%d | ", q -> data[i]);
    }
    printf("\n");
}

//포화상태
int is_full(QueueType *q)
{
    if(q -> front == MAX_QUEUE_SIZE - 1)
        return 1;
    else
        return 0;
}

//빈상태
int is_empty(QueueType *q)
{
    if(q -> front == q -> rear)
        return 1;
    else
        return 0;
}

//entry
void enqueue(QueueType *q, int item)
{
    if(is_full(q))
    {
        error("full");
        return;
    }
    q -> data[++(q -> rear)] = item;
}

//delete
int dequeue(QueueType *q)
{
    if(is_empty(q))
    {
        error("empty");
        return -1;
    }
    int item = q -> data[++(q -> front)];
    return item;
}

int main()
{
    int item;
    QueueType q;

    init_queue(&q);

    enqueue(&q, 10); queue_print(&q);
    enqueue(&q, 20); queue_print(&q);
    enqueue(&q, 30); queue_print(&q);

    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q);
    return 0;
}