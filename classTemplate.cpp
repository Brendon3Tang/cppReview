#include<iostream>
using namespace std;

//类模板基本语法：
template<class NameType, class AgeType = int>//当需要多种类型变量时的定义方法
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->myName = name;
		this->myAge = age;
	}

	void showPerson()
	{
		cout << "名字是：" << this->myName << endl;
		cout << "年龄是：" << this->myAge << endl;
	}

	NameType myName;
	AgeType myAge;
};


//函数模板与类模板的区别==============================================================================================================================
/*1.类模板无法使用自动类型推导
* 2.类模板在模板的参数列表中可以有默认类型参数
*/

//1.类模板无法使用自动类型推导
void test01()
{
	//Person p1("孙悟空", 999); 1.类模板无法使用自动类型推导
	Person<string, int> p1("孙悟空", 999); //只能用显示指定类型
	p1.showPerson();
}

//2.类模板在模板的参数列表中可以有默认类型参数（见line 5)
void test02()
{
	Person<string> p("猪八戒", 999);//参数列表中有默认类型参数,所以不用全部argument都定义
	p.showPerson();
}


//类模板对象做函数参数==============================================================================================================================
//1.传入指定类型  实际开发中常用，因为直接清晰
void printPerson1(Person<string, int> &p)
{
	p.showPerson();
}

void test03a()
{
	Person<string, int>p("孙悟空2", 100);
	printPerson1(p);
}

//2.参数模板化
template<class NameType, class AgeType>
void printPerson2(Person<NameType, AgeType>& p)
{
	p.showPerson();
}

void test03b()
{
	Person<string, int>p2("猪八戒2", 100);
	printPerson2(p2);
}

//3.整个类模板化
template<class T>
void printPerson1(T& p)
{
	p.showPerson();
}

void test03c()
{
	Person<string, int>p3("唐僧", 100);
	printPerson1(p3);
}


int main()
{
	test01();
	test02();
	test03a();
	test03b();
	test03c();
	return 0;
}