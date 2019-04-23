#include<stdio.h>
#include<stdlib.h>

// #define MaxSize 4;
#define ERROR -1;
typedef int ElementType;


struct QNode
{
    ElementType *Data;
    int rear;
    int front;
    int MaxSize;
};

typedef struct QNode *Queue;

Queue CreateQueue(int MaxSize);
void AddQ(Queue PtrQ,ElementType item);
ElementType DeleteQ(Queue PtrQ);
void disQueue(Queue PtrQ);


Queue CreateQueue(int MaxSize)
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType *)malloc(MaxSize*sizeof(ElementType));
    Q->front = Q->rear =0;
    Q->MaxSize = MaxSize;
    return Q;
}

// sequence store
void AddQ(Queue PtrQ,ElementType item)
{
    if((PtrQ->rear+1)%(PtrQ->MaxSize) == PtrQ->front)
    {
        printf("The queue is full");
        return;
    }
    PtrQ->rear = (PtrQ->rear+1)%(PtrQ->MaxSize);
    PtrQ->Data[PtrQ->rear] = item;
}


ElementType DeleteQ(Queue PtrQ)
{
    if(PtrQ->front==PtrQ->rear)
    {
        printf("The queue is empty");
        return ERROR;
    }
    else
    {
        PtrQ->front = (PtrQ->front+1)%(PtrQ->MaxSize);
        return PtrQ->Data[PtrQ->front];
    }   
}


void disQueue(Queue PtrQ)
{
    Queue test_queue = PtrQ;   
    while(PtrQ->front != PtrQ->MaxSize)
    {
        printf("queue_test %d\n",test_queue->Data[(PtrQ->front)]);
        PtrQ->front++;
    }
    return;
}

int main()
{
    Queue queue_test; 
    int MaxSize =4; 
    queue_test = CreateQueue(MaxSize);
    AddQ(queue_test,2);
    AddQ(queue_test,3);
    AddQ(queue_test,3);  
    disQueue(queue_test);
    return 0;
}
