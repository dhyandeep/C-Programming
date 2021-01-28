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
		cout << tmp->val<<" ";
		tmp = tmp->next;
	}
	cout << endl;
}

Node* SortedMerge(Node* head1, Node* head2)
{
	Node* sortedHead = nullptr;
	Node* sortedTail = nullptr;
	if (!head1)
		return head2;
	if (!head2)
		return head1;
	if ((head1->val) < (head2 -> val))
	{
		sortedHead = head1;
		sortedTail = head1;
		head1 = head1->next;
	}
	else
	{
		sortedHead = head2;
		sortedTail= head2;
		head2 = head2->next;
	}
	while (head1&&head2)
	{
		if ((head1->val) < (head2->val))
		{
			sortedTail->next = head1;
			head1 = head1->next;
			sortedTail = sortedTail->next;
		}
		else
		{
			sortedTail->next = head2;
			head2 = head2->next;
			sortedTail = sortedTail->next;
		}
	}
	if (head2)
	{
		sortedTail->next = head2;
	}
	else if (head1)
	{
		sortedTail->next = head1;
	}
	return sortedHead;
}

int main()
{
	Node* head1 = nullptr;
	Node* head2 = nullptr;

	insert(&head1, 10);
	insert(&head1, 20);
	insert(&head1, 30); 
	insert(&head1, 40);
	insert(&head1, 50);

	insert(&head2, 15);
	insert(&head2, 25);
	insert(&head2, 35);
	insert(&head2, 45);
	insert(&head2, 55);
	insert(&head2, 65);
	
	

	PrintList(head1);
	PrintList(head2);

	Node* newList = SortedMerge(head1, head2);

	PrintList(newList);

}