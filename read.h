void read(){
	//定义文件输入流 
	ifstream Read;
	Read.open("tuoputu10.txt");
	Read>>n;
	for(int i=0;i<n;i++){
		int x;Read>>x;
		isDelete[x-1]=0;
	}
	Read>>m;
	for(int i=0;i<m;i++){
		int x,y,len;
		Read>>x>>y>>len;
		map[x][y]=map[y][x]=len;
	}
	Read.close();
} 
