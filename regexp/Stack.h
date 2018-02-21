#pragma once
#include <vector>

using std::vector;

class Stack
{
private:
	vector<int> vec;
public:
	int length;
	Stack();
	~Stack();
	void push(int item);
	int pop();
};

