#pragma once
#include "Node.h"
//const size_t StackMaxSize = 10;
class Stack
{
	int m_size,m_top;
	Node* m_TopNode;
	Stack(Stack&);
public:
	Stack(void);
	Stack(int);
	~Stack(void);
	void Push(int value);
	int Pop();
};

