#include <iostream>
#include <windows.h>
using namespace std;
CRITICAL_SECTION cSection;
static int counter = 0;
HANDLE ghWriteEvent = CreateEvent( 
        NULL,              // default security attributes
        FALSE,             // Auto-reset event
        TRUE,              // initial state is signalled
        TEXT("WriteEvent")  // object name
        ); 
DWORD WINAPI ThreadFunc(LPVOID lpParameter)	//this thread writes the data and signals write event
{
	EnterCriticalSection(&cSection);		// blocks until the thread can take ownership of the critical section
	static int i = 0;
	cout<<"Entered thread GetCurrentThreadId = "<<GetCurrentThreadId()<<"serial number = "<<i++<<endl;
	LeaveCriticalSection (&cSection);		// Release ownership of the critical section
	SetEvent(ghWriteEvent);
	return 1;
}
void main()
{
	HANDLE hThread1[1000];
	if (!InitializeCriticalSectionAndSpinCount(&cSection, 
        0x00000400) ) 
		cout<<"Error initializing critical section"<<endl;
	
	while(counter<1000)
	{
		DWORD result = WaitForSingleObject(ghWriteEvent,INFINITE);//wait for the thread write event which is initially set
		if(result == WAIT_OBJECT_0)
		{
			hThread1[counter] = CreateThread(0,0,ThreadFunc,0,0,0);
			counter++;
		}
	}
	WaitForMultipleObjects(1000, hThread1, 1, INFINITE);
	cout<<"Exiting main i="<<counter<<endl;
}
