#include <iostream>
using namespace std;
template <class T>
class SharedPtr
{
	T* ptr;
	int count;
	int IncCount();
	int DecCount();

public:

	SharedPtr();
	SharedPtr(T* _ptr);
	SharedPtr& operator = (SharedPtr& uptr);
	SharedPtr(SharedPtr& uptr);
	T operator * (void) const;
	SharedPtr(SharedPtr&& uptr);
	~SharedPtr();
};

template <class T>
int SharedPtr<T>::IncCount()
{
	return ++count;
}

template <class T>
int SharedPtr<T>::DecCount()
{
	return --count;
}

template <class T>
SharedPtr<T>::SharedPtr():ptr(nullptr),count(0)
{
	cout<<"SharedPtr::SharedPtr() IncCount = " << IncCount()<<endl;
}

template <class T>
SharedPtr<T>::SharedPtr(T* _ptr):ptr(_ptr),count(0)
{
	cout<<"SharedPtr::SharedPtr(T* _ptr) IncCount = " << IncCount()<<endl;
}
template <class T>
SharedPtr<T>::SharedPtr(SharedPtr& sptr):ptr(sptr.ptr),count(0)
{
	cout<<"SharedPtr::SharedPtr(SharedPtr sptr) IncCount = " << IncCount()<<endl;
	sptr.IncCount();
}

template <class T>
SharedPtr<T>& SharedPtr<T>::operator = (SharedPtr& sptr)
{
	cout<<"SharedPtr::SharedPtr(SharedPtr sptr) IncCount = " << IncCount()<<endl;
	ptr = sptr.ptr;
	count = 0;
	sptr.IncCount();
	return *this;
}

template <class T>
T SharedPtr<T>::operator * (void) const
{
	cout<<"SharedPtr::operator * (void) "<<endl;
	return *ptr;
}

template <class T>
SharedPtr<T>::SharedPtr(SharedPtr&& uptr):ptr(uptr.ptr),count(0)
{
	cout<<"Moving the pointer "<<endl;
	uptr.ptr = nullptr;
	uptr.DecCount();
	IncrementCount();
}
template <class T>
SharedPtr<T>::~SharedPtr()
{
	cout<<"destructing the pointer "<<endl;
	if(DecCount()==0)
	{
		cout<<"Count is zero, deleting the pointer"<<endl;

		if(ptr)
			delete ptr;
	}
}






