
void Dijkstra(AdjMGraph *G, int v0, int distance[], int path[ ])
/*��ȨͼG���±�0���㵽�����������̾���distance*/
/*�����·���϶���ǰ���±�path*/
{ 
	int n = G->vertices.size;
	int *S = (int *)malloc(sizeof(int)*n); //S����
	int minDis, i, j, u;
    	FILE *fp;  
	/*��ʼ��*/
	for(i = 0; i < n; i ++)
	{ 
		distance[i] = G->edge[v0][i];
		S[i] = 0;
		if(i != v0 && distance[i] < MaxWeight)
			path[i] = v0;
		else path[i] = -1;
	}
	S[v0] = 1;
	/*�ڵ�ǰ��δ�ҵ����·���Ķ��㼯��ѡȡ������̾���Ķ���u*/
	for(i = 1; i < n; i ++)
	{ 
		minDis = MaxWeight;
		for (j = 0;j < n;j ++)
			if(S[j] == 0 && distance[j] < minDis)
			{
				u = j;
				minDis = distance[j];
			}
			/*���Ѳ��ٴ���·��ʱ�㷨����*/
			//if(minDis == MaxWeight) return;
			S[u] = 1; /*��Ƕ���u�ѴӼ���T���뵽����S��*/
			/*�޸Ĵ�v0�������������̾�������·��*/
			for(j = 0; j < n; j++)
				if(S[j] == 0 && G->edge[u][j] < MaxWeight &&
					distance[u] + G->edge[u][j] < distance[j])
				{  
					distance[j] = distance[u] + G->edge[u][j];
					path[j] = u;
				}
	}
	printf("Ŀ��·��  ��һ��·��\n");
	 fp=fopen("luyoubiao.txt","w");
	for(i=0;i<n;i++)
	{
		if (i==v0) continue;
		j=i;
		while(path[j]!=v0)
		{
			j=path[j];
			if (j==-1) break;
		}
		printf("%5d%12d\n",i+1,j+1);
        fprintf(fp,"%5d%12d\n",i+1,j+1);
	}
	fclose(fp);
}

