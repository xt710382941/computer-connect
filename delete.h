void deleteP(){
	int point;
	printf("������Ҫɾ��������ڵ���:");
	scanf("%d",&point);
	isDelete[point-1]=true;
	for(int i=0;i<N;i++){
		map[point-1][i]=map[i][point-1]=INF;
	}
	
}
//ɾ��һ����
void deleteS(){ 
	int pointx,pointy;
	printf("������2��ֵ�ֱ�Ϊ�ڵ�x���ڵ�y:");
	scanf("%d%d",&pointx,&pointy);
	map[pointx-1][pointy-1]=map[pointy-1][pointx-1]=INF;
	
}
