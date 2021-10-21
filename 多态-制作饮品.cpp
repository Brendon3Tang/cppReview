#include<iostream>
using namespace std;

class AbstractDrinking {
public:
	virtual void Boil() = 0;

	virtual void Brew() = 0;

	virtual void PourInCup() = 0;

	virtual void PutSth() = 0;

	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSth();
	}
};

class Coffee :public AbstractDrinking{
	void Boil() {
		cout << "ÖóË®" << endl;
	}

	void Brew() {
		cout << "³å¿§·È" << endl;
	}

	void PourInCup() {
		cout << "µ¹Èë±­×Ó" << endl;
	}

	void PutSth()
	{
		cout << "·ÅÌÇ¡¢Å£ÄÌ" << endl;
	}
};

class Tea :public AbstractDrinking {
	void Boil() {
		cout << "ÖóË®" << endl;
	}

	void Brew() {
		cout << "·Å²èÒ¶" << endl;
	}

	void PourInCup() {
		cout << "µ¹Èë±­×Ó" << endl;
	}

	void PutSth()
	{
		cout << "·ÅÌÇ¡¢·äÃÛ" << endl;
	}
};

void doWork(AbstractDrinking* machine) {
	machine->makeDrink();
	delete machine;
}

void test02() {
	doWork(new Coffee);
	doWork(new Tea);
}

//int main()
//{
//	test02();
//}