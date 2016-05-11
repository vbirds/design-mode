#include <iostream>
#include <string>
#include <exception>  

using namespace std;

class Prototype
{
protected:
	string		m_name;
	string		m_sex;
	int			m_age;
	string		m_timeArea;
	string		m_company;
public:
	Prototype(){}
	virtual ~Prototype(){};
public:
	virtual void SetPersonalInfo(string sex, int age) {}
	virtual void SetWorkExperience(string timeArea, string company){}
	virtual void ShowInformation(){}
public:
	virtual Prototype* Clone(){ return NULL;};
};


class Resume: public Prototype
{
public:
	Resume(string name)
	{
		this->m_name = name;
	}
	~Resume(){}
public:
	void SetPersonalInfo(string sex, int age)
	{
		this->m_sex = sex;
		this->m_age = age;
	}
	void SetWorkExperience(string timeArea, string company)
	{
		this->m_timeArea = timeArea;
		this->m_company = company;
	}

	void ShowInformation()
	{
		cout << this->m_name <<" "<< this->m_sex <<" " << this->m_age << endl;
		cout << "工作经历" << this->m_timeArea <<" "<< this->m_company << endl;
	}
public:
	Resume* Clone()
	{
		return new Resume(*this);
	}
};



int main(void)
{
	Prototype *r1;
	r1 = new Resume("kong");
	r1->SetPersonalInfo("男", 22);
	r1->SetWorkExperience("1995", "阿里巴巴");

	r1->ShowInformation();
	Prototype *r2;
	r2 = r1->Clone();
	r2->SetWorkExperience("1996", "斗鱼");
	r2->ShowInformation();

	system("PAUSE");
	return 0;
}