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

bool Edge::match(char c)
{
	return ch == c;
}

bool Edge::isArbitrary()
{
	return  ch == ARBITRARY;
}

char Edge::matchValue()
{
	return ch;
}


