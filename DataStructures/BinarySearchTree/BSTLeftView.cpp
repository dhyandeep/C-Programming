#include<iostream>
#include<queue>
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
		if ((insVal < curr->val) && (!curr->left))
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
		cout << "("<< head->val << " )";
		InorderTraverse(head->right);
	}
}
void PrintLeftView(Node* head)
{
	if (!head)
		return;
	queue<Node*> q;
	q.push(head);

	while (!q.empty())
	{
		int count = q.size();
		int iter = count;
		while (iter)
		{
			Node*curr = q.front();
			if (iter == count)
				cout << curr->val << " ";
			q.pop();
			if (curr->left)
				q.push(curr->left);
			if (curr->right)
				q.push(curr->right);
			iter--;
		}
	}
	cout << endl;
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
	insert(&head, 70);
	InorderTraverse(head);
	PrintLeftView(head);
	cout << endl;
	
}