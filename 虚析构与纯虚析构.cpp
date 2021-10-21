#include<iostream>
using namespace std;
#include<string>

class Animal
{
public:
	Animal()
	{
		cout << "Animal的构造函数" << endl;
	}

	virtual ~Animal()
	{
		cout << "Animal的析构函数" << endl;
	}

	virtual void Speak() = 0;
};

class Cat :public Animal 
{
public:
	Cat(string name)
	{
		cout << "Cat的构造函数" << endl;
		Name = new string(name);
	}

	void Speak()
	{
		cout << *Name << "kitty is speaking" << endl;
	}

	~Cat()
	{
		if (Name != NULL)
		{
			cout << "Cat的析构函数" << endl;
			delete Name;
			Name = NULL;
		}
	}

	string *Name;
};

void test03()
{
	Animal* creature = new Cat("Trition");
	creature->Speak();
	//父类的指针在析构时不会调用子类的析构函数，因此子类有开辟在堆区的对象时会有内存泄漏
	//解决方式：在父类中使用虚析构virtual ~Animal(){}
	delete creature;
}

//int main()
//{
//	test03();
//
//	return 0;
//}