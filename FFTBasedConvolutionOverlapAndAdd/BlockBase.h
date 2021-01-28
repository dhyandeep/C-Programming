#pragma once
#include "SmQueue.h"

enum BlockType
{ 
    BT_Data_Gen, BT_Data_Itp 
}; 
  
class BlockBase
{
	public:
 	BlockBase();
 	virtual ~BlockBase();
	static BlockBase* Create(BlockType type);
	virtual int Operate() = 0;
};
