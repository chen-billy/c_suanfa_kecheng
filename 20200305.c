//用数组来实现一个顺序表，并进行数据插入，数组叫Data，大小100
#include <stdio.h>
#include <malloc.h>         //让计算机内容分配一块物理空间给这个顺序表
#define MAXSIZ 100          //MAXSIZE定义Data这个数组的大小
typedef int ElementType;    //把int 定义一个别名
typedef struct LNode *List; //动态空间
struct LNode
{
    ElementType Data[MAXSIZ];
    int Last; //最后一个元素的位置
};
List L;
/*如果访问下标为i的元素：L->Data[i]   
线性表的长度：L->Last+1*/
//初始化顺序表，初始化后表中的元素个数是0
List MakeEempty()
{
    List L;
    L = (List)malloc(sizeof(struct LNode)); //分配一个地址空间给L
    L->Last = -1;
    return L;
}
//插入元素
void insert(ElementType X, int i, List L)
{
    int j; //做循环使用
    //判断表是否已经满了
    if (L->Last == MAXSIZ - 1)
    {
        printf("表满！");
        return;
    }
    if (i < 0 || L->Last + 1 < i)
    {
        printf("位置不合法");
    }
    //从后往前依次后移一位，给Data[i]腾出位置
    for (j = L->Last; j >= i; j--)
    {
        L->Data[j + 1] = L->Data[j]; //把第j位后移一位变成j+1
    }
    L->Data[i] = X; //在第i个位置插入元素x
    L->Last++;      //数组长度自增1
    return;
}
//按值查找数据元素
int Find(ElementType x, List L)
{
    int i = 0; //做循环使用
    while (i <= L->Last && L->Data[i] != x)
    {
        i++;
    }
    if (L->Last < i)
    {
        return -1; // 如果没有找到，返回-1
    }
    else
    {
        return L->Data[i]; //如果有找到，返回找到的值
    }
}
//测试一下，看一下，线性表能否插入数据，显示数据
int main()
{
    int i = 0;        //做循环使用
    L = MakeEempty(); //调用初始化函数，进行初始化L
    insert(11, 0, L);
    printf("在线性表中L-Data[0]插入11\n");
    insert(25, 0, L);
    printf("在线性表中L-Data[0]插入20\n");
    insert(33, 0, L);
    printf("在线性表中L-Data[0]插入30\n");
    insert(77, 0, L);
    printf("在线性表中L-Data[0]插入81\n");
    printf("此时的线性表为：");
    for (i = 0; i < 4; i++)
    {
        printf("%d ", L->Data[i]);
    }
    printf("\n");
    printf("查找值为12的下标：%d\n", Find(13, L));
    printf("查找值为33的下标：%d\n", Find(33, L));
    printf("查找值为77的下标：%d\n", Find(77, L));
    return 0;
}