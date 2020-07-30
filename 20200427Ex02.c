#include <stdio.h>
#include <malloc.h>
typedef struct Node *stack;
typedef struct QNode *Queue;
//链表结构
struct Node
{
    int Data;   //数据域
    stack Next; //指针域
};

//队列结构
struct QNode
{
    stack rear;  //指向队尾指针
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
void ADD(Queue Q, int X)
{
    stack P; // 创建一个指针指向要插入的结点
    P = (stack)malloc(sizeof(struct Node));
    P->Data = X;
    P->Next = NULL;
    if (Q->rear == NULL)
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

//测试
int main()
{
    Queue Q;
    Q = CreateQueue();
    ADD(Q, 8);
    printf("%d入队\n", Q->rear->Data);
    ADD(Q, 15);
    printf("%d入队\n", Q->rear->Data);
    ADD(Q, 20);
    printf("%d入队\n", Q->rear->Data);
    return 0;
}