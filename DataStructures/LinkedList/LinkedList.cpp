#include <iostream>
using namespace std;
struct Node
{
	int val;
	Node * next;
	Node(int _val)
	{
		val = _val;
	}
};
Node* InsertAtEnd(Node* head, int newVal)
{
	if(head)
	{
		head->next = InsertAtEnd(head->next, newVal);
		return head;
	}
	else
	{
		return new Node(newVal);
	}
}
Node* InsertAtStart(Node* head, int newVal)
{
	if(head)
	{
		Node* tmpNode = new Node(newVal);
		tmpNode->next = head;
		return tmpNode;
	}
	else
	{
		return new Node(newVal);
	}
}
Node* InsertAfter(Node* head,int after, int newVal)
{
	if(head)
	{
		if(head->val==after)
		{
			Node* tmp = new Node(newVal);
			tmp->next = head->next;
			head->next = tmp;
			return head;
		}
		else
		{
			if(head->next)
			{
				head->next = InsertAfter(head->next, after, newVal);
			}
			return head;
		}
	}

}
Node* InsertBefore(Node* head,int before, int newVal)
{
	if(head)
	{
		if(head->val==before)
		{
			Node* tmp = new Node(newVal);
			tmp->next = head;
			return tmp;
		}
		else
		{
			if(head->next)
			{
				head->next = InsertBefore(head->next, before, newVal);
			}
			return head;
		}
	}

}
Node* DeleteNode(Node* head,int key)
{
	if(head)
	{
		if(head->val == key)
		{
			Node *tmp = nullptr;
			if(head->next)
			{
				tmp = new Node(head->next->val);
				tmp->next = head->next->next;
			}

			delete(head);
			return tmp;
		}
		else
		{
			head->next = DeleteNode(head->next,key);
			return head;
		}
	}
}
void PrintList(Node* head)
{
	if(head)
	{
		cout<<head->val<<"\t";
		PrintList(head->next);
	}
}
int main()
{
	cout<<__FUNCTION__<<" entry"<<endl;
	Node* head = nullptr;
	head = InsertAtEnd(head, 10);
	head = InsertAtEnd(head, 20);
	head = InsertAtEnd(head, 30);
	head = InsertAtEnd(head, 40);
	head = InsertAtStart(head,5);
	head = InsertAtStart(head,7);
	head = InsertAfter(head,30,80);
	head = InsertBefore(head,40,2);
	head = DeleteNode(head,30);
	PrintList(head);
	return 0;
}

