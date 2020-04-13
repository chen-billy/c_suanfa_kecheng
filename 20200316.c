#include <stdio.h>
#include <malloc.h>
typedef int ElementType; //ElementType 可定义为任意类型
typedef struct LNode *List;
struct LNode
{
    ElementType Data; //数据域
    List Next;        //指针域下一个链表的地址
};
List L; //头节点指针
//初始化链表
List MakeEmpty()
{
    List L = (List)malloc(sizeof(struct LNode)); //分配一个动态空间，L指向空间的首地址
    L = NULL;                                    //头节点为空
    return L;
}
//求链表的长度
int Length(List L)
{
    List p = L;             //p指向头指针
    int len = 0;            //长度从0开始
    while (p->Next != NULL) //如果指向下一个指针不为空
    {
        p = p->Next;
        len++;
    }
    return len;
}
//按序查找
List FindKth(int K, List L)
{
    List p = L;
    int i = 1;
    while (p->Next != NULL && i < K)
    {
        p = p->Next;
        i++;
    }
    if (i == K) //找到了
    {
        return p;
    }
    else
    {
        return NULL;
    }
}
