#pragma once
#include <string>
#include "Stack.h"
#include "Digraph.h"
#include "DirectedDFS.h"
#include <vector>

using std::vector;
using std::string;
class Grep
{
private:
	Digraph digraph;
	int length;
	vector<int> starts;
	vector<int> connecteds(Digraph digraph, int s);
	vector<int> connecteds(Digraph digraph, vector<int> sources);
public:
	Grep(string &reg);

	bool test( string str);
	string toGraphString();
};

