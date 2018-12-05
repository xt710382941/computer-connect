#include"SeqList.h"
#include <stdlib.h>
#include <malloc.h>
#include<windows.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
typedef int DataType;
#define MaxSize 100 
#define MaxVertices 100
#define MaxWeight 10000
//#include "InsterEdge.h"
#include "GraphInitiate.h"
#include "Insert.h"

#include "Delete.h"
//#include "DeleteVertex.h"
#include "CreatGraph.h"
#include "Dijkstra.h"

	AdjMGraph g1;
		int a[MaxSize]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    RowColWeight rcw[100];
//主函数

void menu()
{
	int p;
	void putList();
	void Deletevertex();
	void Deleteedge();
	void Insertedge();
	void Insertvertex(); 
   //printf("**********************网络路由生成************************\n");
   //printf("**********************请选择相应实现功能******************\n");
   printf("1.路由表输出并打印\n");
   printf("2.删除节点\n");
   printf("3.删除边\n");
   printf("4.增加边\n");
   printf("5.增加节点\n");
   printf("6.退出系统\n");
   //printf("**********************请输入你的选择（1~6）***************\n");
   scanf("%d",&p);
    if(p<1||p>6)
	{printf("\n\n输入序号不属于菜单，请重新输入\n\n");
	p=7;}
	switch(p)
	{
	 case 1:putList();break;      //路由表输出并打印
     case 2:Deletevertex();break;   //删除节点
     case 3:Deleteedge();break;   //删除边
	 case 4:Insertedge();break;   //增加边 
	 case 5:Insertvertex();break;  //增加节点 
	 case 6: exit(0);break; //退出
	 case 7:menu();
	}
}

void putList()
{
	 int i,j;
	 int distance[20],path[20];
     printf("起始路由器\n");
	 scanf("%d",&i);
	 i--;
	 Dijkstra(&g1,i,distance,path);
	 //printf("从顶点%d到其他各顶点的最短距离为：\n",a[i]);
	 for(j=0;j<g1.vertices.size;j++)
		 printf("到顶点%d的最短距离为%d\n",a[j],distance[j]);
		 menu();

}


void Deletevertex()
{
	int i;
    printf("请输入你要删除的是第几个顶点v\n");
	scanf("%d",&i);
	DeleteVertex(&g1,i);
	menu();
}

void Deleteedge()
{
    int i,j;
    printf("请输入你要删除的边的两个顶点v1,v2\n");
	scanf("%d%d",&i,&j);
	DeleteEdge(&g1,i-1,j-1);
	menu();
}


void Insertedge()
{
    int i,j,w;
    printf("请输入你要增加的边的两个顶点和其权值v1,v2,w\n");
	scanf("%d%d%d",&i,&j,&w);
	InsertEdge(&g1,i-1,j-1,w);
	menu();
}
void Insertvertex()
{
	int i,j,w;
	printf("请输入你要增加的顶点v\n");
	scanf("%d",&i);
	InsertVertex(&g1,i-1);
	//printf("请输入你要增加的与这个节点连接的节点和权值\n");
	//scanf("%d%d",&j,&w);
	//InsertEdge(&g1,i-1,j-1,w);
	Insertedge();
	menu();	
 } 

int main()
{
	int i,j,k;
	FILE *fp;           //读入文件
    
	fp=fopen("tuoputu10.txt","r");

	fscanf(fp,"%d",&i);
	for(k=0;k<i;k++)
	{
	fscanf(fp,"%d",&a[k]);
	}
	fscanf(fp,"%d",&j);
	for(k=0;k<j;k++)
	{
        fscanf(fp,"%d%d%d",&rcw[k].row,&rcw[k].col,&rcw[k].weight);
	}
    fclose(fp);
	GraphInitiate(&g1);
    CreatGraph(&g1,a,i,rcw,j);
	menu();

}

