#pragma once
#include"BlockBase.h"
#include"SmQueue.h"
using namespace std;
class DataInterpretationBlock:public BlockBase
{
	DataInterpretationBlock(const DataInterpretationBlock& in);
	DataInterpretationBlock& operator =(const DataInterpretationBlock& in);
	public:
	int Operate();
 	DataInterpretationBlock();
	~DataInterpretationBlock();
};
