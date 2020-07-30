#include<stdio.h>
#include<malloc.h>
#include<windows.h>
#include <stdlib.h> 
typedef struct Node*stack;
typedef struct QNode*Queue;
Queue Create();
void Load();
struct Node{
	int data;
	stack Next;
};

struct QNode{
	stack rear;  //尾指针
	stack front; //头指针
};
//初始化
Queue Create(){
	Queue Z;
	Z=(Queue)malloc(sizeof(struct QNode));
	Z->front=NULL;
	Z->rear=NULL;
	return Z;
}
//初始化2
stack Create2(){
	stack S;
	S=(stack)malloc(sizeof(struct Node));
	S->Next=NULL;
	return S;
}
//入队
void ADD(int X,Queue Z){
	stack S;
	S=Create2();
	if(Z->front==NULL&&Z->rear==NULL){
		S->data=X;
		Z->front=S;
		Z->rear=S;
		printf("存入%d\n",Z->front->data);
	}else{
		S->data=X;
		Z->rear->Next=S;
		Z->rear=S;
		printf("存入%d\n",Z->rear->data);
	}
}

//出队
void out(Queue Z){
	stack C;
	C=Z->front;
	while(C!=NULL){
		printf(" %d ",C->data);
		C=C->Next;
	}
}


//删除
void Delete(stack S,stack V,Queue Z){
	//如果是头指针
	if(S==Z->front){
		
		Z->front=S->Next;
		free(S);

	}
	//如果是尾巴指针
	else if(S==Z->rear){ //如果去掉else 会中断，为什么？猜：S不为NULL 但S指向的地址已经不存在了
		Z->rear=V;
		Z->rear->Next=NULL;
		free(S);
	}
	else{
		V->Next=S->Next;
		free(S);
	}
}

//游戏
void Game(Queue Z,int childNum,int shanyuNum){
	int i,j;
	stack S;
	stack V;//V负责存储S的前一个指针
    printf("\n----游戏开始-----\n");


	for(i=1;i<childNum;i++){
		printf("\n\n山芋从位置一开始传递：");
		S=Z->front;

		for(j=1;j<=shanyuNum;j++){
		//	Sleep(500);  //休眠时间   单位毫秒
		printf("  到%d ",S->data);
			if(j==shanyuNum){
				printf("\n-----在第%d次拿到山芋的小朋友是%d，%d小朋友淘汰",shanyuNum,S->data,S->data);
				Delete(S,V,Z);
				break;
			}
			V=S;  //  V存入
			S=S->Next;
			if(S==NULL){
				S=Z->front;
			}
		}
			printf("\n-------目前小朋友的排列顺序为：");
			out(Z);
	}
	printf("\n\n-----获胜的是%d小朋友",Z->front->data);
}

//手动输入
void Labour(){
	Queue Z=Create();
	int child,i,childNum,shanyuNum;
	system("color 3E");
	//Load();
	printf("请输入参与游戏的人数：");
	scanf("%d",&childNum);
	printf("请输入山芋传递的次数：");
	scanf("%d",&shanyuNum);
	for(i=1;i<=childNum;i++){
		printf("请输入排要在第%d位的孩子的编号:  ",i);
		scanf("%d",&child);
		ADD(child,Z);
	}

	printf("\n-----输入完毕-----\n孩子目前的排列顺序为: ");
	out(Z);
	Game(Z,childNum,shanyuNum);
}
//自动输入
void Auto(){
	Queue Z=Create();
	int child,i,childNum,shanyuNum,num=0,j;
	int child2[100];
	system("color 3E");
	while(1){
		childNum=rand();
		if(childNum>0&&childNum<10)
			break;
	}
	while(1){
		shanyuNum=rand();
		if(shanyuNum>0&&shanyuNum<11)
			break;
	}
	printf("\n---------------------\n");
	printf("参与游戏的人数为%d\n",childNum);
	printf("山芋传递的次数为%d",shanyuNum);
	printf("\n---------------------\n");
	for(i=1;i<=childNum;i++){
	loop: 	while(1){
			child=rand();
			if(child>0&&child<15){
				for(j=0;j<=num;j++){
					if(child==child2[j])
						goto loop;
				}
				break;
			}
		}
        child2[num]=child;
		num++;
		Sleep(300);
		printf("排在第%d位的孩子的编号为: %d ",i,child);
		ADD(child,Z);
	}

	printf("\n-----输入完毕-----\n孩子目前的排列顺序为: ");
	out(Z);
	Sleep(2000);
	printf("\n------go");
	Sleep(2000);
	Game(Z,childNum,shanyuNum);

}

void main(){
	int i;
		system("color 3E");
	Load();

	while(1){
		printf("\n\n---------------------\n请选择游戏的方式\n1.手动输入\n2.自动输入\n");
		scanf("%d",&i);
		switch(i){
		case 1:
			Labour();
			break;
		case 2:
			Auto();
			break;
		default :
			printf("\n输入错误，请重新输入\n");
			break;
		}
		printf("\n\n-----是否继续游戏-----\n------1.继续游戏\n-------2.退出游戏\n");
		scanf("%d",&i);
		if(i==2){
			printf("\n-------按任意键退出------");
			break;
		}
	}


}
//加载画面
void Load(){
	int i;
	for(i=0;i<20;i++){
		Sleep(100);
		printf("-");
	}
	printf("烫");
	Sleep(30);
	printf("手");
	Sleep(30);
	printf("山");
	Sleep(30);
	printf("芋");
	Sleep(30);
	printf("小");
	Sleep(30);
	printf("游");
	Sleep(30);
	printf("戏");
	for(i=0;i<20;i++){
		Sleep(80);
		printf("-");
	}
	printf("\n");
	for(i=0;i<15;i++){
		Sleep(80);
		printf("-");
	}
	printf("加载中");
	for(i=0;i<5;i++){
		Sleep(50);
		printf("★");
	}
	for(i=0;i<15;i++){
		Sleep(50);
		printf("-");
	}
	printf("\n");
	printf("加载成功 gogogo!\n");
	printf("\n---------------------------Game start---------------------------\n");
}