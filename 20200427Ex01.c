#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef struct QNode *Queue; //创建指向队列的别名指针Queue
struct QNode
{
    int Data[MaxSize];
    int front; //队首
    int rear;  //队尾
};

//初始化
Queue CreateQueue()
{
    Queue Q; //指向队列的指针变量Q
    Q = (Queue)malloc(sizeof(struct QNode));
    Q->front = -1;
    Q->rear = -1;
    return Q;
}

//判断队列是否满了
int IsFull(Queue Q)
{
    return ((Q->rear + 1) % MaxSize == Q->front);
}

//入队
void ADD(Queue Q, int X)
{
    if (IsFull(Q))
    {
        printf("队列已经满！");
        return;
    }
    else
    {
        Q->rear = (Q->rear + 1) % MaxSize;
        Q->Data[Q->rear] = X;
    }
}

//判断是否为空
int IsEmpty(Queue Q)
{
    return (Q->front == Q->rear);
}

//出队
int OUT(Queue Q)
{
    if (IsEmpty(Q))
    {
        printf("队列以空！");
        return 0;
    }
    else
    {
        Q->front = (Q->front + 1) % MaxSize;
        return Q->Data[Q->front];
    }
}

//测试
int main()
{
    Queue Q;
    Q = CreateQueue();
    ADD(Q, 3);
    printf("%d入队\n", Q->Data[Q->rear]);
    ADD(Q, 8);
    printf("%d入队\n", Q->Data[Q->rear]);
    ADD(Q, 20);
    printf("%d入队\n", Q->Data[Q->rear]);
    printf("%d出队\n", OUT(Q));
    printf("%d出队\n", OUT(Q));
    printf("%d出队\n", OUT(Q));
    printf("%d出队\n", OUT(Q));
    return 0;
}