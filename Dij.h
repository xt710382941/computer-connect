
void Dijkstra(int x){
	//ǰ�����鸳��ֵ 
	for(int i=0;i<n;i++){
		qianQu[i]=i;
	}
	//��ԭ��x ��������ľ��� 
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
	//��ԭ�㵽�����ڵ�Ķ���̾��룬������ǰ���ڵ� 
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
//ͨ��ǰ��·�ɲ�����һ��·��
int find(int x,int i){ 
	if(qianQu[i]==x||qianQu[i]==i)
	return i;
	else
	find(x,qianQu[i]);
}
//��ʾ��ĳ�ڵ㿪ʼ�ܹ���ͨ�Ľڵ� 
int show(){
	int point;
	printf("������Ҫ���ɵ�·�ɱ����ʼ·����:");
	scanf("%d",&point);
	if(isDelete[point-1]){
		printf("�˽ڵ㲻����!\n");
		return 0;
	}
	Dijkstra(point-1); 
	printf("Ŀ��·��    ��һ��·�� \n");
	for(int i=0;i<n;i++){
		if(i==point-1) continue;
		//if(isDelete[i]) continue;
		//printf("����%d�޷�����\n",i+1);
		if(isDelete[i]||dis[i]==16843009) continue;
		else
		printf("%5d       %5d\n",i+1,find(point-1,i)+1);
	}
	printf("�Ӷ���%d���������������̾���Ϊ:\n",point);
	for(int i=0;i<n;i++){
		if(isDelete[i]||dis[i]==16843009) continue;
		//printf("�޷����ﶥ��%d!\n",i+1);
		else
		printf("������%d����̾���Ϊ:%d\n",i+1,dis[i]);
	}
	printf("*********************����·������*******************\n");
	memset(vis,0,sizeof(vis));
	
}
