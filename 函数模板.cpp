#include <iostream>
using namespace std;

//函数模板基本语法---------------------------------------------------------------------------------------------------
template<typename T>//typename也可以写成class,效果相同。可以在使用类模板的时候用class，函数模板的时候用typename,方便区分
/*使用注意： 1.必须推导出一致的数据类型T才可以使用，比如test01函数中的mySwap(a, c)是错误的
			2. 模板必须确定T的数据类型，才可以使用*/
void mySwap(T& a, T& b)
{
	T tmp;
	tmp = b;
	b = a;
	a = tmp;
}

void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';

	//1.调用模板方式一：自动类型推导（编译器自动识别typename）
	//注意：必须推导出一致的数据类型T才可以使用，比如mySwap(a,c)是错误的
	mySwap(a, b);
	cout << "第一次调换后a是：" << a << "；b是：" << b << endl;

	//2.调用模板方式二：显示指定类型（手动输入typename）
	mySwap<int>(a, b);
	cout << "第二次调换后a是：" << a << "；b是：" << b << endl;
}

//选择排序---------------------------------------------------------------------------------------------------------------------
//swap template
template<typename T>
void templateSwap(T& a, T& b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

//algorithm part
template<typename T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}

		if (max != i)
		{
			templateSwap(arr[max], arr[i]);
		}
	}
}

template<typename T>
void displayArr(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test02()
{
	//测试char数组
	char charArr[] = { 'a','d','f','c','b','e' };
	int charNum = sizeof(charArr) / sizeof(char);
	mySort(charArr, charNum);
	displayArr(charArr, charNum);
	

	//测试int数组
	int intArr[] = { 2,1,5,8,9,3 };
	int intNum = sizeof(intArr) / sizeof(int);
	mySort(intArr, intNum);
	displayArr(intArr, intNum);
}

//隐式转换类型----------------------------------------------------------------------------------------------------------
/*普通函数与函数模板的区别：
1.普通函数调用可以发生隐式类型转换
2.函数模板用“自动类型推导”，不可以发生隐式类型转换
3.函数模板用“显示指定类型”，可以发生隐式类型转换*/
template<typename T>
T myAdd(T a, T b)
{
	return a + b;
}

void test03()
{
	int a = 10;
	int b = 20;
	char c = 'c';

	//myAdd(a , c);错误
	myAdd<int>(a, c);//正确，发生隐式类型转换
	cout << myAdd<int>(a, c) << endl;

}

//普通函数与函数模板调用规则---------------------------------------------------------------------------------------------------------
/*1.两者都可用时优先调用普通函数
  2.函数模板产生更好的匹配时优先调用函数模板
  3.函数模板可以重载
  4.可以用空模板参数列表强制调用函数模板*/
void myPrint(int a, int b)
{
	cout << "调用普通函数" << endl;
}

//函数模板与普通函数可以重载
template<typename T>
void myPrint(T a, T b)
{
	cout << "调用函数模板" << endl;
}

//函数模板之间也可以重载
template<typename T>
void myPrint(T a, T b, T c)
{
	cout << "调用重载后的函数模板" << endl;
}

void test04()
{
	int a = 10, b =20, c = 30;
	myPrint(a, b);//调用普通函数
	myPrint('a', 'b');//优先调用函数模板
	myPrint<>(a, b);//强制调用函数模板
	myPrint(a, b, c);//调用重载函数
}

//模板的局限性-------------------------------------------------------------------------------------------------------
//y有些特定数据类型需要用具体化方式做特殊实现

//对比两个数据是否相等
template<typename T>
bool myCompare(T& a,T& b)
{
	if (a == b)
		return true;
	return false;
}

class Person
{
public:

	Person(string name, int age)
	{
		this->myAge = age;
		this->myName = name;
	}
	string myName;
	int myAge;
};

template<> bool myCompare(Person& a, Person& b)
{
	if (a.myAge == b.myAge && a.myName == b.myName)
		return true;
	return false;
}

void test05()
{
	int a = 10, b = 20;

	bool ret = myCompare(a, b);

	cout << "案例一：" << endl;
	if (ret)
	{
		cout << "相等" << endl;
	}
	else
		cout << "不相等" << endl;

	//函数模板不能直接适用于自定义的类
	//解决方案：利用具体化Person的版本实现代码，具体化优先调用(见上方person版本的myCompare重载函数）
	cout << "案例二：" << endl;
	Person p1("张三", 10);
	Person p2("张三", 10);
	
	bool ret2 = myCompare(p1, p2);
	if (ret2)
	{
		cout << "相等" << endl;
	}
	else
		cout << "不相等" << endl;

}
int main()
{
	//template基础内容测试
	cout << "1:" << endl;
	test01();
	cout << endl;

	//template案例swap测试
	cout << "2:" << endl;
	test02();
	cout << endl;

	//template案例隐式类型转换
	cout << "3:" << endl;
	test03();
	cout << endl;

	//普通函数与函数模板的调用关系
	cout << "4:" << endl;
	test04();
	cout << endl;

	//函数模板的局限性
	cout << "5:" << endl;
	test05();
	cout << endl;

	//学习模板主要并不是为了写模板，而是在STL中能够运用系统提供的模板
	system("pause");

	return 0;
}