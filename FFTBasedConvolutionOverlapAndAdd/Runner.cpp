#include"DataGenerationBlock.h"
#include"DataInterpretationBlock.h"
#include"BlockBase.h"
#include "SmQueue.h"
#include<iostream>
#include<pthread.h>
using namespace std;
void* Producer(void* threadArg)
{
	BlockBase* DataGen = BlockBase::Create(BT_Data_Gen);
	DataGen->Operate();
}
void* Consumer(void* threadArg)
{
	BlockBase* DataItp = BlockBase::Create(BT_Data_Itp);
	DataItp->Operate();
}
int main()
{
	//DataGenerationBlock dataGen;
	//DataInterpretationBlock dataInter;
	//dataGen.Operate();
	//dataInter.Operate();
	SmQueue* qInst = SmQueue::GetInstance();
	pthread_t threadA,threadB;
	pthread_create(&threadA, NULL, Producer, NULL);
	pthread_create(&threadB, NULL, Consumer, NULL);
	pthread_join(threadA, NULL);
	pthread_join(threadB, NULL);
	delete qInst;
	return 0;
}
