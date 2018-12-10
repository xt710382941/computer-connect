void deleteP(){
	int point;
	printf("请输入要删除的网络节点编号:");
	scanf("%d",&point);
	isDelete[point-1]=true;
	for(int i=0;i<N;i++){
		map[point-1][i]=map[i][point-1]=INF;
	}
	
}
//删除一条边
void deleteS(){ 
	int pointx,pointy;
	printf("请输入2个值分别为节点x、节点y:");
	scanf("%d%d",&pointx,&pointy);
	map[pointx-1][pointy-1]=map[pointy-1][pointx-1]=INF;
	
}
