#include "stdafx.h"
#include "Grep.h"




vector<int> Grep::connecteds(Digraph digraph, int s)
{
	vector<int> v{ s };
	return connecteds(digraph, v);
}

vector<int> Grep::connecteds(Digraph digraph, vector<int> sources)
{
	vector<int> vs;
	DirectedDFS dfs(digraph, sources);
	for (int i = 0 , len = digraph.vertexCount(); i < len; i++) {
		if (dfs.marked(i)) {
			vs.push_back(i);
		}
	}
	return vs;
}

Grep::Grep(string &reg):digraph(reg.size()+1),length(reg.size()+1)
{
	Stack stack;
	int len = static_cast<string::size_type>(reg.size());
	for (int i = 0; i < len ; i++) {
		char ch = reg.at(i);
		int loop = i;
		if (ch == '(') {
			stack.push(i);
			digraph.addEdge(i, i + 1, ARBITRARY);
		}else if (ch == ')') {
			digraph.addEdge(i, i + 1, ARBITRARY);
			vector<int> ors;
			int k = stack.pop();
			char kch = reg[k];
			while (kch != '(') {
				if (kch == '|') {
					ors.push_back(k);
				}
				k = stack.pop();
				kch = reg[k];
			}

			// 纪录闭包的开始
			loop = k;

			// 处理或操作的节点连接
			for (int o : ors) {
				digraph.addEdge(o, i + 1, ARBITRARY);
				digraph.addEdge(k, o + 1, ARBITRARY);
			}
		}else if (ch == '|') {
			stack.push(i);
		}else {
			digraph.addEdge(i, i + 1, ch);
		}
		if (reg[i + 1] == '*') {
			digraph.addEdge(i+1, loop, ARBITRARY);
			digraph.addEdge(loop, i+1, ARBITRARY);
			digraph.addEdge(i+1, i + 2, ARBITRARY);
			i++;
		}
	}
	starts = connecteds(digraph, 0);
}


bool Grep::test( string str)
{
	vector<int> pc = starts;
	for (const char c : str) {
		vector<int> match;
		for (int v : pc) {
			auto edges = digraph.adjs(v);
			for (auto e : edges) {
				if (e.match(c)) {
					match.push_back(e.to());
				}
			}
		}
		pc = connecteds(digraph, match);
	}

	int end = digraph.vertexCount() - 1;
	for (int v : pc) {
		if (v == end) return true;
	}
	return false;
}

string  Grep::toGraphString()
{
	// TODO: 在此处插入 return 语句
	return digraph.toString();
}
