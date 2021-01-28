#include<iostream>
using namespace std;
struct Node
{
	int val;
	Node* left;
	Node* right;
	Node(int arg) 
	{
		left = right = nullptr;
		val = arg;
	}
};
int InsertKey(int ins, Node** head)
{
	if (!head)
		return -1;
	Node* curr = *head;
	if (!curr)
	{
		Node* tmpNew = new Node(ins);
		*head = tmpNew;
		return 1;
	}
	while (curr)
	{
		if (ins > curr->val)
		{
			if (!curr->right)
			{
				curr->right = new Node(ins);
				return 1;
			}
			else
				curr = curr->right;
		}
		if (ins < curr->val)
		{
			if (!curr->left)
			{
				curr->left = new Node(ins);
				return 1;
			}
			else
				curr = curr->left;
		}
	}
	return -1;
}
Node* InorderPredecessor(Node* head)
{
	if (head == nullptr)
		return nullptr;
	else
	{
		Node* curr = head;
		while (curr)
		{
			if (curr->right)
				curr = curr->right;
			else
			{
				return curr;
			}
		}
	}
}
int DeleteKey(int key, Node** head)
{
	if (!head)
		return -1;
	if (!*head)
		return -1;
	Node* curr = *head;
	Node* parent = *head;
	bool left = false;
	while (curr)
	{
		if (key < curr->val)
		{
			parent = curr;
			left = true;
			curr = curr->left;
		}
		else if (key > curr->val)
		{
			parent = curr;
			left = false;
			curr = curr->right;
		}
		else
		{
			if (curr->left == nullptr)
			{
				Node* tmp = curr->right;
				delete curr;
				if (left)
					parent->left = tmp;
				else
					parent->right = tmp;
				return 1;
			}
			else if (curr->right == nullptr)
			{
				Node* tmp = curr->left;
				delete curr;
				if (left)
					parent->left = tmp;
				else
					parent->right = tmp;
			}
			else
			{
				Node* inPre = InorderPredecessor(curr->left);
				curr->val = inPre->val;
				DeleteKey(inPre->val, &curr);
				return 1;
			}
		}
	}
	return -1;
}

void InorderTraversal(Node* head)
{
	if (!head)
		return;
	
	InorderTraversal(head->left);
	cout << head->val<<" ";
	InorderTraversal(head->right);
}
int FindHeight(Node* head)
{
	if (!head)
	{
		return 0;
	}
	int leftH = 0;
	int rightH = 0;
	if(head->left)
		leftH = 1+FindHeight(head->left);
	if(head->right)
		rightH = 1+FindHeight(head->right);
	if (leftH > rightH)
		return leftH;
	else
		return rightH;
}
void PrintLevelI(Node* head, int level)
{
	if (!head)
		return;
	if (level == 0)
	{
		cout << head->val<<" ";
		return;
	}
	else
	{
		PrintLevelI(head->left, level - 1);
		PrintLevelI(head->right, level - 1);
	}
}
void LevelOrder(Node* head)
{
	int height = FindHeight(head);
	cout << "Height = " << height<<endl;
	for (int i = 0; i < height+1; i++)
	{
		PrintLevelI(head, i);
	}
}

int main()
{
	Node* head = nullptr;
	InsertKey(8, &head);
	InsertKey(4, &head);
	InsertKey(2, &head);
	InsertKey(6, &head);
	InsertKey(10, &head);
	InsertKey(9, &head);
	InsertKey(7, &head);
	InorderTraversal(head);
	cout << endl;
	DeleteKey(7, &head);
	InorderTraversal(head);
	cout << "Level Order" << endl;
	LevelOrder(head);
	return 1;
}