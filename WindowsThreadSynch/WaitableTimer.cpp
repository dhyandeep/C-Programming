#include <iostream>
#include <windows.h>
using namespace std;
CRITICAL_SECTION cSection;
static int counter = 0;
LARGE_INTEGER liDueTime ;
HANDLE hTimer = NULL;
__int64 qwDueTime;
#define _SECOND 10000000

DWORD WINAPI ThreadFunc(LPVOID lpParameter)	//this thread writes the data and signals write event
{
	qwDueTime = -1 * _SECOND;	// 1 second timeout setting
		// Copy the relative time into a LARGE_INTEGER.
	liDueTime.LowPart  = (DWORD) ( qwDueTime & 0xFFFFFFFF );
	liDueTime.HighPart = (LONG)  ( qwDueTime >> 32 );
	EnterCriticalSection(&cSection);								// blocks until the thread can take ownership of the critical section
	static int i = 0;
	cout<<"Entered thread GetCurrentThreadId = "<<GetCurrentThreadId()<<"serial number = "<<i++<<endl;
	if (!SetWaitableTimer(hTimer, &liDueTime, 0, NULL, NULL, 0))	//count timer to 1 second
	{
		printf("SetWaitableTimer failed (%d)\n", GetLastError());
		return 2;
	}
	LeaveCriticalSection (&cSection);								// Release ownership of the critical section
	
	return 1;
}
void main()
{
	HANDLE hThread1[1000];
	hTimer = CreateWaitableTimer(NULL, FALSE, NULL);
	if (!InitializeCriticalSectionAndSpinCount(&cSection, 
		0x00000400) ) 
	{
		cout<<"Error initializing critical section"<<endl;
	}
	
	while(counter<1000)
	{
		//printf("Waiting for 1 seconds...\n");

		hThread1[counter] = CreateThread(0,0,ThreadFunc,0,0,0);
		counter++;

		if (WaitForSingleObject(hTimer, INFINITE) != WAIT_OBJECT_0)		// wait for the timer from the created thread 
		printf("WaitForSingleObject failed (%d)\n", GetLastError());
	}
	WaitForMultipleObjects(1000, hThread1, 1, INFINITE);
	cout<<"Exiting main i="<<counter<<endl;
}
