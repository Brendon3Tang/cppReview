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
		cout << "��ˮ" << endl;
	}

	void Brew() {
		cout << "�忧��" << endl;
	}

	void PourInCup() {
		cout << "���뱭��" << endl;
	}

	void PutSth()
	{
		cout << "���ǡ�ţ��" << endl;
	}
};

class Tea :public AbstractDrinking {
	void Boil() {
		cout << "��ˮ" << endl;
	}

	void Brew() {
		cout << "�Ų�Ҷ" << endl;
	}

	void PourInCup() {
		cout << "���뱭��" << endl;
	}

	void PutSth()
	{
		cout << "���ǡ�����" << endl;
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