#include"DataGenerationBlock.h"
#include<iostream>
#include<fstream>
#include "SmQueue.h"
#include "CSVManager.h"
#include<sys/wait.h>
#include<unistd.h>
using namespace std;
DataGenerationBlock::DataGenerationBlock()
{
	cout<<__FUNCTION__<<"entered"<<endl;
}

DataGenerationBlock::~DataGenerationBlock()
{
	cout<<__FUNCTION__<<"entered"<<endl;
}

int DataGenerationBlock::Operate()
{
	if (fork()== 0) 
	{
		ifstream infile;
		int inVal, count =0;
		vector<int> lineIn;

		infile.open("incsv.txt");
		SmQueue* qInst = SmQueue::GetInstance();
		CSVManager* csvInst = CSVManager::GetInstance();
		while(count = csvInst->ReadLine(lineIn))
		{
			cout<<"Count = "<<count<<endl;
			cout<<"lineIn.size() = "<<lineIn.size()<<endl;

			for(int i=0; i<lineIn.size(); i++)
			{
				cout<<"Got: "<<lineIn[i]<<" ";
				qInst->Enqueue(lineIn[i]);	
			}
			lineIn.clear();
		}
	}
	else
	{ 
		cout<<__FUNCTION__<<" Parent entered"<<endl;
		wait(NULL); 
		cout<<__FUNCTION__<<" Child finished"<<endl;
	} 

	return 0;
}
int DataGenerationBlock::RandomOperate()
{

	if (fork()== 0) 
	{
		ifstream infile;
		int inVal, count =0;
		vector<int> lineIn;

		infile.open("incsv.txt");
		SmQueue* qInst = SmQueue::GetInstance();
		CSVManager* csvInst = CSVManager::GetInstance();
		while(count = csvInst->ReadLine(lineIn))
		{
			cout<<"Count = "<<count<<endl;
			cout<<"lineIn.size() = "<<lineIn.size()<<endl;

			for(int i=0; i<lineIn.size(); i++)
			{
				cout<<"Got: "<<lineIn[i]<<" ";
				qInst->Enqueue(lineIn[i]);	
			}
			lineIn.clear();
		}
	}	
	else
	{ 
		printf("HP: hello from parent\n"); 
		wait(NULL); 
		printf("CT: child has terminated\n"); 
	} 

	return 0;
}
