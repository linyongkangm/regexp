#pragma once
class Edge
{
private:
	int v;
	int w;
	char32_t ch;
public:
	Edge(int v, int w , char ch);
	int from();
	int to();
	bool match(char32_t c);
	char matchValue();
};

