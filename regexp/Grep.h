#pragma once
#include <string>
#include "Stack.h"
#include "Digraph.h"


using std::string;
class Grep
{
private:
	Digraph digraph;
	int length;
public:
	Grep(string &reg);
	~Grep();
	bool test( string &str);
	string toGraphString();
};

