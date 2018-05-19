

#include <iostream>
#include <stack>
#include <string>
#include "gtest/gtest.h"
#include "../bracket_sequence/func.h"

TEST(plus, test1)
{
	polynom a1("2x+3");
	polynom b1("2x^2+2x+3");
	polynom c1("2x^2+4x+6");
	cout << a1 + b1 << c1;
	bool temp = false;
	if (c1 == a1 + b1)
		temp = true;
	EXPECT_TRUE(temp);
}
TEST(plus, test2)
{
	bool temp = false;
	polynom a2("0");
	polynom b2("0");
	polynom c2("0");
	temp = false;
	if (c2 == a2 + b2)
		temp = true;
	EXPECT_TRUE(temp);
}
TEST(minus, test1)
{
	polynom a1("2x+3");
	polynom b1("2x^2+2x+3");
	polynom c1("2x^2+4x+6");
	cout << a1 + b1 << c1;
	bool temp = false;
	if (a1 == c1 - b1)
		temp = true;
	polynom(x) = c1 - b1;
	cout << c1 - b1 << a1 <<x.nn()<<a1.nn() ;
	EXPECT_TRUE(temp);
}
TEST(minus,test2)
{
	bool temp = false;
	polynom a2("0");
	polynom b2("0");
	polynom c2("0");
	temp = false;
	if (c2 == a2 - b2)
		temp = true;
	EXPECT_TRUE(temp);
}

	