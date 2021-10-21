#include<iostream>
using namespace std;

//抽象类：含有纯虚函数
class AbstractCalculator
{
public:
	virtual int getResult() = 0;//纯虚函数

	int num1 = 0;
	int num2 = 0;
};

class AddCalculator : public AbstractCalculator {
public:
	int getResult() {
		return num1 + num2;
	}
};

class MinusCalculator : public AbstractCalculator {
public:
	int getResult() {
		return num1 - num2;
	}
};

class MulCalculator : public AbstractCalculator {
public:
	int getResult() {
		return num1 * num2;
	}
};

class DivCalculator : public AbstractCalculator {
public:
	int getResult() {
		return num1 / num2;
	}
};

void test01() {
	//加法
	AbstractCalculator* calculator = new AddCalculator();
	calculator->num1 = 100;
	calculator->num2 = 20;
	cout << calculator->num1 << "+" << calculator->num2 << "=" << calculator->getResult() << endl;
	delete calculator;

	//减法
	AbstractCalculator* calculator2 = new MinusCalculator();
	calculator2->num1 = 100;
	calculator2->num2 = 20;
	cout << calculator2->num1 << "-" << calculator2->num2 << "=" << calculator2->getResult() << endl;
	delete calculator2;

	//乘法
	AbstractCalculator* calculator3 = new MulCalculator();
	calculator3->num1 = 100;
	calculator3->num2 = 20;
	cout << calculator3->num1 << "*" << calculator3->num2 << "=" << calculator3->getResult() << endl;
	delete calculator3;

	//除法
	AbstractCalculator* calculator4 = new DivCalculator();
	calculator4->num1 = 100;
	calculator4->num2 = 20;
	cout << calculator4->num1 << "/" << calculator4->num2 << "=" << calculator4->getResult() << endl;
	delete calculator4;
}

//int main() {
//	test01();
//
//	return 0;
//}