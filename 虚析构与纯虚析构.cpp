#include<iostream>
using namespace std;
#include<string>

class Animal
{
public:
	Animal()
	{
		cout << "Animal�Ĺ��캯��" << endl;
	}

	virtual ~Animal()
	{
		cout << "Animal����������" << endl;
	}

	virtual void Speak() = 0;
};

class Cat :public Animal 
{
public:
	Cat(string name)
	{
		cout << "Cat�Ĺ��캯��" << endl;
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
			cout << "Cat����������" << endl;
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
	//�����ָ��������ʱ������������������������������п����ڶ����Ķ���ʱ�����ڴ�й©
	//�����ʽ���ڸ�����ʹ��������virtual ~Animal(){}
	delete creature;
}

//int main()
//{
//	test03();
//
//	return 0;
//}