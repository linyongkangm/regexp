#include "stdafx.h"
#include "Stack.h"



Stack::Stack()
{
}


Stack::~Stack()
{

}


void Stack::push(int item)
{
	vec.push_back(item);
	length++;
}


int Stack::pop()
{
	int item = vec[length - 1];
	vec.pop_back();
	length--;
	return item;
}
