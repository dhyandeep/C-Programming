
#include"DataInterpretationBlock.h"
#include"SmQueue.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include"FFTConv.h"
#include<string.h>
#include<unistd.h>
#include<fstream>
#include<sys/wait.h>

#define KERN_SIZE 9

using namespace std;
double kernel[] = {0.00025177, 0.008666992, 0.078025818, 0.24130249, 0.343757629, 0.24130249, 0.078025818, 0.008666992, 0.000125885};
const int threshold = 12;

const char*  g_outFileName = "out.txt";
DataInterpretationBlock::DataInterpretationBlock()
{
	cout<<__FUNCTION__<<"entered"<<endl;
}

DataInterpretationBlock::~DataInterpretationBlock()
{
	cout<<__FUNCTION__<<"entered"<<endl;
}

int DataInterpretationBlock::Operate()
{
	if (fork()== 0) 
	{
		cout<<__FUNCTION__<<"inside child"; 
	  
		SmQueue* gQ = SmQueue::GetInstance();

		long dqCount = 0;
		int nOfLines;
		gQ->Dequeue(nOfLines);
		ofstream MyFile(g_outFileName);

		cout<<"********"<<"nof lines"<<nOfLines<<endl;
		while(nOfLines--)
		{
			int lineSize;
			gQ->Dequeue(lineSize);

			cout<<"Line size:************************ "<<lineSize<<endl;
			cout<<"Processing Line"<<nOfLines<<endl;

			int windowIter = 0, dqCount=0;
			int isBeg=1;
			double convout[18]={0}, convoutPrev[18]={0}, input[9]={0},result[18]={0};
			while((dqCount<lineSize))
			{
				int dqVal;

				gQ->Dequeue(dqVal);
				input[windowIter] = dqVal;
				dqCount++;

				if(windowIter!=8)
				{
					windowIter++;
					continue;
				}
				FFTConvolve(input, kernel, convout, KERN_SIZE);
				
				for(int i=0; i<KERN_SIZE; i++)
				{
					result[i] = convoutPrev[KERN_SIZE+i]+convout[i];
					//MyFile<<std::setprecision(8) << std::showpoint <<result[i]<<" ";
					if(result[i]>threshold)
						MyFile<<"1 ";
					else
						MyFile<<"0 ";

				}
				isBeg =0;
				memcpy(convoutPrev, convout,((2*KERN_SIZE)-1)*sizeof(double));
				windowIter = 0;
			}
			if(dqCount==lineSize)
			{
				for(int i=windowIter; i<KERN_SIZE;i++)
					input[i] = 0;
				if(windowIter!=0)
				{
					if(isBeg == 1)
					{
						FFTConvolve(input, kernel, convout, KERN_SIZE);
						for(int i=KERN_SIZE/2; i<KERN_SIZE+KERN_SIZE/2-1; i++)
						{
							//MyFile<<std::setprecision(8) << std::showpoint <<convout[i]<<" ";

							if(convout[i]>threshold)
								MyFile<<"1 ";
							else
								MyFile<<"0 ";
						}
					}
					else
					{
						FFTConvolve(input, kernel, convout,windowIter);
						for(int i=0 ; i<windowIter; i++)
						{
							result[i] = convoutPrev[KERN_SIZE+i]+convout[i];
							//MyFile<<std::setprecision(8) << std::showpoint <<result[i]<<" ";
							if(result[i]>threshold)
								MyFile<<"1 ";
							else
								MyFile<<"0 ";

						}
						
					}
				MyFile<<std::setprecision(8) << std::showpoint <<"\t"<<" ";
				}
			}
			MyFile<<endl;
		}
		MyFile.close();
	}
	else
	{ 
		cout<<__FUNCTION__<<" inside parent"; 
		wait(NULL); 
		cout<<__FUNCTION__<<" child completed"; 
	} 
	cout<<__FUNCTION__<<"Exiting"<<endl;
	return 0;
}
