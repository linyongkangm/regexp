#include "stdafx.h"
#include "Edge.h"

Edge::Edge(int v, int w, char ch):v(v), w(w), ch(ch)
{
}

int Edge::from()
{
	return v;
}

int Edge::to()
{
	return w;
}

bool Edge::match(char32_t c)
{
	return ch == c;
}

char Edge::matchValue()
{
	return ch;
}
