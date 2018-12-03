#include <iostream>    
#include <string>  
#include <stdlib.h>  
#include <time.h>  



using namespace std;

const int PACK_MAX_W = 80;                  //背包最大承受重量    
const int NUM = 32;                         //物品数  
const int MAX_GENERATION = 100;             //遗传最大代数  
const int PS = 500;                         //种群规模  
const float PC = 0.8;                       //交叉率  
const float PV = 0.1;                      //变异率  


const int zl[NUM] = { 22,15,4,5,10,19,21,20,8,13,2,3,3,17,12,5,12,4,1,21,14,23,17,15,20,22,25,0,22,15,25,13 };
const int value[NUM] = { 8,9,15,6,16,9,1,4,14,9,3,7,12,4,15,5,18,5,15,4,6,2,12,14,11,9,13,13,14,13,19,4 };

//随机产生01  
int pp() {
	float p;
	p = rand() % 1000 / 1000.0;
	if (p < 0.8)
	{ 
		return 0;
	}
	else
	{ 
		return 1;
	}
}
//个体类  
class Entity {
public:
	int fit;
	int sum_w;
	int sum_val;
	int gene[NUM];
	int _count;

	Entity() {
		fit = 0;
		sum_w = 0;
		sum_val = 0;
		int i;
		for (i = 0; i < NUM; i++)
			gene[i] = 0;
	}

};

//遗传算法类  
class GA {

private:

	Entity zq[PS];                          //种群  
	Entity max_single;                      //最优个体  

public: 
	void Init();
	//计算个体价值重量 
	int Cal_SingleValue(int row);

	int Cal_SingleW(int row);

	//计算个体适应度  
	void Cal_Fitness();
	//计算价值最大个体  
	void Cal_Maxval_Single(int _generation);
	//选择  
	void Select();
	//是否交叉  
	bool IsCross() { return ((rand() % 1000 / 1000.0) <= PC); }
	//交叉  
	void Cross();
	//是否变异  
	bool IsVariation() { return ((rand() % 1000 / 1000.0) <= PV); }
	//变异  
	void Variation();
	//进行遗传，每五代几率变异  
	void Run() {
		int i; 
		Init();
		for (i = 0; i < MAX_GENERATION; i++) {
			Cal_Fitness();
			Cal_Maxval_Single(i);
			Select();
			Cross();
			if (i % 5 == 0 && i != 0) {
				Variation();
			}
		}
		Cal_Fitness();
		Cal_Maxval_Single(MAX_GENERATION);
		cout << "最大价值是:" << max_single.fit << endl;
		cout << "最优个体的基因是:" << endl;
		for (int i = 0; i < NUM; i++) {
			cout << max_single.gene[i];
			if (i != NUM - 1)
				cout << " ";
		}

		cout << endl << "最优个体是在第" << max_single._count << "代." << endl;

	}
};
