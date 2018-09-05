#include "PipeLib.h"

PipeLib::PipeLib(const string& nameInput):m_pipeName(nameInput),m_hPipe(nullptr)
{
	
}

PipeLib::~PipeLib(void)
{
	closeConnection();
	if(m_hPipe!=nullptr)
		m_hPipe = nullptr;
}


PIPE_STATUS PipeLib::createConnection()
{
	PIPE_STATUS creationStatus;
	DWORD createFileError,createNamedPipeError;
	
	m_hPipe = CreateFile( 
	m_pipeName.c_str(),   // pipe name 
	GENERIC_READ |  // read and write access 
	GENERIC_WRITE|
	PIPE_WAIT, 
	0,              // no sharing 
	NULL,           // default security attributes
	OPEN_EXISTING,  // opens existing pipe 
	0,              // default attributes 
	NULL);          // no template file 
	
	if(m_pipeName.empty())
	{
		creationStatus = PipeNameInvalidError;
	}
	// Break if the pipe handle is invalid. 
	else if (m_hPipe == INVALID_HANDLE_VALUE) 
	{
	// Exit if an error other than ERROR_PIPE_BUSY occurs. 
		createFileError = GetLastError();
		switch (createFileError) 
		{
			case ERROR_PIPE_BUSY:
				cout<<"Could not open pipe. GLE="<< createFileError<<endl; 
				creationStatus = PipeBusyError;
				
				 if (!WaitNamedPipe(m_pipeName.c_str(), 30000))
				 {
					 cout<<"Timeout in WaitNamedPipe. GLE="<< createFileError <<endl; 
					 break;
				 }
				 cout<<"WaitNamedPipe success."<<endl;
			//if server, it will return ERROR_FILE_NOT_FOUND. call CreateNamedPipe instead of CreateFile in server.
			case ERROR_FILE_NOT_FOUND:
				cout<<"Could not open pipe. GLE="<< createFileError<<endl;
				m_hPipe = CreateNamedPipe( 
					m_pipeName.c_str(),             // pipe name 
					PIPE_ACCESS_DUPLEX,       // read/write access 
					PIPE_TYPE_MESSAGE |       // message type pipe 
					PIPE_READMODE_MESSAGE,   // message-read mode 
					PIPE_UNLIMITED_INSTANCES, // max. instances  
					BUFSIZE,                  // output buffer size 
					BUFSIZE,                  // input buffer size 
					0,                        // client time-out 
					NULL);                    // default security attribute
				cout<<"handle value m_hPipe = "<<m_hPipe<<endl;
				if (m_hPipe == INVALID_HANDLE_VALUE) 
				{
					createNamedPipeError = GetLastError();
					switch (createNamedPipeError) 
					{
						case ERROR_PIPE_BUSY:
						cout<<"Could not open pipe. GLE="<< GetLastError(); 
							creationStatus = PipeBusyError;
							break;
						case ERROR_FILE_NOT_FOUND:
						cout<<"Could not open pipe. GLE="<< GetLastError();
							creationStatus = PipeFileNotFoundError;
							break;
						default:
							cout<<"Could not open pipe. GLE="<< GetLastError();
							creationStatus = PipeCreationUnknownError;
							break;
					}
				}
				else
				{
					cout<< "Pipe created successfully";
					creationStatus = PipeServerCreationSuccess;
				}
				creationStatus = PipeCreationUnknownError;
				break;
		}
	}
	else
	{
		creationStatus = PipeClientCreationSuccess;
		cout<<"handle value m_hPipe = "<<m_hPipe<<endl;
	}
	return creationStatus;
}
PIPE_STATUS PipeLib::sendMsg(const void *data,const size_t nOfBytes) const
{
	cout<<"Client connected.\n";

	PIPE_STATUS sendStatus;
	BOOL fSuccess = FALSE;
	DWORD cbBytesRead = 0, cbReplyBytes = 32, cbWritten = 0;

	// Read client requests from the pipe. This simplistic code only allows messages
	// up to BUFSIZE characters in length.
	// Write the reply to the pipe. 

	fSuccess = WriteFile(
		m_hPipe,        // handle to pipe 
		data,			// buffer to write from 
		nOfBytes,		// number of bytes to write 
		&cbWritten,		// number of bytes written 
		NULL);			// not overlapped I/O 
			
	
	if (!fSuccess )
	{  
		DWORD error  = GetLastError();
		if (error == ERROR_BROKEN_PIPE)
		{
			cout<<"Error: client disconnected.\n"; 
			sendStatus = PipeBrokenError;
		}
		else if(error = ERROR_PIPE_LISTENING)
		{
			sendStatus = PipeListeningError;
		}
		else
		{
			cout<<"writeFile failed, GLE = "<<GetLastError()<<endl; 
			sendStatus = PipeWriteFileFailedError;
		}
	}
	else
	{
		cout<<"write success. \n";
		sendStatus = PipeSendSuccess;
	}
	return sendStatus;
}
PIPE_STATUS PipeLib::rcvMsg(void *data,const size_t nOfBytes) const
{
	DWORD cbRead = 0;
	BOOL fSuccess;
	PIPE_STATUS rcvStatus;

	fSuccess = ReadFile( 
		m_hPipe,				// handle to pipe 
		data,					// buffer to receive data 
		nOfBytes, // size of buffer 
		&cbRead,				// number of bytes read 
		NULL);					// not overlapped I/O 

	if (!fSuccess || cbRead == 0)
	{   
		DWORD error = GetLastError();
		if (error == ERROR_BROKEN_PIPE)
		{
			cout<<"Error: client disconnected.\n"; 
			rcvStatus = PipeBrokenError;
		}
		else if(error = ERROR_PIPE_LISTENING)
		{
			rcvStatus = PipeListeningError;
		}
		else
		{
			cout<<"ReadFile failed, GLE = "<<error; 
			rcvStatus = PipeReadFailedError;
		}
	}
	else
	{
		cout<<"read success. cbRead= \n";
		rcvStatus = PipeReceiveSuccess;
	}
	return rcvStatus;
}
void PipeLib::closeConnection()
{
	if(m_hPipe!=nullptr)
	{
		DisconnectNamedPipe(m_hPipe);
		CloseHandle(m_hPipe);
		m_hPipe = nullptr;
	}
}
bool PipeLib::waitForConnection()
{
	bool result = 0;
		if (!WaitNamedPipe(m_pipeName.c_str(), 30000))
		{
			cout<<"Timeout in WaitNamedPipe. GLE="<< GetLastError() <<endl; 
			result =0;
		}
		result = 1;
		return result;
}