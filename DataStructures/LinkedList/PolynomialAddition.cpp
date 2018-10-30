#include <iostream>
using namespace std;
struct Node
{
	int coeff,pow;
	Node* next;
	Node():coeff(0),pow(0),next(nullptr)
	{

	}
	Node(int _coeff, int _pow):coeff(_coeff),pow(_pow),next(nullptr)
	{

	}
};
void PrintList(Node** llist);
Node* PolyAdd(Node* Head1, Node* Head2)
{
	Node* tmp1 = Head1;
	Node* tmp2 = Head2;
	Node* result = new Node();
	Node* nodeptr = result;
	//cout<<__FUNCTION__<<" ENTERED "<<endl;
	while((tmp1)&&(tmp2))
	{

		//cout<<__FUNCTION__<<" while(tmp1&&tmp2) "<<endl;
		if((tmp1->pow)<(tmp2->pow))
		{
			//cout<<__FUNCTION__<<" (tmp1->pow)<(tmp2->pow) "<<endl;
			result ->coeff = tmp2->coeff;
			result-> pow = tmp2->pow;
			tmp2 = tmp2->next;

		}
		else if((tmp1->pow)>(tmp2->pow))
		{
			//cout<<__FUNCTION__<<" (tmp1->pow)>(tmp2->pow) "<<endl;
			result ->coeff = tmp1->coeff;
			result-> pow = tmp1->pow;
			tmp1 = tmp1->next;

		}
		else
		{
			//cout<<__FUNCTION__<<" else case "<<endl;
			result->coeff = tmp1->coeff+tmp2->coeff;
			result->pow = tmp1->pow;
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		result->next = new Node();
		result = result->next;
	}
	//cout<<__FUNCTION__<<" EXITING "<<endl;
	PrintList(&nodeptr);
	return nodeptr;
}
void InsertNode(Node** head, int coeff, int pow)
{
	Node* tmpHead = *head;
	Node* nptr;
	//cout<<__FUNCTION__<<" ENTERED "<<endl;
	if(tmpHead)
	{
		while(tmpHead->next)
		{
			tmpHead = tmpHead->next;
		}
		tmpHead->next = new Node(coeff, pow);
		//cout<<__FUNCTION__<<" Inserted successfully "<<endl;
	}
	else
	{
		//cout<<__FUNCTION__<<" Inserted head "<<endl;
		tmpHead = new Node(coeff, pow);
		*head = tmpHead;
	}
}
void PrintList(Node** llist)
{
	//cout<<__FUNCTION__<<" ENTERED "<<endl;
	if(llist)
	{
		//cout<<__FUNCTION__<<" ENTERED if(llist) "<<endl;
		Node* headPtr = *llist;
		bool flag=0;
		while(headPtr)
		{
			//cout<<headPtr->coeff<<" X^"<<headPtr->pow<<" ";
			headPtr = headPtr->next;
		}
		//cout<<__FUNCTION__<<" EXITING"<<endl;
	}
}
int main()
{
	cout<<__FUNCTION__<<" ENTERED "<<endl;
	Node* headNode1 = nullptr;
	InsertNode(&headNode1, 2, 3);
	InsertNode(&headNode1, 4, 1);
	PrintList(&headNode1);
	Node* headNode2 = nullptr;
	InsertNode(&headNode2, 3, 3);
	InsertNode(&headNode2, 1, 1);
	PrintList(&headNode2);
	Node* result = PolyAdd(headNode1,headNode2);
	PrintList(&result);
	return 0;
}

