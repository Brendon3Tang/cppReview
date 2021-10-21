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
		cout << "Intel的CPU开始运行..." << endl;
	}
};

class IntelVideoCard :public VideoCard
{
	void display()
	{
		cout << "Intel的VideoCard开始运行..." << endl;
	}
};

class IntelMemory :public Memory
{
	void storage()
	{
		cout << "Intel的Memory开始运行..." << endl;
	}
};

//===========================================================NVIDIA=====================================================
class NvidiaCPU :public CPU
{
	void calculate()
	{
		cout << "Nvidia的CPU开始运行..." << endl;
	}
};

class NvidiaVideoCard :public VideoCard
{
	void display()
	{
		cout << "Nvidia的VideoCard开始运行..." << endl;
	}
};

class NvidiaMemory :public Memory
{
	void storage()
	{
		cout << "Nvidia的Memory开始运行..." << endl;
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
		cout << "=======================================电脑开始组装=======================================" << endl;
		myCPU->calculate();
		myVC->display();
		myMemory->storage();
		cout << "=======================================电脑组装完毕=======================================" << endl;
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

	//此时如果不用新方式传参数会报错，因为上方delete cmp1 与 cmp2时已经delete了所有的
	//配件对象（myIntelCPU，myNvidiaCPU，myIntelVC，myNvidiaVC，myIntelMemory，myNvidiaMemory），无法继续在下方使用
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