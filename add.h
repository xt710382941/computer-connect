void addP(){
	void addS();
	int point,sideGe;
	printf("������Ҫ��������ڵ���:");
	scanf("%d",&point);
	isDelete[point-1]=false;
	n++;
	printf("��������Ҫ����Ϊ����ڵ㽨��������:");
	scanf("%d",&sideGe);
	for(int i=0;i<sideGe;i++);
	{
	addS();}
	
}
//����һ���� 
bool addS(){
	int pointx,pointy,len;
	printf("������3��ֵ�ֱ�Ϊ�ڵ�x���ڵ�y���ڵ�x��y�ߵĳ���:");
	scanf("%d%d%d",&pointx,&pointy,&len);
	map[pointx-1][pointy-1]=map[pointy-1][pointx-1]=len;

}
