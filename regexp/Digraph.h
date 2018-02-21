#pragma once
#include "Edge.h"
#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>

using std::ostringstream;
using std::endl;
using std::string;
using std::vector;
using std::runtime_error;

class Digraph
{
private:
	int vNum; //顶点数量
	int eNum; //边数量
	vector<vector<Edge>> adj;
public:
	Digraph(int num);
	void addEdge(int v, int w, char ch);
	void addEdge(Edge e);
	vector<Edge> adjs(int v);
	vector<Edge> edges();
	int vertexCount() { return vNum; };
	int edgeCount() { return eNum; };
	string toString();
};

