#include <iostream>
#include "Stack.h"
using namespace std;
void main()
{
	Stack* st = new Stack(10);
	st->Push(1);
	st->Push(2);
	st->Push(3);
	st->Push(4);
	st->Push(5);
	st->Push(6);
	st->Push(7);
	st->Push(8);
	st->Push(9);
	st->Push(10);
	st->Push(11);
	int val = st->Pop();
	st->Push(12);
}