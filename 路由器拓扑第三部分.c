
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
#include "AdjMGraph.h"
	AdjMGraph g1;
		int a[MaxSize];
    RowColWeight rcw[100];
//������

void menu()
{
	int p;
	void putList();
	void Deletevertex();
	void Deleteedge();
	void Insertedge();
	void Insertvertex(); 
   //printf("**********************����·������************************\n");
   //printf("**********************��ѡ����Ӧʵ�ֹ���******************\n");
   printf("1.·�ɱ��������ӡ\n");
   printf("2.ɾ���ڵ�\n");
   printf("3.ɾ����\n");
   printf("4.���ӱ�\n");
   printf("5.���ӽڵ�\n");
   printf("6.�˳�ϵͳ\n");
   //printf("**********************���������ѡ��1~6��***************\n");
   scanf("%d",&p);
    if(p<1||p>6)
	{printf("\n\n������Ų����ڲ˵�������������\n\n");
	p=7;}
	switch(p)
	{
	 case 1:putList();break;      //·�ɱ��������ӡ
     case 2:Deletevertex();break;   //ɾ���ڵ�
     case 3:Deleteedge();break;   //ɾ����
	 case 4:Insertedge();break;   //���ӱ� 
	 case 5:Insertvertex();break;  //���ӽڵ� 
	 case 6: exit(0);break; //�˳�
	 case 7:menu();
	}
}

void putList()
{
	 int i,j;
	 int distance[20],path[20];
     printf("��ʼ·����\n");
	 scanf("%d",&i);
	 i--;
	 Dijkstra(&g1,i,distance,path);
	 //printf("�Ӷ���%d���������������̾���Ϊ��\n",a[i]);
	 for(j=0;j<g1.vertices.size;j++)
		 printf("������%d����̾���Ϊ%d\n",a[j],distance[j]);
		 menu();

}


void Deletevertex()
{
	int i;
    printf("��������Ҫɾ�����ǵڼ�������v\n");
	scanf("%d",&i);
	DeleteVertex(&g1,i);
	menu();
}

void Deleteedge()
{
    int i,j;
    printf("��������Ҫɾ���ıߵ���������v1,v2\n");
	scanf("%d%d",&i,&j);
	DeleteEdge(&g1,i-1,j-1);
	menu();
}


void Insertedge()
{
    int i,j,w;
    printf("��������Ҫ���ӵıߵ������������Ȩֵv1,v2,w\n");
	scanf("%d%d%d",&i,&j,&w);
	InsertEdge(&g1,i-1,j-1,w);
	menu();
}
void Insertvertex()
{
	int i,j,w;
	printf("��������Ҫ���ӵĶ���v\n");
	scanf("%d",&i);
	InsertVertex(&g1,i-1);
	//printf("��������Ҫ���ӵ�������ڵ����ӵĽڵ��Ȩֵ\n");
	//scanf("%d%d",&j,&w);
	//InsertEdge(&g1,i-1,j-1,w);
	Insertedge();
	menu();	
 } 

int main()
{
	int i,j,k;
	FILE *fp;           //�����ļ�
    
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

