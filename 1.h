#ifndef __H
#define _A_H 1
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
