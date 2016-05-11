#include <iostream>
#include <exception>  

using namespace std;

/*²Ù×÷*/
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

/*¼Ó*/
class OperationAdd: public Operation
{
public:
	virtual double GetResult()
	{
		return _numA + _numB;
	}
};

/*¼õ*/
class OperationSub: public Operation
{
public:
	virtual double GetResult()
	{
		return _numA - _numB;
	}
};

/*³Ë*/
class OperationMul: public Operation
{
public:
	virtual double GetResult()
	{
		return _numA * _numB;
	}
};

/*³ý*/
class OperationDiv: public Operation
{
public:
	virtual double GetResult()
	{
		return _numA / _numB;
	}
};


class IFactory
{
public:
	virtual Operation* CreatOperation() = 0;
};

class AddFactory: public IFactory
{
public:
	Operation* CreatOperation()
	{
		return new OperationAdd();
	}
};

class SubFactory: public IFactory
{
public:
	Operation* CreatOperation()
	{
		return new OperationSub();
	}
};

class MulFactory: public IFactory
{
public:
	Operation* CreatOperation()
	{
		return new OperationMul();
	}
};

class DivFactory: public IFactory
{
public:
	Operation* CreatOperation()
	{
		return new OperationDiv();
	}
};

int main(void)
{
	IFactory *factory = new AddFactory();
	Operation *operate = factory->CreatOperation();

	operate->_numA = 1;
	operate->_numB = 2;

	int result = operate->GetResult();

	cout<< "1+2 = " << result << endl;

	system("PAUSE");

	return 0;
}