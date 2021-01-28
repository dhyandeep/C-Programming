#pragma once
#include"BlockBase.h"
#include"SmQueue.h"
using namespace std;
class DataGenerationBlock:public BlockBase
{
	DataGenerationBlock& operator = (const DataGenerationBlock& in);
	DataGenerationBlock(const DataGenerationBlock& in);
	public:
	int Operate();
	int RandomOperate();
	DataGenerationBlock();
	~DataGenerationBlock();
};
