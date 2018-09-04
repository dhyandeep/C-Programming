#include "Stack.h"
#include <iostream>
using namespace std;
Stack::Stack(void):m_TopNode(nullptr),m_size(0),m_top(0)
{
	cout<<__FUNCTION__<<" Default ctor called"<<endl;
}

Stack::Stack(int sizeArg):m_TopNode(nullptr),m_size(sizeArg),m_top(0)
{
	cout<<__FUNCTION__<<" Parameterized ctor called"<<endl;
}

void Stack::Push(int value)
{
	if(( m_top+1) < m_size)
	{
		m_top++;
		Node* tmpNode = new Node(value);
		tmpNode->PreviousNode = m_TopNode;
		m_TopNode = tmpNode;
		cout<<__FUNCTION__<<" Pushed value"<<m_TopNode->GetValue()<<endl;
	}
	else
	{
		cout<<__FUNCTION__<<" Unable to push!! Stack size out of bounds"<<m_TopNode->GetValue()<<endl;
	}
}

int Stack::Pop()
{
	if((m_top-1)>0)
	{
		Node* tmpNode = m_TopNode;
		m_top --;
		int RetVal = tmpNode->GetValue();
		m_TopNode = m_TopNode->PreviousNode;
		cout<<__FUNCTION__<<" Popped value"<<RetVal<<endl;
		delete tmpNode;
		return RetVal;
	}
	else
	{
		cout<<__FUNCTION__<<" Unable to pop!! Stack empty"<<endl;
		return -1;
	}
	
}
Stack::~Stack(void)
{
}
