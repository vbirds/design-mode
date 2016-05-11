#include <iostream>

using namespace std;


class AbstractClass
{
public:
	virtual void PrimitiOperation1() = 0;
	virtual void PrimitiOperation2() = 0;
public:
	void TemplateMethod() 
	{
		PrimitiOperation1();
		PrimitiOperation2();
		cout << " " << endl;
	}
};


class ConcreteClassA :  public AbstractClass
{
public:
	void PrimitiOperation1()
	{
		cout << "具体类A 方法1实现" << endl;
	}
	void PrimitiOperation2()
	{
		cout << "具体类A 方法2实现" << endl;
	}

};

class ConcreteClassB :  public AbstractClass
{
public:
	void PrimitiOperation1()
	{
		cout << "具体类B 方法1实现" << endl;
	}
	void PrimitiOperation2()
	{
		cout << "具体类B 方法2实现" << endl;
	}

};


int main(void)
{
	AbstractClass *p1;
	p1 = new ConcreteClassA();
	p1->TemplateMethod();

	delete p1;
	p1 = new ConcreteClassB();
	p1->TemplateMethod();

	system("PAUSE");
	return 0;
}