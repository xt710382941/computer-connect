//#include "SeqList.h"
#define MaxVertices 100
#define MaxWeight 10000
#include <malloc.h>
//#include "GraphInitiate.h"
void InsertVertex(AdjMGraph *G,DataType vertex)
{
	//if(IsVertex(G,vertex)<0)
		if(ListInsert(&G->vertices,G->vertices.size,vertex)==0)//�ڶ���˳���ı�β���붥��vertex
		{
			printf("���붥��ʱ�ռ������޷����룡");
			exit(1);
		}
}
void InsertEdge(AdjMGraph *G,int v1,int v2,int weight)
{
	DataType x;
	if(v1!=v2)
	{
		if((ListGet(G->vertices,v1,&x)==0)||(ListGet(G->vertices,v2,&x)==0))
		{
			printf("�����ʱ����v1��v2Խ�����\n");
			exit(1);
		}
		
		G->edge[v1][v2]=weight;
		G->edge[v2][v1]=weight;
		G->numOfEdges++;
	}
}

