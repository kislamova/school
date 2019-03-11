#pragma once

#include <iostream>




template <class T>
class ControlBlok;

template <class T>
class MyShared_ptr
{
private:
	T* ptr;
	ControlBlok<T>*  blok;
public:
	 MyShared_ptr();
	 explicit MyShared_ptr(T* _ptr);
	 MyShared_ptr(const MyShared_ptr & other);
	 MyShared_ptr(MyShared_ptr && other);
	 MyShared_ptr & operator = (const MyShared_ptr<T> & other);
	 MyShared_ptr & operator = ( MyShared_ptr<T> && other);
	 int get() const;
	 ~MyShared_ptr();
};

template <class T>
class ControlBlok
{
private:
	int counter;
	T * object;
	void inc() { counter++; };
	void dec()
	{
		counter--;
		if (counter == 0)
			delete object;
	};
	ControlBlok() :object(nullptr), counter(0) {};
	ControlBlok(T*ptr) : object(ptr), counter(1) {};

	friend class MyShared_ptr<T>;

}
;
template <class T>
int MyShared_ptr<T>:: get() const
{
	return blok->counter;
}

 template <class T>
 MyShared_ptr<T>::MyShared_ptr():ptr(nullptr),blok(new ControlBlok ()){};

 template <class T>
 MyShared_ptr<T>::MyShared_ptr(T*_ptr)
 {
	 ptr=_ptr;
	 blok = new ControlBlok<T>(_ptr);
 }

 template <class T>
 MyShared_ptr<T>::MyShared_ptr(const MyShared_ptr & other)
 {
	 ptr=other.ptr;
	 blok=other.blok;
	 blok->inc();
 }

 template <class T>
 MyShared_ptr<T>::MyShared_ptr(MyShared_ptr && other)
 {
	 ptr=other.ptr;
	 blok=other.blok;
	 other.ptr=nullptr;
	 other.blok = nullptr;
	 
 }
 
 template <class T>
 MyShared_ptr<T> & MyShared_ptr<T>:: operator = (const MyShared_ptr<T> & other)
 {
	 ptr(other.ptr);
	 blok->dec();
	 if (get() == 0)
		 delete blok;
	 blok(other.blok);
	 blok->inc();
	 return *this;
 }

 template <class T>
 MyShared_ptr<T>& MyShared_ptr<T>::  operator = (MyShared_ptr<T> && other)
 {
	 ptr(other.ptr);
	 blok->dec();
	 if (get() == 0)
		 delete blok;
	 blok(other.blok);
	 other.ptr = nullptr;
	 other.blok = nullptr;
	 return *this;
  }
 template <class T>
 MyShared_ptr<T>:: ~MyShared_ptr()
 {
	 blok->dec();
	 if (get() == 0)
	     delete blok;
	 
 }
