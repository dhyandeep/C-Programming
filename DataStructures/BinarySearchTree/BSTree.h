#pragma once
#include "Node.h"
class BSTree
{
	Node* m_Root;
public:
	BSTree(void);
	void InsertValue(int val);
	Node* DeleteValue(Node* rootArg, int val);
	void PrintInorder(Node* thisNode);
	void PrintPreorder(Node* thisNode);
	void PrintPostorder(Node* thisNode);
	Node* GetRootNode();
	void SetRootNode(Node* pNode);
	~BSTree(void);
};

