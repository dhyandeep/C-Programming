
#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <conio.h>

#define BUF_SIZE 256
#define FAILED_TO_CREATE_FILE_MAPPING_EXCEPTION "Could not create file mapping object"
#define FAILED_TO_MAP_FILE_EXCEPTION "Could not create file mapping object"
#define FAILED_TO_READ_SM_EXCEPTION "Could not read from shared memory"

TCHAR smName[]=TEXT("Global\\MQFileMappingObject");

using namespace std;

template <typename dtype, size_t size>
class SharedMem
{
	HANDLE m_hMapFile;
	LPCTSTR m_pBuf;
public:
	SharedMem();//creates shared memory
	~SharedMem();
	bool WriteMemory(dtype* ObjectToShare);
	dtype* ReadMemory();
	bool CloseSharedMem();
};
//=============================================================================================

//=============================================================================================


template <typename dtype, size_t size>
SharedMem<dtype, size>::SharedMem()
{
	 m_hMapFile = CreateFileMapping(
                 INVALID_HANDLE_VALUE,    // use paging file
                 NULL,                    // default security
                 PAGE_READWRITE,          // read/write access
                 0,                       // maximum object size (high-order DWORD)
                 BUF_SIZE,                // maximum object size (low-order DWORD)
                 smName);                 // name of mapping object

   if (nullptr == m_hMapFile)
   {
      cout<<"Could not create file mapping object "<<endl<<GetLastError();
	  throw(exception(FAILED_TO_CREATE_FILE_MAPPING_EXCEPTION));
   }
   else
   {
	   m_pBuf = (LPTSTR) MapViewOfFile(m_hMapFile,   // handle to map object
							FILE_MAP_ALL_ACCESS, // read/write permission
							0,
							0,
							BUF_SIZE);

	   if(m_pBuf == NULL)
	   {
		  cout<<"Could not map view of file "<<GetLastError()<<endl;
		  throw(exception(FAILED_TO_MAP_FILE_EXCEPTION));
		  CloseHandle(m_hMapFile);
	   }
   }
}


template <typename dtype, size_t size>
bool SharedMem<dtype, size>::WriteMemory(dtype * ObjectToShare)
{
	 CopyMemory((PVOID)m_pBuf, ObjectToShare, sizeof(dtype));
	 std::cout<<"Message sent successfully"<<endl;
	 return true;
}
template <typename dtype, size_t size>
dtype* SharedMem<dtype, size>::ReadMemory()
{
	dtype* dataFromFile= (dtype*) MapViewOfFile(hMapFile, 
               FILE_MAP_ALL_ACCESS,  
               0,
               0,
               sizeof(dtype));

	   if (pBuf == NULL)
	   {
		  _tprintf(TEXT("Could not map view of file (%d).\n"),
				 GetLastError());

	   }
	   std::cout<<dataFromFile;
	   return dataFromFile;
}


template <typename dtype, size_t size>
bool SharedMem<dtype, size>::CloseSharedMem()
{
	UnmapViewOfFile(m_pBuf);
	CloseHandle(m_hMapFile);
}


template <typename dtype, size_t size>
SharedMem<dtype, size>::~SharedMem()
{
	UnmapViewOfFile(m_pBuf);
	CloseHandle(m_hMapFile);
}