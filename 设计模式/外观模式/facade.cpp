#include <iostream>

using namespace std;


class SubSystenmOne
{
public:
	void MethodOne()
	{
		cout << "子系统方法一" << endl;
	}
};

class SubSystemTwo
{
public:
	void MethodTwo()
	{
		cout << "子系统方法二" << endl;
	}
};

class SubSystemThree
{
public:
	void MethodThree()
	{
		cout << "子系统方法三" << endl;
	}
};

class SubSystemFour
{
public:
	void MethodFour()
	{
		cout << "子系统方法四" << endl;
	}
};

class Facade
{
private:
	SubSystenmOne	*one;
	SubSystemTwo	*two;
	SubSystemThree  *three;
	SubSystemFour	*four;

public:

	Facade()
	{
		one		= new SubSystenmOne();
		two		= new SubSystemTwo();
		three	= new SubSystemThree();
		four	= new SubSystemFour();
	}
	~Facade()
	{
		delete one;
		delete two;
		delete three;
		delete four;
	}

public:
	void MethodA()
	{
		cout << "方法组A：" << endl;
		one->MethodOne();
		two->MethodTwo();
		three->MethodThree();

	}
	void MethodB()
	{
		cout << "方法组B：" << endl;
		four->MethodFour();
		two->MethodTwo();
	}

};

int main(void)
{
	Facade *facade = new Facade();

	facade->MethodA();
	facade->MethodB();

	system("PAUSE");
	return 0;
}