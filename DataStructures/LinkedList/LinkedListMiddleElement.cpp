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
Node* FindMiddle(Node* head)
{
	Node* mid = head;
	int count = 0;
	while (head)
	{
		if ((count % 2 == 1)&&(count>0))
			mid = mid->next;
		head = head->next;
		count++;
	}
	return mid;
}
Node* NthFromEnd(Node* head, int n)
{
	Node* curr = head;
	Node* slow = curr;
	int counter = 0;
	while (curr)
	{
		counter++;
		if (counter > n)
			slow = slow->next;
		curr = curr->next;
	}
	return slow;
}
int main()
{
	Node* head1 = nullptr;

	insert(&head1, 10);
	insert(&head1, 20);
	insert(&head1, 30);
	insert(&head1, 40);
	insert(&head1, 50);
	insert(&head1, 60);
	Node* mid = FindMiddle(head1);
	if (mid)
		cout << mid->val<<endl;
	else
		cout << "NULL"<<endl;
	Node* nth = NthFromEnd(head1, 3);
	cout << "nth = " << nth->val << endl;
}