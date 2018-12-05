
void Dijkstra(AdjMGraph *G, int v0, int distance[], int path[ ])
/*带权图G从下标0顶点到其它顶点的最短距离distance*/
/*和最短路径上顶点前驱下标path*/
{ 
	int n = G->vertices.size;
	int *S = (int *)malloc(sizeof(int)*n); //S数组
	int minDis, i, j, u;
    	FILE *fp;  
	/*初始化*/
	for(i = 0; i < n; i ++)
	{ 
		distance[i] = G->edge[v0][i];
		S[i] = 0;
		if(i != v0 && distance[i] < MaxWeight)
			path[i] = v0;
		else path[i] = -1;
	}
	S[v0] = 1;
	/*在当前还未找到最短路径的顶点集中选取具有最短距离的顶点u*/
	for(i = 1; i < n; i ++)
	{ 
		minDis = MaxWeight;
		for (j = 0;j < n;j ++)
			if(S[j] == 0 && distance[j] < minDis)
			{
				u = j;
				minDis = distance[j];
			}
			/*当已不再存在路径时算法结束*/
			//if(minDis == MaxWeight) return;
			S[u] = 1; /*标记顶点u已从集合T加入到集合S中*/
			/*修改从v0到其它顶点的最短距离和最短路径*/
			for(j = 0; j < n; j++)
				if(S[j] == 0 && G->edge[u][j] < MaxWeight &&
					distance[u] + G->edge[u][j] < distance[j])
				{  
					distance[j] = distance[u] + G->edge[u][j];
					path[j] = u;
				}
	}
	printf("目的路由  下一跳路由\n");
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

