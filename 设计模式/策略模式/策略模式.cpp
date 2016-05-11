#include <iostream>
#include <exception>  
#include <stdlib.h>

using namespace std;

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
class Context
{
public:
	Context(Strategy *strategy)       /*初始化时传入具体的接口*/
	{
		this->_strategy = strategy;
	}
public:
	void ContexInterface()			/*根据具体的对象调用其算法策略*/
	{
		this->_strategy->AlgorithmInterface();
	}
private:
	Strategy *_strategy;
};


/*
int main(void)
{
	Context context(new ConcreteStrategyA());
	context.ContexInterface();

	Context context2(new ConcreteStrategyB());
	context2.ContexInterface();

	Context context3(new ConcreteStrategyC());
	context3.ContexInterface();

	system("PAUSE");
	return 0;
}
*/