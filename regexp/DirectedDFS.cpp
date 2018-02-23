#include "stdafx.h"
#include "DirectedDFS.h"



void DirectedDFS::dfs(Digraph digraph, int s)
{
	mark[s] = true;
	auto edges = digraph.adjs(s);
	for (auto e : edges) {
		int to = e.to();
		if (connected(e) && mark[to] != true ) {
			dfs(digraph, to);
		}
	}
}

bool DirectedDFS::connected(Edge e)
{
	return e.isArbitrary();
}



DirectedDFS::DirectedDFS(Digraph digraph, int s):mark(digraph.vertexCount(),false)
{
	dfs(digraph, s);
}

DirectedDFS::DirectedDFS(Digraph digraph, vector<int> sources):mark(digraph.vertexCount(), false)
{
	for (int s : sources) {
		if(mark[s] != true) dfs(digraph, s);
	}
}

bool DirectedDFS::marked(int v)
{
	return mark[v];
}

DirectedDFS::~DirectedDFS()
{
}
