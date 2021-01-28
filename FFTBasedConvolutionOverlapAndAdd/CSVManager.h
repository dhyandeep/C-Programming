#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
class CSVManager
{
	ifstream m_infile;
	static CSVManager* m_Instance;
	CSVManager();
	CSVManager& operator = (const CSVManager& cpy);
	CSVManager(const CSVManager& cpy);
	public:
	static CSVManager* GetInstance();
	int ReadLine(vector<int>& outLine);
	~CSVManager();

};

