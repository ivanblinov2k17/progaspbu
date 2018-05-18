#define _CRT_SECURE_NO_WARNINGS
#include "func.h"

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	string s;
	cin >> s;
	if (is_right_cons(s))
		cout << "Right";
	else
		cout << "Not Right";
	return 0;
}