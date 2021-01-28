#include"CSVManager.h"
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#define DELIM ','
using namespace std;
CSVManager* CSVManager::m_Instance;
CSVManager::CSVManager()
{
	cout<<__FUNCTION__<<" Entered "<<endl;
	m_infile.open("incsv.txt");
}
CSVManager::~CSVManager()
{
	cout<<__FUNCTION__<<" Entered "<<endl;
	m_infile.close();
}
CSVManager* CSVManager::GetInstance()
{
	cout<<__FUNCTION__<<" Entered "<<endl;
	if(m_Instance)
		return m_Instance;
	if(!m_Instance)
	{
		m_Instance = new CSVManager();
	}
	return m_Instance;
}
int CSVManager::ReadLine(vector<int>& outLine)
{
	cout<<__FUNCTION__<<" Entered "<<endl;
	string line, word, temp; 
 

	outLine.clear();   
	getline(m_infile, line); 
	cout<<"Line: "<<line<<" line.size:"<< line.size()<<endl;
	if(line.size()==0)
		return 0;
	stringstream s(line); 
  	long wordCount = 0;
	while (getline(s, word, DELIM)) 
	{ 
		//if(s.bad())
		//	break;
		cout<<"Tokenized "<<word<<endl;
		wordCount++;
		outLine.push_back(stoi(word)); 
	} 
  
     	return wordCount;
}
