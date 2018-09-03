#include "BSTree.h"
#include <iostream>
using namespace std;
void main()
{
	BSTree *bTree = new BSTree();
	bTree->InsertValue(70);
	bTree->InsertValue(30);
	bTree->InsertValue(40);
	bTree->InsertValue(80);
	bTree->InsertValue(10);
	bTree->InsertValue(50);
	cout<<"Inorder************"<<endl;
	bTree->PrintInorder(bTree->GetRootNode());
	cout<<"After delete"<<endl;
	bTree->DeleteValue(bTree->GetRootNode(),40);
	cout<<"Inorder************"<<endl;
	bTree->PrintInorder(bTree->GetRootNode());
	bTree->SetRootNode(bTree->DeleteValue(bTree->GetRootNode(),10));
	cout<<"Inorder************"<<endl;
	bTree->PrintInorder(bTree->GetRootNode());
	bTree->SetRootNode(bTree->DeleteValue(bTree->GetRootNode(),70));
	cout<<"Inorder************"<<endl;
	bTree->PrintInorder(bTree->GetRootNode());
	cout<<"Preorder************"<<endl;
	bTree->PrintPreorder(bTree->GetRootNode());
	cout<<"Postorder************"<<endl;
	bTree->PrintPostorder(bTree->GetRootNode());
}