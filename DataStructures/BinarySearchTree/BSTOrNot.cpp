#include<iostream>
using namespace std;
typedef struct Node
{
	int val;
	Node* left;
	Node* right;
	Node(int val_)
	{
		val = val_;
		left = nullptr;
		right = nullptr;
	}
};
int insert(Node** head, int insVal)
{
	if (!head)
		return -1;
	Node* curr = *head;
	if (!curr)
	{
		*head = new Node(insVal);
		return 0;
	}
	while (curr) 
	{
		if ((insVal < curr->val)&& (!curr->left))
		{
			curr->left = new Node(insVal);
			return 0;
		}
		if ((insVal > curr->val) && (!curr->right))
		{
			curr->right = new Node(insVal);
			return 0;
		}
		if (insVal < curr->val)
		{
			curr = curr->left;
				continue;
		}
		if (insVal > curr->val)
		{
			curr = curr->right;
				continue;
		}
	}
}
void InorderTraverse(Node* head)
{
	if (head)
	{
		InorderTraverse(head->left);
		cout << head->val << " ";
		InorderTraverse(head->right);
	}
}
bool CheckBST(Node* head, int min, int max)
{
	if (!head)
		return true;
	if ((head->val > max) || (head->val < min))
	{
		return false;
	}
	bool left = CheckBST(head->left, min, head->val);
	bool right = CheckBST(head->right,head->val, max);
	return left & right;
}
int main()
{
	Node* head = nullptr;
	insert(&head, 50);
	insert(&head, 30);
	insert(&head, 75);
	insert(&head, 80);
	insert(&head, 20);
	insert(&head, 90);
	InorderTraverse(head);
	cout << endl;
	cout << CheckBST(head, INT_MIN, INT_MAX) << endl;
}