#ifndef My_H
#define My_H
#include<iostream>
#include<cstring>
#include<fstream>
#include<cmath>
#define N 110
#define INF 1<<30 
using namespace std;
int n,m;
int map[N][N];
//vis���飬�ж������·��ʱ�ýڵ��Ƿ��ҹ��� 
//isDelete:�жϸýڵ��Ƿ�ɾ���� 
bool vis[N],isDelete[N];
//qianQu��ǰ���ڵ㣬 dis:�����ԭ�㵽�����ڵ����̾��� 
int dis[N],qianQu[N];
//Ѱ��dis������е���Сֵ,�����±� 

extern void menu();
extern int findMid();
extern void Dijkstra(int x);
extern int find(int x,int i);
extern int show();
extern void deleteP();
extern void deleteS();
extern void addP();
extern bool addS();
extern void read();
#endif
int findMin(){ 
	int min=INF,minXb=INF;
	for(int i=0;i<n;i++){
		if(dis[i]<min&&!vis[i]){
			min=dis[i];
			minXb=i;
		}
	}
	if(minXb==INF)
	return -1;
	vis[minXb]=true;
	return minXb;
}
void menu(){
	//system("cls");
	printf("**********����·������******************\n");
	printf("**********��ѡ����Ӧѡ��ʵ�ֹ���********\n");
	printf("**********1.·�ɱ������ӡ**************\n");
	printf("**********2.ɾ���ڵ�********************\n");
	printf("**********3.ɾ����**********************\n");
	printf("**********4.���ӽڵ�********************\n");
	printf("**********5.���ӱ�**********************\n");
	printf("**********6.��������ѡ��˵�************\n");
	printf("**********7.�˳�ϵͳ********************\n");
	printf("**********���������ѡ��**************\n");
}

