#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};

class Cat :public Animal
{
public: 
	void speak()
	{
		cout << "èè��˵��" << endl;
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
	cout << "Animal��size�ǣ�" << sizeof(Animal) << endl;
}

int main()
{
	test01();
	test02();
	system("pause");

	return 0;
}