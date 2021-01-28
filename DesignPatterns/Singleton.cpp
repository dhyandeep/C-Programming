#include<iostream>
using namespace std;
class Logger
{
	static Logger* m_Inst;
	Logger() {};
public:
	static Logger* getInst();
	void WriteLog(string str) { cout << __FUNCTION__ << " Writing on the screen " << str.c_str() << endl; };
};
Logger* Logger:: m_Inst = nullptr;
Logger* Logger::getInst()
{
	if (m_Inst)
	{
		cout << __FUNCTION__ << " Returning existing inst" << endl;
		return m_Inst;
	}
	else
	{
		cout << __FUNCTION__ << " Creating new inst" << endl;
		return (m_Inst = new Logger());
	}
}
int main()
{
	Logger* l = Logger::getInst();
	l->WriteLog(string("helloworld"));
	Logger* ln = Logger::getInst();
}