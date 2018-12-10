
void Dijkstra(int x){
	//前驱数组赋初值 
	for(int i=0;i<n;i++){
		qianQu[i]=i;
	}
	//从原点x 到其他点的距离 
	for(int i=0;i<n;i++){
		if(isDelete[i]) continue;
		if(map[x][i]==0)
		dis[i]=INF;
		else{
			dis[i]=map[x][i];
			qianQu[i]=x;
		}
		dis[x]=0;
	}
	//找原点到其他节点的额最短距离，并保存前驱节点 
	int yuan;
	while((yuan=findMin())!=-1){
		for(int i=0;i<n;i++){
			if(isDelete[i]) continue;
			if(vis[i]) continue;
			if(map[yuan][i]+dis[yuan]<dis[i]){
				dis[i]=map[yuan][i]+dis[yuan];
				qianQu[i]=yuan;
			}
		}
	}
} 
//通过前驱路由查找下一跳路由
int find(int x,int i){ 
	if(qianQu[i]==x||qianQu[i]==i)
	return i;
	else
	find(x,qianQu[i]);
}
//显示从某节点开始能够连通的节点 
int show(){
	int point;
	printf("请输入要生成的路由表的起始路由器:");
	scanf("%d",&point);
	if(isDelete[point-1]){
		printf("此节点不存在!\n");
		return 0;
	}
	Dijkstra(point-1); 
	printf("目的路由    下一跳路由 \n");
	for(int i=0;i<n;i++){
		if(i==point-1) continue;
		//if(isDelete[i]) continue;
		//printf("顶点%d无法到达\n",i+1);
		if(isDelete[i]||dis[i]==16843009) continue;
		else
		printf("%5d       %5d\n",i+1,find(point-1,i)+1);
	}
	printf("从顶点%d到其他各顶点的最短距离为:\n",point);
	for(int i=0;i<n;i++){
		if(isDelete[i]||dis[i]==16843009) continue;
		//printf("无法到达顶点%d!\n",i+1);
		else
		printf("到顶点%d的最短距离为:%d\n",i+1,dis[i]);
	}
	printf("*********************网络路由生成*******************\n");
	memset(vis,0,sizeof(vis));
	
}
