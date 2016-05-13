#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

class Product
{
private:
	list<string> *parts;
public:
	Product()
	{
		this->parts = new list<string>();
	}
	~Product()
	{
		this->parts->clear();
		if (this->parts != NULL)
		{
			delete this->parts;
		}
	}
public:
	void Add(string part)
	{
		this->parts->push_back(part);
	}
	void Show()
	{
		cout << "产品\n" << endl;
		for_each(this->parts->begin(), this->parts->end(), Product::print);
	}
public:
	static void print(string str)
	{
		cout << str << endl;
	}
};

class Builder
{
public:
	virtual void BuildPartA() = 0;
	virtual void BulidPartB() = 0;
	virtual void BulidPartC() = 0;
	virtual Product* GetResult() = 0;
};

class ConcreteBuilder1 : public Builder
{
private:
	Product *product;
public:
	ConcreteBuilder1()
	{
		this->product = new Product();
	}
	~ConcreteBuilder1()
	{
		if (this->product != NULL)
		{
			delete this->product;
		}
	}
public:
	void BuildPartA()
	{
		product->Add("部件A");
	}
	void BulidPartB()
	{
		product->Add("部件B");
	}
	void BulidPartC()
	{
		product->Add("部件C");
	}

	Product* GetResult()
	{
		return this->product;
	}
};

class ConcreteBuilder2 : public Builder
{
private:
	Product *product;
public:
	ConcreteBuilder2()
	{
		this->product = new Product();
	}
	~ConcreteBuilder2()
	{
		if (this->product != NULL)
		{
			delete this->product;
		}
	}
public:
	void BuildPartA()
	{
		product->Add("部件X");
	}
	void BulidPartB()
	{
		product->Add("部件Y");
	}
	void BulidPartC()
	{
		product->Add("部件Z");
	}

	Product* GetResult()
	{
		return this->product;
	}
};

class Director
{
public:
	void Constrct(Builder& builder)
	{
		builder.BuildPartA();
		builder.BulidPartB();
		builder.BulidPartC();
	}
};


int main()
{
	Director *director = new Director();
	Builder *b1 = new ConcreteBuilder1;
	Builder *b2 = new ConcreteBuilder2;

	director->Constrct(*b1);
	Product *p1 = b1->GetResult();
	p1->Show();

	director->Constrct(*b2);
	Product *p2 = b2->GetResult();
	p2->Show();

	system("PAUSE");
	return 0;
}