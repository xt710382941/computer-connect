
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
