// ConsoleApplication32.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include "MyShared_ptr.h"

void foo(MyShared_ptr<int>& v);
void bar(MyShared_ptr<int> v);
int main()
{
	int * a =0;
	MyShared_ptr<int> b(a);
	std::cout <<"ptr № "<< b.get() << std::endl;
	MyShared_ptr<int> c(b);
	std::cout <<"after copy constructor"<< b.get() << std::endl;
	MyShared_ptr<int> d=b;
	std::cout << "after copy operator" << b.get() << std::endl;
	foo(b);
	bar(b);
	std::cout <<"after bar() "<< b.get() << std::endl;

    return 0;
}

void foo(MyShared_ptr<int>&v)
{
	std::cout << "after move " << v.get() << std::endl;
}

void bar(MyShared_ptr<int>v)
{
	std::cout << "after copy " << v.get() << std::endl;
}