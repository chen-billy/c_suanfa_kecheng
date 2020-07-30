#include "stdio.h"
#include "malloc.h"
typedef int ElementType;
typedef struct Node *stack;
typedef struct QNode *Queue;
//链表结构
struct Node
{
    ElementType Data; //数据域
    stack Next;       //指针域
};
//队列结构
struct QNode
{
    stack rear;  // 指向队尾指针
    stack front; //指向队头指针
};
//初始化链队列
Queue CreateQueue()
{
    Queue Q;
    Q = (Queue)malloc(sizeof(struct QNode));
    Q->front = NULL;
    Q->rear = NULL;
    return Q;
}
//入队
void ADD(Queue Q, ElementType X)
{
    stack P; // 创建一个指针指向要插入的结点
    P = (stack)malloc(sizeof(struct Node));
    P->Data = X;
    P->Next = NULL;
    if (Q->rear == NULL) //链队列初始的时候就是空
    {
        Q->rear = P;
        Q->front = P;
    }
    else
    {
        Q->rear->Next = P;
        Q->rear = P;
    }
}
//判断是否为空
int IsEmpty(Queue Q)
{
    return (Q->front == NULL);
}

//出队
ElementType OUT(Queue Q)
{
    stack M;          //指向第一个元素的指针
    ElementType Ment; //取出的元素
    if (IsEmpty(Q))
    {
        printf("链队列为空!");
        return 0;
    }
    M = Q->front;
    //如果队列当中只有一个元素
    if (Q->front == Q->rear)
    {
        Q->front = Q->rear = NULL;
    }
    else
    {
        Q->front = Q->front->Next;
    }
    Ment = M->Data;
    free(M);
    return Ment;
}

//测试

int main()
{
    Queue Q;
    Q = CreateQueue();
    ADD(Q, 8);
    printf("%d 入队\n", Q->rear->Data);
    ADD(Q, 15);
    printf("%d 入队\n", Q->rear->Data);
    ADD(Q, 20);
    printf("%d 入队\n", Q->rear->Data);
    printf("%d 出队\n", OUT(Q));
    printf("%d 出队\n", OUT(Q));
    printf("%d 出队\n", OUT(Q));
    printf("%d 出队\n", OUT(Q));
    return 0;
}