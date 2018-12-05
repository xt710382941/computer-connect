//#include "SeqList.h"
#define MaxVertices 100
#define MaxWeight 10000
#include <malloc.h>

//�ڽӾ���ʵ��ͼ�Ĵ洢���Ͷ���
typedef struct
{
	SeqList vertices;  //��Ŷ����˳���
	int edge[MaxVertices][MaxVertices];//��űߵ��ڽӾ���
	int numOfEdges;  //�ߵ���Ŀ
}AdjMGraph;//ͼ�Ľṹ�嶨��

typedef struct
{
    int row;  //���±�
    int col;  //���±� 
    int weight;  //Ȩֵ
}RowColWeight;//����Ϣ�ṹ�嶨��

//�ô�Ȩ����ͼGΪ��ͼ
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
			
			}//MaxWeight��ʾȨֵ�����
		}
		
		G->numOfEdges=0;  //�ߵ�������Ϊ0
		ListInitiate(&G->vertices);  //����˳����ʼ��
}
