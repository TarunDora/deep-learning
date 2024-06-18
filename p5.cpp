//UNIT 4
/*
Static binding happens at compile-time, 
i.e., the function call and the function definition are 
linked during the compile time itself.
So, it is also called early binding.
This is because all the information needed to associate the
 function call to its definition is available at the compile time.
 */
 
 /*
 Upcasting
It is the process to create the derived class's pointer or
 reference from the base class's pointer or reference
 */
 
 
 
//Example 1
/*
#include<iostream>
using namespace std;

class Base
{
	int m_a;
	public:
	Base(int a=0):m_a(a){}
	void display(){cout<<m_a<<" ";}
};

class Derived:public Base
{
	int m_b;
	public:
	Derived(int a=0,int b=0):Base(a),m_b(b){}
	void display(){Base::display(); cout<<m_b<<endl;}
};
int main()
{
	Base bobj(10);
	Derived dobj(100,200);
	
	bobj.display();
	cout<<endl;
	dobj.display();
	
	cout<<"\nPointer for base object"<<endl;
	Base *bptr=&bobj;
	bptr->display();
	cout<<endl;
	bptr=&dobj;			//Upcasting
	bptr->display();	//static binding, fn call based on static type
	
	cout<<"\nReference for base object"<<endl;
	Base &bref1=bobj;
	bref1.display();
	cout<<endl;
	Base &bref2=dobj;	//Upcasting
	bref2.display();	
	//static binding, fn call based on static type
	
	cout<<"\nPointer for derived object"<<endl;
	Derived *dptr=&dobj;
	dptr->display();
	
	cout<<"\nReference for derived object"<<endl;
	Derived &dref1=dobj;
	dref1.display();
	cout<<endl;
	
	cout<<"\nPointer"<<endl;
	//dptr=&bobj;				//Downcasting, Implicitly error
	//dptr=(Derived*)&bobj;	//Downcasting, Explicitly okay, but Risky
	//dptr->display();	//undefined
}

//Dynamic Binding

#include<iostream>
using namespace std;

class Base
{
	int m_a;
	public:
	Base(int a=0):m_a(a){}
	virtual void display(){cout<<m_a<<" ";}
};

class Derived:public Base
{
	int m_b;
	public:
	Derived(int a=0,int b=0):Base(a),m_b(b){}
	void display(){Base::display(); cout<<m_b<<endl;}
};

int main()
{
	Base bobj(10);
	Derived dobj(100,200);
	
	bobj.display();
	cout<<endl;
	dobj.display();
	
	cout<<"\nPointer"<<endl;
	Base *bptr=&bobj;
	bptr->display();
	cout<<endl;
	bptr=&dobj;			//Upcasting
	bptr->display();	//static binding, fn call based on static type
	
	cout<<"\nReference"<<endl;
	Base &bref1=bobj;
	bref1.display();
	cout<<endl;
	Base &bref2=dobj;	//Upcasting
	bref2.display();	//static binding, fn call based on static type
	
	cout<<"\nPointer"<<endl;
	Derived *dptr=&dobj;
	dptr->display();
	cout<<"\nReference"<<endl;
	Derived &dref1=dobj;
	dref1.display();
	cout<<endl;
}



#include <iostream>
using namespace std;
class Parent {
public:
virtual	void fun()
	{
		cout << "Base Function" << endl;}
};
class Child : public Parent {
public:
	void fun()
	{
		cout << "Derived Function" << endl;	}
};
int main()
{
	Child Child_obj;
	Parent Parent_obj;
	Parent_obj.fun();
	Child_obj.fun();
	return 0;
}



//override identifier

#include<iostream>
using namespace std;
class Base
{
	public:
	virtual void display();	
};
 void Base::display()
{
	cout<<"Base display"<<endl;
}
class Derived:public Base
{
	public:
	void display()override{ cout<<"Derived display"<<endl;}
//void display(int x)override{Base::display(); cout<<"Derived display"<<endl;}
};
int main()
{
	Derived dobj;
	Base *bptr=&dobj;
	bptr->display();
}



//pure virtual function

Pure Virtual Function

SYNTAX: virtual returntype functionname(parameters...) = 0;

NOTES:
1). If some class can have only signature of function but not
 the body then we use pure virtual functions.
 
2). Sometimes in Base class we know the function name but not 
the definition of the function, so we want Derived classes to 
provide the definition of the function.

3). We can actually give body of pure virtual function.

4). If you have pure virtual function in your class, 
it means that class is an Abstract class and you can't create 
an object of that class. 
(But pointers and Reference can be created)


#include<iostream>
using namespace std;

class Shape
{
	public:
	virtual double area()=0;
};

class Rectangle:public Shape
{
	double length;
	double breadth;
	public:
	Rectangle(double l,double b){length=l; breadth=b;}
	double area()
	{
		return length*breadth;
	}
};

class Circle:public Shape
{
	double radius;
	public:
	Circle(double r){radius=r;}
	double area()
	{
		return 3.142*radius*radius;
	}
};

int main()
{
//	Shape s;	//Abstract class, coz it has a pure virtual fn
	Rectangle r(2,3);
	cout<<"Area of rectangle="<<r.area()<<endl;
	
	Circle c(1);
	cout<<"Area of circle="<<c.area()<<endl;
}


//virtual destructor

destructor is called by its type
so we need virtual destructor



#include<iostream>
using namespace std;
class Base 
{ 
  public: 
    Base() { } 
   virtual  ~Base() {cout<<"Base dtor"<<endl;} 
}; 
class Derived : public Base 
{ 
  public: 
    Derived() { mString = new char[30]; } 
    ~Derived() { cout<<"Derived dtor"<<endl;delete [] mString; } 
  private: 
    char* mString; 
}; 
int main() 
{ 
  Base* ptr = new Derived(); 
  delete ptr;    
  // ~Derived is called because the destructor is virtual! 
  return 0; 
}




//multiple inheritance

#include<iostream>
using namespace std;

class Base1
{
	protected:
		int m_x;
		int m_data;
	public:
		Base1(int x,int data):m_x(x),m_data(data){}
		void show(){cout<<m_x<<" "<<m_data<<endl;}
};
class Base2
{
	protected:
		int m_y;
		int m_data;
	public:
		Base2(int y,int data):m_y(y),m_data(data){}
		void show(){cout<<m_y<<" "<<m_data<<endl;}
};
class Derived:public Base1,public Base2
{
	protected:
		int m_z;
	public:
		Derived(int x,int data1,int y,int data2,int z):Base1(x,data1),Base2(y,data2),m_z(z){}
		void show()
		{
			Base1::show();
			Base2::show();
			cout<<m_z<<endl;
		}
		void chk()
		{
			cout<<Base1::m_data<<" "<<Base2::m_data<<endl;
		}
};
//Resolve ambiguity 
	//using scope resolution operator
	//or by providing a new override for the method
	
//For data members: use scope resolution operator

int main()
{
	Derived d(1,2,3,4,5);
	d.show();
	d.Base1::show();
	d.Base2::show();
	cout<<endl;
	d.chk();
}


//inheritance and constructor

#include<iostream>
using namespace std;
class A
{
	protected:int m_a;
	public: A(int a):m_a(a){cout<<"A ctor"<<endl;}
	~A(){cout<<"A dtor"<<endl;}
	
};
class B:public A
{
	protected:int m_b;
	public: B(int a,int b):A(a),m_b(b){cout<<"B ctor"<<endl;}	
	~B(){cout<<"B dtor"<<endl;}
};
class C:public A
{
	protected:int m_c;
	public: C(int a,int c):A(a),m_c(c){cout<<"C ctor"<<endl;}	
	~C(){cout<<"C dtor"<<endl;}
};
class D:public B, public C
{
	protected:int m_d;
	public: D(int a,int b,int c,int d):B(a,b),C(a,c),m_d(d){cout<<"D ctor"<<endl;}
	~D(){cout<<"D dtor"<<endl;}	
	void display(){cout<<B::m_a<<" "<<m_b<<" "<<m_c<<" "<<m_d<<endl;}
};

int main()
{
	D d(1,2,3,4);
	d.display();	
}

*/












































































































































































