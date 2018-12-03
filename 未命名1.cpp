#include <iostream>    
#include <string>  
#include <stdlib.h>  
#include <time.h>  



using namespace std;

const int PACK_MAX_W = 80;                  //��������������    
const int NUM = 32;                         //��Ʒ��  
const int MAX_GENERATION = 100;             //�Ŵ�������  
const int PS = 500;                         //��Ⱥ��ģ  
const float PC = 0.8;                       //������  
const float PV = 0.1;                      //������  


const int zl[NUM] = { 22,15,4,5,10,19,21,20,8,13,2,3,3,17,12,5,12,4,1,21,14,23,17,15,20,22,25,0,22,15,25,13 };
const int value[NUM] = { 8,9,15,6,16,9,1,4,14,9,3,7,12,4,15,5,18,5,15,4,6,2,12,14,11,9,13,13,14,13,19,4 };

//�������01  
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
//������  
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

//�Ŵ��㷨��  
class GA {

private:

	Entity zq[PS];                          //��Ⱥ  
	Entity max_single;                      //���Ÿ���  

public: 
	void Init();
	//��������ֵ���� 
	int Cal_SingleValue(int row);

	int Cal_SingleW(int row);

	//���������Ӧ��  
	void Cal_Fitness();
	//�����ֵ������  
	void Cal_Maxval_Single(int _generation);
	//ѡ��  
	void Select();
	//�Ƿ񽻲�  
	bool IsCross() { return ((rand() % 1000 / 1000.0) <= PC); }
	//����  
	void Cross();
	//�Ƿ����  
	bool IsVariation() { return ((rand() % 1000 / 1000.0) <= PV); }
	//����  
	void Variation();
	//�����Ŵ���ÿ������ʱ���  
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
		cout << "����ֵ��:" << max_single.fit << endl;
		cout << "���Ÿ���Ļ�����:" << endl;
		for (int i = 0; i < NUM; i++) {
			cout << max_single.gene[i];
			if (i != NUM - 1)
				cout << " ";
		}

		cout << endl << "���Ÿ������ڵ�" << max_single._count << "��." << endl;

	}
};
