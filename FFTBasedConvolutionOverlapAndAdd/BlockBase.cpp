#include<iostream>
#include "BlockBase.h"
#include "DataGenerationBlock.h"
#include "DataInterpretationBlock.h"
using namespace std;
BlockBase::BlockBase()
{
	cout<<__FUNCTION__<<" Entered"<<endl;
}
BlockBase* BlockBase::Create(BlockType type)
{
	if(type == BT_Data_Gen)
		return new DataGenerationBlock();
	else if(type == BT_Data_Itp)
		return new DataInterpretationBlock();
}
BlockBase::~BlockBase()
{
	cout<<__FUNCTION__<<" Entered"<<endl;
}
