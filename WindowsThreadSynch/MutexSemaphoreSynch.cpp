#include <iostream>
#include <windows.h>
using namespace std;
HANDLE hSemaphore = CreateSemaphore(NULL, 1, 1, "write_sem"); 

DWORD WINAPI ThreadFunc(LPVOID lpParameter)
{
	HANDLE hMutex = CreateMutex(0,0,"WriteMutex");
	DWORD waitResult = WaitForSingleObject(hMutex,INFINITE);
	
	if(waitResult  == WAIT_OBJECT_0)
	{
		cout<<"Entered thread GetCurrentThreadId = "<<GetCurrentThreadId()<<endl;
		ReleaseSemaphore(hSemaphore,1,NULL);
	}
	ReleaseMutex(hMutex);
	return 1;
}
void main()
{
	HANDLE hThread1[1000];
	int i=0;
	//HANDLE hSemaphore = CreateSemaphore(NULL, 1, 1, "write_sem"); 
	while(i<1000)
	{
		cout<<"creted thread "<<i<<endl;
		DWORD result = WaitForSingleObject(hSemaphore,INFINITE);
		if(result == WAIT_OBJECT_0)
		{
			hThread1[i] = CreateThread(0,0,ThreadFunc,0,0,0);
			
		}
		i++;
	}
	WaitForMultipleObjects(1000, hThread1, 1, INFINITE);
	cout<<"Exiting main i="<<i<<endl;
}
