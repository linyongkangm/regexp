#pragma once
#include "Digraph.h"
#include "Edge.h"
#include <vector>

using std::vector;

class DirectedDFS
{
private:
	vector<bool> mark;
	void dfs(Digraph digraph, int s);
protected:
	bool connected(Edge e);
public:
	DirectedDFS(Digraph digraph , int s);
	DirectedDFS(Digraph digraph, vector<int> sources);
	bool marked(int v);
	~DirectedDFS();
};

