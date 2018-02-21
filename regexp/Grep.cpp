#include "stdafx.h"
#include "Grep.h"


const char E = '$';

Grep::Grep(string &reg):digraph(reg.size()+1),length(reg.size()+1)
{
	Stack stack;
	int len = static_cast<string::size_type>(reg.size());
	for (int i = 0; i < len ; i++) {
		char ch = reg.at(i);
		int loop = i;
		if (ch == '(') {
			stack.push(i);
			digraph.addEdge(i, i + 1, E);
		}else if (ch == ')') {
			digraph.addEdge(i, i + 1, E);
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
				digraph.addEdge(o, i + 1, E);
				digraph.addEdge(k, o + 1, E);
			}
		}else if (ch == '|') {
			stack.push(i);
		}
		else if (ch == '*') {
			digraph.addEdge(i, i + 1, E);
		}else {
			digraph.addEdge(i, i + 1, ch);
		}
		if (i+1 < len && reg[i + 1] == '*') {
			digraph.addEdge(i+1, loop, E);
		}
	}
	digraph.addEdge(len, -1, E);
}

Grep::~Grep()
{
}

bool Grep::test( string & str)
{

	return false;
}

string  Grep::toGraphString()
{
	// TODO: 在此处插入 return 语句
	return digraph.toString();
}
