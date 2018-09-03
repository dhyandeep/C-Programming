#include <iostream>
using namespace std;
struct Node
{
	int m_data;
	Node* m_next;
	Node(int data)
	{
		m_next = nullptr;
		m_data = data;
	}
	Node()
	{
		m_next = nullptr;
		m_data = 0;
	}

};
void InsertAtEnd(Node** head, int data)
{
	if(head)
	{
		if(*head)
		{
			Node* pNode = *head;
			while(pNode->m_next)
			{
				pNode = pNode->m_next;
			}
			pNode->m_next = new Node(data);
		}
	}
	else
	{
		Node* tmp = new Node(data);
		head = &tmp;
	}
}
void InsertAtBegining(Node** head, int data)
{
	if(head)
	{
		if(*head)
		{
			Node* pNode = new Node(data);
			pNode->m_next = *head;
			*head = pNode;
		}
	}
	else
	{
		Node* tmp = new Node(data);
		head = &tmp;
	}
}
void InsertAfter(Node** head,int after, int data)
{
	if(head)
	{
		Node* tmp = *head;
		if(tmp)
		{
			while((tmp)&&(tmp->m_data != after))
			{
				tmp = tmp->m_next;
			}
			if(tmp->m_data == after)
			{
				Node* tmpNext = tmp->m_next;
				tmp->m_next = new Node(data);
				tmp->m_next->m_next = tmpNext;
			}
		}
	}
}
void DeleteFromEnd(Node** head)
{
	if(head)
	{
		if(*head)
		{
			Node* pNode = *head;
			Node* pPrevPtr = *head;
			int i = 0;
			while(pNode->m_next)
			{
				if(i != 0)
				{
					pPrevPtr = pPrevPtr->m_next;
				}
				else
				{
					i = 1;
				}
				pNode = pNode->m_next;
			}
			delete (pNode);
			pPrevPtr->m_next = nullptr;
		}
		
	}

}
void PrintList(Node** head)
{
	if(head)
	{
		Node *tmp = *head;
		while(tmp)
		{
			cout << (tmp)->m_data <<"\t";
			tmp = tmp->m_next;
		}
	}
	cout<<endl;
}
int main()
{
	Node* phead = new Node(3);
	Node** head = &phead;
	InsertAtEnd(head, 10);
	InsertAtEnd(head, 20);
	InsertAtEnd(head, 30);
	InsertAtEnd(head, 40);
	PrintList(head);
	InsertAfter(head,30,8);
	PrintList(head);
	DeleteFromEnd(head);
	InsertAtBegining(head,1);
	PrintList(head);
	return 0;
}