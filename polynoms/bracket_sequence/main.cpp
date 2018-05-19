#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "func.h"
using namespace std;
int main()
{
	polynom a("2x^2 + 3x"), b("3x^3+2x"), c;
	c = a * b;
	cout << c;
	c = c + b;
	cout << c;
	c = c - b;
	cout << c;
	system("pause");
}