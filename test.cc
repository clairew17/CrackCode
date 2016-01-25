#include"header.h"

#include <stdio.h>

class Base1
{
  public:

  virtual int virt1() { cout<<"b1 virt1\t"<< this << endl;return 100; }
  //virtual int foo() { return 123; }
  //int data1 = 100;

};

class Derived : public Base1
{
  public:

  virtual int virt1() { cout<<"d virt2\t"<< this << endl;return 200; }

  //int derivedData = 150;
};

int Global1( Base1 * b1 )
{
	cout << "base1:\t"<<b1<<endl;
  return b1->virt1();
}



class Base2
{
  public:

  virtual int virt2(){ cout<< "b2 virt2\t" << this << endl;return 200; }

  //int data2 = 200;
};

class MultipleDerived : public Base1, public Base2
{
  public:

  virtual int virt1() {cout<<"MD virt1\t"<< this << endl;return 150; }
  virtual int virt2() {cout<<"MD virt2\t"<< this << endl;return 250; }
  virtual int foo() {cout<<"MD foo\t"<< this << endl;return 350; }

  //int derivedData = 150;
};

int Global2( Base2 * b2 )
{
	cout << "base2:\t"<<b2<<endl;
  	return b2->virt2();
}

int main()
{
	cout << "\n---------------------- Part 1 ----------------------\n";
	Base1 * d = new Derived;
  Base1 * b = new Base1;
  cout <<"SIZEOF Base1\t"<< sizeof(*b)<<endl;

	printf( "%d %d\n", d->virt1(), 
		//dereference: look up virt1() in Derived:VTable
		//fixup: overriden by derived class, B1::virt1() is not in vtable, call Derived::virt1()
		Global1(d ));
		//cast from Derived->base1; 
	d = new Base1;
	printf( "%d %d\n", d->virt1(), Global1( d ));
	cout << sizeof(*d)<<endl;
	cout << "\n---------------------- Part 2 ----------------------\n";

  	MultipleDerived * md = new MultipleDerived;
  	Base2 *md2 = static_cast<Base2*>(md);

  	printf( "%d %d %d %d\t%d\n\n", md->virt1(), Global1( md ), md->virt2(), Global2( md ), Global2( md2 ));
    
  	cout << sizeof(*md)<<endl;

}
