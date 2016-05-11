#include <iostream>
#include <exception>  
#include <stdlib.h>

using namespace std;

/************************************************************************/
/*  在原来策略算法的基础上，添加算法类标签，这样在避免在构造的时候暴露
/*  算法定义                                                            */
/************************************************************************/

/*抽象算法类*/
class Strategy
{
public:
	virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategyA: public Strategy
{
public:
	virtual void AlgorithmInterface()
	{
		cout<< "算法A的实现" <<endl;
	}
};

class ConcreteStrategyB: public Strategy
{
public:
	virtual void AlgorithmInterface()
	{
		cout<< "算法B的实现" <<endl;
	}
};

class ConcreteStrategyC: public Strategy
{
public:
	virtual void AlgorithmInterface()
	{
		cout<< "算法C的实现" <<endl;
	}
};

/*上下文*/
enum AI {CSA, CSB, CSC}; /*标签*/
class Context
{
public:
	Context(enum AI ai)       /*初始化时传入选项*/
	{
		switch (ai)
		{
		case CSA:
			this->_strategy = new ConcreteStrategyA();
			break;
		case CSB:
			this->_strategy = new ConcreteStrategyB();
			break;
		case CSC:
			this->_strategy = new ConcreteStrategyC();
			break;
		default:
			this->_strategy = NULL;
			break;
		}
	}
	~Context()
	{
		if (!_strategy)
		{
			delete _strategy;
			_strategy = NULL;
		}
	}
public:
	void ContexInterface()			/*根据具体的对象调用其算法策略*/
	{
		this->_strategy->AlgorithmInterface();
	}
private:
	Strategy *_strategy;
};



int main(void)
{
	/*
	Context context(CSA);
	context.ContexInterface();

	Context context2(CSB);
	context2.ContexInterface();

	Context context3(CSC);
	context3.ContexInterface();
	*/

	Context *context = NULL;
	context = new Context(CSA);
	context->ContexInterface();

	context = new Context(CSB);
	context->ContexInterface();

	context = new Context(CSC);
	context->ContexInterface();


	system("PAUSE");
	return 0;
}
