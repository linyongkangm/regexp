#pragma once

#include "CONSTEXPR.h"

class Edge
{
private:
	int v;
	int w;
	char ch;
public:
	Edge(int v, int w , char ch);
	int from();
	int to();
	bool match(char c);
	bool isArbitrary();
	char matchValue();
};

