#include"delete1.h"
#include<fstream>
#define N 110
#define INF 1<<30
//#include"My.h"
extern int n,m;
extern int map[N][N];
//vis���飬�ж������·��ʱ�ýڵ��Ƿ��ҹ���
//isDelete:�жϸýڵ��Ƿ�ɾ����
extern bool vis[N],isDelete[N];
//qianQu��ǰ���ڵ㣬 dis:�����ԭ�㵽�����ڵ����̾���
extern int dis[N],qianQu[N];
void deleteP(){
	int point;
	printf("������Ҫɾ��������ڵ���:");
	scanf("%d",&point);
	isDelete[point-1]=true;
	for(int i=0;i<N;i++){
		map[point-1][i]=map[i][point-1]=INF;
	}

}
//ɾ��һ����
void deleteS(){
	int pointx,pointy;
	printf("������2��ֵ�ֱ�Ϊ�ڵ�x���ڵ�y:");
	scanf("%d%d",&pointx,&pointy);
	map[pointx-1][pointy-1]=map[pointy-1][pointx-1]=INF;
	printf("qihongfei")

}
