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
//vis数组，判断找最短路径时该节点是否找过了
//isDelete:判断该节点是否被删除了
extern bool vis[N],isDelete[N];
//qianQu：前驱节点， dis:保存从原点到其他节点的最短距离
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
	//定义文件输入流
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
