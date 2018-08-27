#include <iostream>
#include <windows.h>
using namespace std;
CRITICAL_SECTION cSection;
static int counter = 0;
HANDLE hTimer = NULL;
__int64 qwDueTime;
#define _SECOND 10000000
CONDITION_VARIABLE WriteCV;
DWORD WINAPI ThreadFunc(LPVOID lpParameter)	//this thread writes the data and signals write 
{
	
	EnterCriticalSection(&cSection);		// blocks until the thread can take ownership of the critical section
	static int i = 0;
	cout<<"Entered thread GetCurrentThreadId = "<<GetCurrentThreadId()<<"serial number = "<<i++<<endl;
	LeaveCriticalSection (&cSection);		// Release ownership of the critical section
	WakeConditionVariable(&WriteCV);		// wake up the condition variable after critical section
	return 1;
}
void main()
{
	HANDLE hThread1[1000];
	InitializeConditionVariable (&WriteCV);
	if (!InitializeCriticalSectionAndSpinCount(&cSection, 
		0x00000400) ) 
	{
		cout<<"Error initializing critical section"<<endl;
	}
	
	while(counter<1000)
	{
		//printf("Waiting for 1 seconds...\n");
		
		hThread1[counter] = CreateThread(0,0,ThreadFunc,0,0,0);
		SleepConditionVariableCS (&WriteCV, &cSection, INFINITE);	//Sleep the condition variable until the critical section completes.
		counter++;
	}
	WaitForMultipleObjects(1000, hThread1, 1, INFINITE);
	cout<<"Exiting main i="<<counter<<endl;
}
