#include <iostream>
#include <exception>  

using namespace std;

/*操作*/
class Operation
{
public:
	int _numA;
	int _numB;
public:
	virtual  double GetResult()
	{
		return 0;
	}
};

/*加*/
class OperationAdd: public Operation
{
public:
	virtual double GetResult()
	{
		return _numA + _numB;
	}
};

/*减*/
class OperationSub: public Operation
{
public:
	virtual double GetResult()
	{
		return _numA - _numB;
	}
};

/*乘*/
class OperationMul: public Operation
{
public:
	virtual double GetResult()
	{
		return _numA * _numB;
	}
};

/*除*/
class OperationDiv: public Operation
{
public:
	virtual double GetResult()
	{
		return _numA / _numB;
	}
};

/*工厂*/
class OperationFactory
{
public:
	static Operation* CreateOperation(char operate)
	{
		Operation *oper = NULL;
		switch(operate)
		{
		case  '+':
			oper = new OperationAdd();
			break;
		case '-':
			oper = new OperationSub();
			break;
		case '*':
			oper = new OperationMul();
			break;
		case '/':
			oper = new OperationDiv();
			break;
		default :
			break;
		}
		return oper;
	}
};


int main(void)
{
	Operation *oper = NULL;
	int numA = 0;
	int numB = 0;
	char operate ='0';

	cout<< "请输入数A： ";
	cin >> numA;

	cout<< "请输入运算符：";
	cin >> operate;

	cout<< "请输入数B： ";
	cin >> numB;

	oper = OperationFactory::CreateOperation(operate);

	try
	{
		oper->_numA = numA;
		oper->_numB = numB;

		cout << numA << operate << numB << "=" << oper->GetResult() << endl;

	}
	catch (exception& e)
	{
		cout << "出现异常" << e.what() <<endl;
	}

	system("PAUSE");
	return 0;
}