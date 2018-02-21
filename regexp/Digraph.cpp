#include "stdafx.h"
#include "Digraph.h"


Digraph::Digraph(int num):vNum(num),eNum(0),adj(num)
{

}

void Digraph::addEdge(int v, int w, char ch)
{
	Edge e(v, w, ch);
	adj[v].push_back(e);
}

void Digraph::addEdge(Edge e)
{
	int from = e.from();
	adj[from].push_back(e);
}

vector<Edge> Digraph::adjs(int v)
{
	return adj[v];
}

vector<Edge> Digraph::edges()
{
	vector<Edge> edges;
	auto begin = adj.begin();
	auto end = adj.end();
	while (begin != end) {
		auto b = *begin;
		edges.insert(edges.end(), b.begin(), b.end());
		begin++;
	}
	return edges;
}

string  Digraph::toString()
{
	// TODO: 在此处插入 return 语句
	ostringstream oss;
	oss << vNum << " vertices," << eNum << " edges" << endl;
	for (int v = 0; v < vNum; v++) {
		oss << v << ": ";
		for (Edge e : adjs(v)) {
			oss << e.to() << ":" << e.matchValue() << " , ";
 		}
		oss << endl;
	}
	return oss.str();
}






