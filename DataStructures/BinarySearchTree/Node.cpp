#include "Node.h"
#include <iostream>
using namespace std;


Node::Node(void):m_LeftNode(nullptr),m_RightNode(nullptr),m_NodeValue(0)
{
	cout<<__FUNCTION__<<"Default ctor called"<<endl;
}

Node::Node(int value):m_LeftNode(nullptr),m_RightNode(nullptr),m_NodeValue(value)
{
	cout<<__FUNCTION__<<"Parameterized ctor called"<<endl;
}



void Node::SetValue(int value)
{
	m_NodeValue = value;
	cout<<__FUNCTION__<<"Node Value set:"<<m_NodeValue<<endl;
}
int Node::GetValue()
{

	cout<<__FUNCTION__<<"Node Value got:"<<m_NodeValue<<endl;
	return m_NodeValue;
}
Node::~Node(void)
{
	cout<<__FUNCTION__<<"Node dtor called"<<endl;
}