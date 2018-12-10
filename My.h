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
//vis数组，判断找最短路径时该节点是否找过了 
//isDelete:判断该节点是否被删除了 
bool vis[N],isDelete[N];
//qianQu：前驱节点， dis:保存从原点到其他节点的最短距离 
int dis[N],qianQu[N];
//寻找dis数组的中的最小值,返回下标 

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
	printf("**********网络路由生成******************\n");
	printf("**********请选择相应选项实现功能********\n");
	printf("**********1.路由表输出打印**************\n");
	printf("**********2.删除节点********************\n");
	printf("**********3.删除边**********************\n");
	printf("**********4.增加节点********************\n");
	printf("**********5.增加边**********************\n");
	printf("**********6.重新生成选择菜单************\n");
	printf("**********7.退出系统********************\n");
	printf("**********请输入你的选择！**************\n");
}

