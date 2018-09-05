#pragma once
#include <iostream>
#include<string>
#include <windows.h>
#include<cstdint>

#define BUFSIZE 1024

using namespace std;

enum PIPE_STATUS
{
	PipeServerCreationSuccess = 0,
	PipeClientCreationSuccess,
	PipeHandleInvalidError,
	PipeNameInvalidError,
	PipeBusyError,
	PipeListeningError,
	PipeCreationWaitTimeoutError,
	PipeFileNotFoundError,
	PipeCreationUnknownError,
	PipeSendSuccess,
	PipeWriteFileFailedError,
	PipeConnectionError,
	PipeReceiveSuccess,
	PipeBrokenError,
	PipeReadFailedError,
};
class PipeLib
{
	HANDLE m_hPipe;
	

	PipeLib ( const PipeLib& obj);			//hiding copy ctor
	PipeLib& operator= ( const PipeLib&);	//hiding assnmnt oprtor

public:
	string m_pipeName;
	PipeLib(const string& nameInput);
	~PipeLib(void);
	PIPE_STATUS createConnection();
	PIPE_STATUS sendMsg(const void *,const size_t) const;
	PIPE_STATUS rcvMsg(void *,const size_t) const;
	void closeConnection();
	bool waitForConnection();
};

