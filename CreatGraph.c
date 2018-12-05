//#include "SeqList.h"
#define MaxVertices 100
#define MaxWeight 10000
#include <malloc.h>
#include"CreatGraph.h"
void CreatGraph(AdjMGraph *G,DataType v[],int n,RowColWeight W[],int e)
{
	int i,k;
	
	GraphInitiate(G);
	for(i=0;i<n;i++)
	{
			//cout<<n<<endl;
			InsertVertex(G,v[i]);
	}
	for(k=0;k<e;k++)
        InsertEdge(G,W[k].row,W[k].col,W[k].weight);
}
