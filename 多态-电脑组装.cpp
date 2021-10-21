#include<iostream>
using namespace std;
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

class CPU
{
public:
	virtual void calculate() = 0;
};

class VideoCard
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};
//===========================================================INTEL=====================================================
class IntelCPU :public CPU
{
	void calculate()
	{
		cout << "Intel��CPU��ʼ����..." << endl;
	}
};

class IntelVideoCard :public VideoCard
{
	void display()
	{
		cout << "Intel��VideoCard��ʼ����..." << endl;
	}
};

class IntelMemory :public Memory
{
	void storage()
	{
		cout << "Intel��Memory��ʼ����..." << endl;
	}
};

//===========================================================NVIDIA=====================================================
class NvidiaCPU :public CPU
{
	void calculate()
	{
		cout << "Nvidia��CPU��ʼ����..." << endl;
	}
};

class NvidiaVideoCard :public VideoCard
{
	void display()
	{
		cout << "Nvidia��VideoCard��ʼ����..." << endl;
	}
};

class NvidiaMemory :public Memory
{
	void storage()
	{
		cout << "Nvidia��Memory��ʼ����..." << endl;
	}
};

class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* memory)
	{
		myCPU = cpu;
		myVC = vc;
		myMemory = memory;
	}

	~Computer()
	{
		if (myCPU != nullptr)
		{ 
			delete myCPU;
			myCPU = NULL;
		}

		if (myMemory != nullptr)
		{
			delete myMemory;
			myMemory = NULL;
		}

		if (myVC != nullptr)
		{
			delete myVC;
			myVC = NULL;
		}
	
	}

	void Work()
	{
		cout << "=======================================���Կ�ʼ��װ=======================================" << endl;
		myCPU->calculate();
		myVC->display();
		myMemory->storage();
		cout << "=======================================������װ���=======================================" << endl;
		cout << endl;
	}

private:
	CPU* myCPU;
	VideoCard* myVC;
	Memory* myMemory;
};

void test04()
{
	CPU* myIntelCPU = new IntelCPU;
	CPU* myNvidiaCPU = new NvidiaCPU;
	VideoCard *myIntelVC = new IntelVideoCard;
	VideoCard* myNvidiaVC = new NvidiaVideoCard;
	Memory *myIntelMemory = new IntelMemory;
	Memory* myNvidiaMemory = new NvidiaMemory;


	Computer *cmp1 = new Computer(myIntelCPU, myIntelVC, myIntelMemory);
	cmp1->Work();
	delete cmp1;

	Computer* cmp2 = new Computer(myNvidiaCPU, myNvidiaVC, myNvidiaMemory);
	cmp2->Work();
	delete cmp2;

	//��ʱ��������·�ʽ�������ᱨ����Ϊ�Ϸ�delete cmp1 �� cmp2ʱ�Ѿ�delete�����е�
	//�������myIntelCPU��myNvidiaCPU��myIntelVC��myNvidiaVC��myIntelMemory��myNvidiaMemory�����޷��������·�ʹ��
	Computer* cmp3 = new Computer(new IntelCPU, new NvidiaVideoCard, new IntelMemory);
	cmp3->Work();
	delete cmp3;
}

int main()
{
	test04();
	_CrtDumpMemoryLeaks();
	
	return 0;
}