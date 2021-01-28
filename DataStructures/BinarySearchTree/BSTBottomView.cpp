#include<iostream>
#include<queue>
#include<map>
using namespace std;
typedef struct Node
{
	int val;
	Node* left;
	Node* right;
	int horizDist;
	Node(int val_, int horizDist_)
	{
		val = val_;
		horizDist = horizDist_;
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
		*head = new Node(insVal, 0);
		return 0;
	}
	int horiz = 0;
	while (curr)
	{
		if ((insVal < curr->val) && (!curr->left))
		{
			curr->left = new Node(insVal, horiz - 1);
			return 0;
		}
		if ((insVal > curr->val) && (!curr->right))
		{
			curr->right = new Node(insVal, horiz + 1);
			return 0;
		}
		if (insVal < curr->val)
		{
			horiz = horiz - 1;
			curr = curr->left;
			continue;
		}
		if (insVal > curr->val)
		{
			horiz = horiz + 1;
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
		cout << "(" << head->val << ", " << head->horizDist << " )";
		InorderTraverse(head->right);
	}
}
void PrintBottomView(Node* head)
{
	map<int, int> horizDistMap;
	queue<Node*> q;
	q.push(head);
	while (!q.empty())
	{
		int levelSize = q.size();
		int count = 0;
		while (count<levelSize)
		{
			Node* curr = q.front();
			if (curr->left)
				q.push(curr->left);
			if (curr->right)
				q.push(curr->right);
			q.pop();
			if (horizDistMap.find(head->horizDist) != horizDistMap.end())
				horizDistMap[head->horizDist] = head->val;
			else
				horizDistMap.insert(pair<int, int>(head->horizDist, head->val));
			count++;
		}
	}
	for (auto i : horizDistMap)
	{
		cout << i.second << " "<<;
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
	PrintBottomView(head);
	cout << endl;

}