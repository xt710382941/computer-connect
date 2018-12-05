#define MaxVertices 100
#define MaxWeight 10000
#include <malloc.h>
//#include "GraphInitiate.h"

void DeleteEdge(AdjMGraph *G,int v1,int v2)
{
	
	
		G->edge[v1][v2]=MaxWeight;
		G->edge[v2][v1]=MaxWeight;
		G->numOfEdges--;
	
}
void DeleteVertex(AdjMGraph *G,int v)
{
	
	int m3,i,j;
		   m3=v-1;
		   if(m3<0||m3>=G->vertices.size)
		   {
			   printf("对不起，此链路内没有您想要删除的路由节点\n");
			   exit(0);
		   }
		   else 
		   { 
			   
	//		   for(i=m3;i<G->vertices.size;i++)
				   for(j=0,i=m3;j<G->vertices.size;j++)
				   {
                       G->edge[j][i]=MaxWeight;

				   }
	//			  for(i=m3;i<G->vertices.size;i++)
					  for(i=m3,j=0;j<G->vertices.size;j++)
						 G->edge[i][j]=MaxWeight;
	//		   for(i=m3;i<G->vertices.size;i++)
//				   G->vertices.list[i]=G->vertices.list[i]-1;
	//		       G->vertices.size--;
	//			printf("删除结点成功\n");
		   }
}
//有没有向是一样的。
//在带权有向图G中取第v个顶点的第一个邻接顶点，如果这样的邻接顶点存在，则返回该顶点在顶点顺序表的序号，否则返回-1.时间复杂度:O(n)。
int GetFirstVex(AdjMGraph G,int v)
{
    int col;DataType x;
	v=v-1;
    
    if(ListGet(G.vertices,v,&x)==0)
    {
        printf("取第一个邻接顶点时参数v越界出错！\n");
        exit(1);
	}
	
	//寻找邻接矩阵v行中从最左开始第一个值非零且非无穷大的权值对应的顶点
	for(col=0;col<G.vertices.size;col++)
        if(G.edge[v][col]>0 && G.edge[v][col] < MaxWeight) 
			return col;
		return -1; 
}

//在带权有向图G中取第v1个顶点的继邻接结点第v2个顶点之后的下一个邻接结点,时间复杂度:O(n)。
int GetNextVex(AdjMGraph G,int v1,int v2)
{
    int col;DataType x;
    
    if((ListGet(G.vertices,v1,&x)==0)||(ListGet(G.vertices,v2,&x)==0))
    {
        printf("取下一邻接顶点时参数v1和v2越界出错！\n");
        exit(1);
	}
	if(G.edge[v1][v2]==0)
	{
		printf("v2不是v1的邻接顶点\n");
        exit(1);
	}
	//寻找邻接矩阵v行中从第v2+1列开始的第一个值非零且非无穷大的权值对应的顶点
	for(col=v2+1;col<G.vertices.size;col++)
        if(G.edge[v1][col]>0 && G.edge[v1][col]<MaxWeight) 
			return col;
        return -1;
}
