#include <iostream>
using namespace std;

//����ģ������﷨---------------------------------------------------------------------------------------------------
template<typename T>//typenameҲ����д��class,Ч����ͬ��������ʹ����ģ���ʱ����class������ģ���ʱ����typename,��������
/*ʹ��ע�⣺ 1.�����Ƶ���һ�µ���������T�ſ���ʹ�ã�����test01�����е�mySwap(a, c)�Ǵ����
			2. ģ�����ȷ��T���������ͣ��ſ���ʹ��*/
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

	//1.����ģ�巽ʽһ���Զ������Ƶ����������Զ�ʶ��typename��
	//ע�⣺�����Ƶ���һ�µ���������T�ſ���ʹ�ã�����mySwap(a,c)�Ǵ����
	mySwap(a, b);
	cout << "��һ�ε�����a�ǣ�" << a << "��b�ǣ�" << b << endl;

	//2.����ģ�巽ʽ������ʾָ�����ͣ��ֶ�����typename��
	mySwap<int>(a, b);
	cout << "�ڶ��ε�����a�ǣ�" << a << "��b�ǣ�" << b << endl;
}

//ѡ������---------------------------------------------------------------------------------------------------------------------
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
	//����char����
	char charArr[] = { 'a','d','f','c','b','e' };
	int charNum = sizeof(charArr) / sizeof(char);
	mySort(charArr, charNum);
	displayArr(charArr, charNum);
	

	//����int����
	int intArr[] = { 2,1,5,8,9,3 };
	int intNum = sizeof(intArr) / sizeof(int);
	mySort(intArr, intNum);
	displayArr(intArr, intNum);
}

//��ʽת������----------------------------------------------------------------------------------------------------------
/*��ͨ�����뺯��ģ�������
1.��ͨ�������ÿ��Է�����ʽ����ת��
2.����ģ���á��Զ������Ƶ����������Է�����ʽ����ת��
3.����ģ���á���ʾָ�����͡������Է�����ʽ����ת��*/
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

	//myAdd(a , c);����
	myAdd<int>(a, c);//��ȷ��������ʽ����ת��
	cout << myAdd<int>(a, c) << endl;

}

//��ͨ�����뺯��ģ����ù���---------------------------------------------------------------------------------------------------------
/*1.���߶�����ʱ���ȵ�����ͨ����
  2.����ģ��������õ�ƥ��ʱ���ȵ��ú���ģ��
  3.����ģ���������
  4.�����ÿ�ģ������б�ǿ�Ƶ��ú���ģ��*/
void myPrint(int a, int b)
{
	cout << "������ͨ����" << endl;
}

//����ģ������ͨ������������
template<typename T>
void myPrint(T a, T b)
{
	cout << "���ú���ģ��" << endl;
}

//����ģ��֮��Ҳ��������
template<typename T>
void myPrint(T a, T b, T c)
{
	cout << "�������غ�ĺ���ģ��" << endl;
}

void test04()
{
	int a = 10, b =20, c = 30;
	myPrint(a, b);//������ͨ����
	myPrint('a', 'b');//���ȵ��ú���ģ��
	myPrint<>(a, b);//ǿ�Ƶ��ú���ģ��
	myPrint(a, b, c);//�������غ���
}

//ģ��ľ�����-------------------------------------------------------------------------------------------------------
//y��Щ�ض�����������Ҫ�þ��廯��ʽ������ʵ��

//�Ա����������Ƿ����
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

	cout << "����һ��" << endl;
	if (ret)
	{
		cout << "���" << endl;
	}
	else
		cout << "�����" << endl;

	//����ģ�岻��ֱ���������Զ������
	//������������þ��廯Person�İ汾ʵ�ִ��룬���廯���ȵ���(���Ϸ�person�汾��myCompare���غ�����
	cout << "��������" << endl;
	Person p1("����", 10);
	Person p2("����", 10);
	
	bool ret2 = myCompare(p1, p2);
	if (ret2)
	{
		cout << "���" << endl;
	}
	else
		cout << "�����" << endl;

}
int main()
{
	//template�������ݲ���
	cout << "1:" << endl;
	test01();
	cout << endl;

	//template����swap����
	cout << "2:" << endl;
	test02();
	cout << endl;

	//template������ʽ����ת��
	cout << "3:" << endl;
	test03();
	cout << endl;

	//��ͨ�����뺯��ģ��ĵ��ù�ϵ
	cout << "4:" << endl;
	test04();
	cout << endl;

	//����ģ��ľ�����
	cout << "5:" << endl;
	test05();
	cout << endl;

	//ѧϰģ����Ҫ������Ϊ��дģ�壬������STL���ܹ�����ϵͳ�ṩ��ģ��
	system("pause");

	return 0;
}