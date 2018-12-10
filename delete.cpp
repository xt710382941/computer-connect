#include"delete1.h"
#include<fstream>
#define N 110
#define INF 1<<30
//#include"My.h"
extern int n,m;
extern int map[N][N];
//vis数组，判断找最短路径时该节点是否找过了
//isDelete:判断该节点是否被删除了
extern bool vis[N],isDelete[N];
//qianQu：前驱节点， dis:保存从原点到其他节点的最短距离
extern int dis[N],qianQu[N];
void deleteP(){
	int point;
	printf("请输入要删除的网络节点编号:");
	scanf("%d",&point);
	isDelete[point-1]=true;
	for(int i=0;i<N;i++){
		map[point-1][i]=map[i][point-1]=INF;
	}

}
//删除一条边
void deleteS(){
	int pointx,pointy;
	printf("请输入2个值分别为节点x、节点y:");
	scanf("%d%d",&pointx,&pointy);
	map[pointx-1][pointy-1]=map[pointy-1][pointx-1]=INF;
	printf("qihongfei")

}
