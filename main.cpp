#include<iostream>
//#include"My.h"
#include"dij1.h"
#include"delete1.h"
#include"add1.h"
//#include"read.h"

#include<cstring>
#include<fstream>
#include<cmath>
#define N 110
#define INF 1<<30

using namespace std;
extern int n,m;
extern int map[N][N];
//vis���飬�ж������·��ʱ�ýڵ��Ƿ��ҹ���
//isDelete:�жϸýڵ��Ƿ�ɾ����
extern bool vis[N],isDelete[N];
//qianQu��ǰ���ڵ㣬 dis:�����ԭ�㵽�����ڵ����̾���
extern int dis[N],qianQu[N];
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
void read(){
	//�����ļ�������
	ifstream Read;
	Read.open("tuoputu10.txt");
	Read>>n;
	for(int i=0;i<n;i++){
		int x;Read>>x;
		isDelete[x-1]=0;
	}
	Read>>m;
	for(int i=0;i<m;i++){
		int x,y,len;
		Read>>x>>y>>len;
		map[x][y]=map[y][x]=len;
	}
	Read.close();
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
int main(){
	memset(map,1,sizeof(map));
	memset(vis,0,sizeof(vis));
	memset(isDelete,1,sizeof(isDelete));
	read();
	while(1){
		int n;
		menu();
		scanf("%d",&n);
		switch(n){
			case 1:show();break;
			case 2:deleteP();break;
			case 3:deleteS();break;
			case 4:addP();break;
			case 5:addS();break;
		qhf 
			//case 6:system("cls");menu();break;
			//case 7:exit(0);break;
		}
	}
}
