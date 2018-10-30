#include <iostream>
using namespace std;
template <class T>
class UniquePtr
{
	T* ptr;
	UniquePtr& operator = (UniquePtr& uptr);
	UniquePtr(UniquePtr& uptr);
public:
	UniquePtr();
	UniquePtr(T* _ptr);
	T operator * (void) const;
	UniquePtr(UniquePtr&& uptr);
	~UniquePtr();
};
template <class T>
UniquePtr<T>::UniquePtr():ptr(nullptr)
{
	cout<<"UniquePtr::UniquePtr()"<<endl;
}

template <class T>
UniquePtr<T>::UniquePtr(T* _ptr):ptr(_ptr)
{
	cout<<"UniquePtr::UniquePtr(T* _ptr)"<<endl;
}

template <class T>
T UniquePtr<T>::operator * (void) const
{
	cout<<"UniquePtr::operator * (void) "<<endl;
	return *ptr;
}

template <class T>
UniquePtr<T>::UniquePtr(UniquePtr&& uptr):ptr(uptr.ptr)
{
	cout<<"Moving the pointer "<<endl;
	uptr.ptr = nullptr;
}
template <class T>
UniquePtr<T>::~UniquePtr()
{
	cout<<"destructing the pointer "<<endl;
	if(ptr)
		delete ptr;
}






