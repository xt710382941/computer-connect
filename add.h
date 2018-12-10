void addP(){
	void addS();
	int point,sideGe;
	printf("请输入要增加网络节点编号:");
	scanf("%d",&point);
	isDelete[point-1]=false;
	n++;
	printf("请输入你要建立为这个节点建立几条边:");
	scanf("%d",&sideGe);
	for(int i=0;i<sideGe;i++);
	{
	addS();}
	
}
//增加一条边 
bool addS(){
	int pointx,pointy,len;
	printf("请输入3个值分别为节点x、节点y、节点x到y边的长度:");
	scanf("%d%d%d",&pointx,&pointy,&len);
	map[pointx-1][pointy-1]=map[pointy-1][pointx-1]=len;

}
