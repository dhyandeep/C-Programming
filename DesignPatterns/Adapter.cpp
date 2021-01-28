#include<iostream>
using namespace std;
enum PlugType {
	US,
	IND
};
class Plug
{
public:
	PlugType m_std;
};
class IndPlug : public Plug
{
public:
	IndPlug() { m_std = IND; };
};
class USPlug : public Plug
{
public:
	USPlug() { m_std = US; };
};
class Socket
{
public:
		virtual void Connect(Plug* p) = 0;
};
class USSocket : public Socket
{
public:
	void Connect(Plug* p) override
	{
		if (p->m_std == US)
			cout << __FUNCTION__ << " Connecting to socket";
	}
};
class IndSocketAdapter : public USSocket, IndPlug
{
public:
	void ConnectInd(IndPlug* p) 
	{
		Socket* uss = new USSocket();
		Plug* p = new USPlug();
		uss->Connect(p);
	}
};