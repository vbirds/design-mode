#include <iostream>
#include <string>

using namespace std;

class Image
{
public:
	Image(string name): m_image(name) {}
public:
	virtual ~Image() {}
	virtual void Show() {}

protected:
	string m_image;
};

class BigImage: public Image
{
public:
	BigImage(string name):Image(name) {}
	~BigImage() {}

	virtual void Show()
	{
		cout<< "Show big Image: " << m_image <<endl;
	}
};

class BogImageProxy: public Image
{
private:
	BigImage *m_bigImage;
public:
	BogImageProxy(string name):Image(name),m_bigImage(NULL) {}
	~BogImageProxy()
	{
		if (m_bigImage)
		{
			delete m_bigImage;
		}
	}

	virtual void Show()
	{
		if (m_bigImage == NULL)
		{
			m_bigImage = new BigImage(m_image);
		}

		m_bigImage->Show();
	}
};


int main(void)
{
	Image *image = new BogImageProxy("proxy.jpg");
	image->Show();

	delete image;
	system("PAUSE");
	return 0;
}