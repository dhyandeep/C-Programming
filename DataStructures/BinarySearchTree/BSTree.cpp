#include "BSTree.h"
#include <iostream>
using namespace std;

Node* FindSuccessor(Node* delNode);

BSTree::BSTree(void):m_Root(nullptr)
{
}
void BSTree::InsertValue(int val)
{
	Node* tmpNode = new Node(val);
	Node* IterNode = m_Root;
	if(m_Root == nullptr)
	{
		m_Root = tmpNode;
		return;
	}
	while(IterNode != nullptr)
	{
		if(val < IterNode->GetValue())
		{
			if(IterNode->m_LeftNode == nullptr)
			{
				IterNode->m_LeftNode = tmpNode;
				cout<<__FUNCTION__<<" Inserted value in BST"<<val<<endl;
				return;
			}
			IterNode = IterNode->m_LeftNode;
		}
		else if(val >= IterNode->GetValue())
		{
			if(IterNode->m_RightNode == nullptr)
			{
				IterNode->m_RightNode = tmpNode;
				cout<<__FUNCTION__<<" Inserted value in BST"<<val<<endl;
				return;
			}
			IterNode = IterNode->m_RightNode;
		}
	}
}

Node* BSTree::DeleteValue(Node* rootArg, int val)
{
	if(rootArg == nullptr)
	{
		return rootArg;
	}
	else if(rootArg->GetValue()<val)
	{
		rootArg->m_RightNode = DeleteValue(rootArg->m_RightNode,val);
	}
	else if(rootArg->GetValue()>val)
	{
		rootArg->m_LeftNode = DeleteValue(rootArg->m_LeftNode,val);
	}
	else
	{
		if((rootArg->m_LeftNode==nullptr) &&(rootArg->m_RightNode==nullptr))
		{
			delete (rootArg);
			rootArg = nullptr;
		}
		else if(rootArg->m_LeftNode == nullptr)
		{
			Node* tempNode = rootArg;
			rootArg = rootArg->m_RightNode;
			delete tempNode;
			tempNode = nullptr;
		}
		else if(rootArg->m_RightNode == nullptr)
		{
			Node* tempNode = rootArg;
			rootArg = rootArg->m_LeftNode;
			delete tempNode;
			tempNode = nullptr;
		}
		else
		{
			Node *successorNode = FindSuccessor(rootArg->m_RightNode);
			rootArg->SetValue(successorNode->GetValue());
			rootArg->m_RightNode = DeleteValue(rootArg->m_RightNode,successorNode->GetValue());
			
		}
	}
	return rootArg;
}
Node* FindSuccessor(Node* delNode)
{
	while(delNode->m_LeftNode !=nullptr)
	{
		delNode = delNode->m_LeftNode;
	}
	return delNode;
}
void BSTree::PrintInorder(Node *thisNode)
{
	if(thisNode!= nullptr)
	{
		PrintInorder(thisNode->m_LeftNode);
	}
	if(thisNode!= nullptr)
	{
		cout<<__FUNCTION__<<" Node Val: "<<thisNode->GetValue()<<endl;
		PrintInorder(thisNode->m_RightNode);
	}
}
void BSTree::PrintPreorder(Node *thisNode)
{
	
	if(thisNode!= nullptr)
	{
		cout<<__FUNCTION__<<" Node Val: "<<thisNode->GetValue()<<endl;
		PrintPreorder(thisNode->m_LeftNode);
		PrintPreorder(thisNode->m_RightNode);
	}
}
void BSTree::PrintPostorder(Node *thisNode)
{
	if(thisNode!= nullptr)
	{
		PrintPostorder(thisNode->m_LeftNode);
		PrintPostorder(thisNode->m_RightNode);
		cout<<__FUNCTION__<<" Node Val: "<<thisNode->GetValue()<<endl;
	}
}
	
Node* BSTree::GetRootNode()
{
	 return m_Root;
}

void BSTree::SetRootNode(Node* pNode)
{
	m_Root = pNode;
}
BSTree::~BSTree(void)
{
}
