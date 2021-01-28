#include<iostream>
using namespace std;
typedef struct Node
{
	int val;
	Node* next;
	Node(int val_)
	{
		val = val_;
		next = nullptr;
	};

}Node_t;
int insert(Node** head, int val)
{
	if (!head)
		return -1;
	Node* curr = *head;
	if (!curr)
	{
		*head = new Node(val);
		return 0;
	}
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = new Node(val);
	return 0;
}
void PrintList(Node* head)
{
	Node* tmp = head;
	while (tmp)
	{
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << endl;
}
void PairSwap(Node** head)
{
	if (!head)
		return;
	Node* curr = *head;
	if ((!curr) || (!curr->next))
	{
		return;
	}

	Node* prev = curr;
	curr = curr->next;
	*head = curr;
	Node* next;
	while (true)
	{
		next = curr->next;
		curr->next = prev;
		if ((next == nullptr) || (next->next == nullptr))
		{
			prev->next = next;
			break;
		}
		prev->next = next->next;
		prev = next;
		curr = next->next;
	}
}
//10 20 30 40 50 60
//20 10 40 30 60 50
int main()
{
	Node* head1 = nullptr;

	insert(&head1, 10);
	insert(&head1, 20);
	insert(&head1, 30);
	insert(&head1, 40);
	insert(&head1, 50);
	insert(&head1, 60);
	PairSwap(&head1);
	PrintList(head1);
}