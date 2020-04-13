//创建一个顺序表-利用数组的形式-对顺序表进行初始化，建立一个空表
#include <stdio.h>
#include <malloc.h>      //从内存中分配空间给数组
#define MAXSIZE 100      //MAXSIZE定义为数组的大小，给数组起一个名字比如：Data
typedef int ElementType; //ElementType可以是任意类型
typedef struct LNode *List;
struct LNode
{

    ElementType Data[MAXSIZE];
    int Last; //定义线性表的最后一个元素
};
List L; //创建一个别名叫L
//如果访问下标为i的元素：L->Data[i]
//线性表的长度：L->Last+1

//初始化一个空顺序表
List MakeEmpty()
{
    List L;
    L = (List)malloc(sizeof(struct LNode)); //从内存取一块空间出来给顺序表使用
    L->Last = -1;                           //空表
    return L;
}
//插入元素
void insert(ElementType X, int i, List L)
{
    int j;
    if (L->Last == MAXSIZE - 1)
    {
        printf("表满"); //表已经满了。不能在插入元素了。
        return;
    }

    for (j = L->Last; j >= i; j--) //从第i个元素之后依次往后移动一位，给data[i]腾出位置
    {
        L->Data[j + 1] = L->Data[j];
    }
    L->Data[i] = X; //新插入一个X元素
    L->Last++;      //数组长度加1
    return;
}
//主函数中插入几个元素，并显示出来
int main()
{
    int i = 0;
    L = MakeEmpty();
    insert(11, 0, L);
    printf("在线性表中插入11\n");
    insert(25, 0, L);
    printf("在线性表中插入25\n");
    insert(30, 0, L);
    printf("在线性表中插入30\n");
    insert(77, 0, L);
    printf("在线性表中插入77\n");
    printf("此时的线性表是：");
    for (i = 0; i < 4; i++)
    {
        printf("%d,", L->Data[i]);
    }
}