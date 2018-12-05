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
			   printf("�Բ��𣬴���·��û������Ҫɾ����·�ɽڵ�\n");
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
	//			printf("ɾ�����ɹ�\n");
		   }
}
//��û������һ���ġ�
//�ڴ�Ȩ����ͼG��ȡ��v������ĵ�һ���ڽӶ��㣬����������ڽӶ�����ڣ��򷵻ظö����ڶ���˳������ţ����򷵻�-1.ʱ�临�Ӷ�:O(n)��
int GetFirstVex(AdjMGraph G,int v)
{
    int col;DataType x;
	v=v-1;
    
    if(ListGet(G.vertices,v,&x)==0)
    {
        printf("ȡ��һ���ڽӶ���ʱ����vԽ�����\n");
        exit(1);
	}
	
	//Ѱ���ڽӾ���v���д�����ʼ��һ��ֵ�����ҷ�������Ȩֵ��Ӧ�Ķ���
	for(col=0;col<G.vertices.size;col++)
        if(G.edge[v][col]>0 && G.edge[v][col] < MaxWeight) 
			return col;
		return -1; 
}

//�ڴ�Ȩ����ͼG��ȡ��v1������ļ��ڽӽ���v2������֮�����һ���ڽӽ��,ʱ�临�Ӷ�:O(n)��
int GetNextVex(AdjMGraph G,int v1,int v2)
{
    int col;DataType x;
    
    if((ListGet(G.vertices,v1,&x)==0)||(ListGet(G.vertices,v2,&x)==0))
    {
        printf("ȡ��һ�ڽӶ���ʱ����v1��v2Խ�����\n");
        exit(1);
	}
	if(G.edge[v1][v2]==0)
	{
		printf("v2����v1���ڽӶ���\n");
        exit(1);
	}
	//Ѱ���ڽӾ���v���дӵ�v2+1�п�ʼ�ĵ�һ��ֵ�����ҷ�������Ȩֵ��Ӧ�Ķ���
	for(col=v2+1;col<G.vertices.size;col++)
        if(G.edge[v1][col]>0 && G.edge[v1][col]<MaxWeight) 
			return col;
        return -1;
}
