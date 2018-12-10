#include<iostream>
#include"My.h"
#include"Dij.h"
#include"delete.h"
#include"add.h"
#include"read.h"
using namespace std;
int main(){
	memset(map,1,sizeof(map));
	memset(vis,0,sizeof(vis));
	memset(isDelete,1,sizeof(isDelete));
	read();
	while(1){
		int n;
		menu();
		scanf("%d",&n);
		switch(n){
			case 1:show();break;
			case 2:deleteP();break;
			case 3:deleteS();break;
			case 4:addP();break;
			case 5:addS();break;
			case 6:system("cls");menu();break;
			case 7:exit(0);break;
		}
	}
}
