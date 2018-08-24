#include "ExportsFinder.h"
#include <iostream>
#include <windows.h>
const int MAX_FILE_NOS = 256;
const string DUMPBIN_SCRIPT = "dumpbin";
const string EXPORTS_OPT = "/ALL ";
const string TO_FILE_SYMBOL = " >> ";
const string TXT_EXTENTION = ".txt";
const string DIR_SEPARATOR = "\\";
const string BACK_DIR = "\\..";

ExportsFinder::ExportsFinder(void)
{
}

void ExportsFinder::Init(string CurLocation)
{
    string search_path = CurLocation + "/*.dll";
    WIN32_FIND_DATA fd; 
    HANDLE hFind = FindFirstFile(search_path.c_str(), &fd); 
    if(hFind != INVALID_HANDLE_VALUE) { 
        do { 
            // read all (real) files in current folder
            // , delete '!' read other 2 default folder . and ..
            if(! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ) {
                m_FileList.push_back(CurLocation+DIR_SEPARATOR+fd.cFileName);
				cout<<"Found file "<<fd.cFileName<<endl;
            }
        }while(FindNextFile(hFind, &fd)); 
        FindClose(hFind); 
    } 
	//WIN32_FIND_DATA fd; 
	search_path = CurLocation + "/*.exe";
	hFind = FindFirstFile(search_path.c_str(), &fd); 
    if(hFind != INVALID_HANDLE_VALUE) { 
        do { 
            // read all (real) files in current folder
            // , delete '!' read other 2 default folder . and ..
            if(! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ) {
                m_FileList.push_back(CurLocation+DIR_SEPARATOR+fd.cFileName);
				cout<<"Found file "<<fd.cFileName<<endl;
            }
        }while(FindNextFile(hFind, &fd)); 
        FindClose(hFind); 
    } 
    
}

int ExportsFinder::FindExports(void)
{
	string VsComnEnvPath = getenv("VS100COMNTOOLS");
	for(auto i = m_FileList.begin(); i!=m_FileList.end(); i++)
	{
		
		string script_complete = DUMPBIN_SCRIPT+EXPORTS_OPT+ (*i)+" > "+(*i) + TXT_EXTENTION;
		system(script_complete.c_str());
		cout<<"Executed dump for "<<*i<<endl;
	}
	
	return 1;
}
ExportsFinder::~ExportsFinder(void)
{
}
