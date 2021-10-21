#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal
{
public: 
	void speak()
	{
		cout << "猫猫在说话" << endl;
	}
};

void doSpeak(Animal &animal)
{
	animal.speak();
}

void test01()
{
	Cat cat;
	doSpeak(cat);
}

void test02()
{
	cout << "Animal的size是：" << sizeof(Animal) << endl;
}

int main()
{
	test01();
	test02();
	system("pause");

	return 0;
}