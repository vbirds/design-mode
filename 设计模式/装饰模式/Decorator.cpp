#include <iostream>
#include <string>

using namespace std;

/************************************************************************/
/* 装饰模式。                                                                     */
/************************************************************************/

/*人类*/
class Person
{
public:
	Person(){}
	Person(string name)
	{
		this->_name = name;
	}
private:
	string _name;
public:
	virtual void Show()			/*显示装扮*/
	{
		cout<< " 装扮的" << _name <<endl;
	}
};

/*服饰类*/
class Finery: public Person
{
protected:
	Person *_component;
public:
	void Decorate(Person *component)
	{
		this->_component = component;
	}
	virtual void Show()
	{
		if (_component != NULL)
		{
			_component->Show();
		}
	}
};

/*具体服饰类*/
class TShirts: public Finery
{
public:
	virtual void Show()
	{
		cout<< " 穿大T恤 ";
		Finery::Show();
	}
};

class BigTrouser: public Finery
{
	virtual void Show()
	{
		cout<< " 垮裤 ";
		Finery::Show();
	}
};

class Shoes: public Finery
{
	virtual void Show()
	{
		cout<< " 破球鞋 ";
		Finery::Show();
	}
};

class Shuit: public Finery
{
	virtual void Show()
	{
		cout<< " 西装 ";
		Finery::Show();
	}
};

class Tie: public Finery
{
	virtual void Show()
	{
		cout<< " 领带 ";
		Finery::Show();
	}
};



int main(void)
{
	Person *kong = new Person("kong");

	cout<< "\n第一种装扮: " << endl;

	Tie		   *tie		  = new Tie();
	BigTrouser *bigtrouser = new BigTrouser();
	TShirts	   *tshirt     = new TShirts();

	tie->Decorate(kong);
	bigtrouser->Decorate(tie);
	tshirt->Decorate(bigtrouser);

	tshirt->Show();

	delete tie;
	delete bigtrouser;
	delete tshirt;
	delete kong;

	system("PAUSE");

	return 0;
}