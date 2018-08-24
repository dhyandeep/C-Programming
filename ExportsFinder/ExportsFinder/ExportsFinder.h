#pragma once
#include <string>
#include <vector>
using namespace std;


class ExportsFinder
{
	string	m_CurrentDir;
	vector<string> m_FileList;

public:
	ExportsFinder(void);
	void Init(string CurLocation);
	void Term();
	int FindExports();
	~ExportsFinder(void);
};

