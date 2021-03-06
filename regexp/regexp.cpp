// regexp.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


string cbool(bool b) {
	return b ? "true" : "false";
}

int main()
{
	string str("(AB|BCC*A)");
	Grep grep(str);
	cout << grep.toGraphString() << endl;
	cout << cbool(grep.test("AB")) << endl;
	cout << cbool(grep.test("BCA")) << endl;
	cout << cbool(grep.test("BCCCA")) << endl;

	cout << cbool(grep.test("ABA")) << endl;
	cout << cbool(grep.test("BCC")) << endl;
	cout << cbool(grep.test("BA")) << endl;
    return 0;
}



