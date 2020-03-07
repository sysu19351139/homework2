
#include<iostream>
using namespace std;

class identity {
public:
	identity(char*,char*);
	identity(identity &);
	identity();
	~identity();
	void get();
	void show();
private:
	char number_[19];
	char name_[4];
};

identity::identity(char* newnumber, char* newname)//构造函数的实现
{
	for(int i=0;i<19;i++)
	    number_[i] = newnumber[i];
	for (int i = 0; i < 4; i++)
		name_[i] = newname[i];
	cout << "constructor"<<endl;
}

identity::identity(identity& d)//复制构造函数的实现
{
	for (int i = 0; i < 19; i++)
		number_[i] = d.number_[i];
	for (int i = 0; i < 4; i++)
		name_[i] = d.name_[i];
	cout << "calling the copy constructor" << endl;
}

identity::identity()//无参数构造函数的实现
{
	number_[0] = '\0'; name_[0] = '\0';
	cout << "constructor"<<endl;
}

identity::~identity() {//析构函数的实现
	cout << "distructor"<<endl;
}

void identity::get()
{
	cout << "请输入身份证号（18位数）："<<endl;
	for (int i = 0; i < 19; i++)
	{
		cin >> number_[i];
		if (number_[i] == '\n') break;
	}
	cout << "请输入姓名：" << endl;
	for (int i = 0; i < 4; i++)
	{
		cin >> name_[i];
		if (name_[i] == '\n') break;
	}
}

void identity::show() 
{
	cout << "身份证号：";
	for (int i = 0; i < 19; i++)
		cout << number_[i];
	cout << "姓名：" ;
	for (int i = 0; i < 4; i++)
		cout<< name_[i];
}

class student:public identity
{
public:
	student(identity,string);
	student(student&);
	student();
	~student();
	void get1();
	void show1();

private:
	identity id_;
	string school_[5];
};

student::student(identity newid_,string newschool_)//构造函数的实现
{
	identity a(new char[19]{ "362331200102260032" }, new char[4]{ "why" });
	newid_ = a;
	for (int i = 0; i < 5; i++)
	school_[i]=newschool_[i];
	cout << "constructor"<<endl;
}

student::student(student& d)//复制构造函数的实现
{
	id_ = d.id_;
	for (int i = 0; i < 5; i++)
	school_[i] = d.school_[i];
	cout << "calling the copy constructor" << endl;
}

student::student()//无参数构造函数的实现
{
	identity a(new char[19] { "362331200102260032" }, new char[4] { "why" });
	school_ [0]= '\0';
	cout << "constructor"<<endl;
}

student::~student() //析构函数的实现
{
	cout << "distructor"<<endl;
}

void student::get1()
{
	identity::get();
	cout << "请输入学校：" << endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> school_[i];
	}
}

void student::show1()
{
	identity::show();
	cout << "学校："<<endl;
	for (int i = 0; i < 5; i++)
		cout << school_[i];
}
int main()
{
	identity a1(new char[19] { "362331200102260032" }, new char[4] { "why" }),b,c;
	b=a1;
	a1.show();
	b.show();
	c.get();
	c.show();
	student d(a1, "zsdx"),e,f;
	e=d;
	d.show1();
	e.show1();
	f.get1();
	f.show1();
	return 0;
}

