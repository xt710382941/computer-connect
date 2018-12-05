//#include "SeqList.h"
#define MaxVertices 100
#define MaxWeight 10000
#include <malloc.h>

//邻接矩阵实现图的存储类型定义
typedef struct
{
	SeqList vertices;  //存放顶点的顺序表
	int edge[MaxVertices][MaxVertices];//存放边的邻接矩阵
	int numOfEdges;  //边的数目
}AdjMGraph;//图的结构体定义

typedef struct
{
    int row;  //行下标
    int col;  //列下标 
    int weight;  //权值
}RowColWeight;//边信息结构体定义

//置带权有向图G为空图
void GraphInitiate(AdjMGraph *G)
{
	int i,j;
	
	for(i=0;i<MaxVertices;i++)
		for(j=0;j<MaxVertices;j++)
		{
			if(i==j) {
				G->edge[i][j]=0;
				
			}
			else  {
				G->edge[i][j]=MaxWeight; 
			
			}//MaxWeight表示权值无穷大
		}
		
		G->numOfEdges=0;  //边的条数置为0
		ListInitiate(&G->vertices);  //顶点顺序表初始化
}
