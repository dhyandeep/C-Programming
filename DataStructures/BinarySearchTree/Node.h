#pragma once
class Node
{
	int m_NodeValue;
public:
	Node *m_LeftNode,*m_RightNode;
	Node(void);
	Node(int);
	void SetValue(int value);
	int GetValue();
	~Node(void);
};

