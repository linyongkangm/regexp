// regexp.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


int main()
{
	string str("(AB|BCC*A)");
	Grep grep(str);
	cout << grep.toGraphString() << endl;
	cout << (grep.test("BCCCCCCCCCCA") ? "true" : "false") << endl;
    return 0;
}



