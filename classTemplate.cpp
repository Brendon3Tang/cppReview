#include<iostream>
using namespace std;

//��ģ������﷨��
template<class NameType, class AgeType = int>//����Ҫ�������ͱ���ʱ�Ķ��巽��
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
		cout << "�����ǣ�" << this->myName << endl;
		cout << "�����ǣ�" << this->myAge << endl;
	}

	NameType myName;
	AgeType myAge;
};


//����ģ������ģ�������==============================================================================================================================
/*1.��ģ���޷�ʹ���Զ������Ƶ�
* 2.��ģ����ģ��Ĳ����б��п�����Ĭ�����Ͳ���
*/

//1.��ģ���޷�ʹ���Զ������Ƶ�
void test01()
{
	//Person p1("�����", 999); 1.��ģ���޷�ʹ���Զ������Ƶ�
	Person<string, int> p1("�����", 999); //ֻ������ʾָ������
	p1.showPerson();
}

//2.��ģ����ģ��Ĳ����б��п�����Ĭ�����Ͳ�������line 5)
void test02()
{
	Person<string> p("��˽�", 999);//�����б�����Ĭ�����Ͳ���,���Բ���ȫ��argument������
	p.showPerson();
}


//��ģ���������������==============================================================================================================================
//1.����ָ������  ʵ�ʿ����г��ã���Ϊֱ������
void printPerson1(Person<string, int> &p)
{
	p.showPerson();
}

void test03a()
{
	Person<string, int>p("�����2", 100);
	printPerson1(p);
}

//2.����ģ�廯
template<class NameType, class AgeType>
void printPerson2(Person<NameType, AgeType>& p)
{
	p.showPerson();
}

void test03b()
{
	Person<string, int>p2("��˽�2", 100);
	printPerson2(p2);
}

//3.������ģ�廯
template<class T>
void printPerson1(T& p)
{
	p.showPerson();
}

void test03c()
{
	Person<string, int>p3("��ɮ", 100);
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