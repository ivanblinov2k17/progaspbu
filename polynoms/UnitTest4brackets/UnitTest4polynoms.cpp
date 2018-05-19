

#include <iostream>
#include <stack>
#include <string>
#include "gtest/gtest.h"
#include "../bracket_sequence/func.h"
//Тесты равенства полиномов
TEST(equal, test1)
{
	polynom a1("2x+3");
	polynom a2("2x+3");
	bool temp = false;
	if (a1 == a2)
		temp = true;
	EXPECT_TRUE(temp);
}
TEST(equal, test2)
{
	polynom a1("0");
	polynom a2("0");
	bool temp = false;
	if (a1 == a2)
		temp = true;
	EXPECT_TRUE(temp);
}
TEST(equal, test3)
{
	polynom a1("2x+3");
	polynom a2("2x+3");
	bool temp = false;
	if (a1 == a2)
		temp = true;
	EXPECT_TRUE(temp);
}
//Сложение полиномов
TEST(plus, test1)
{
	polynom a1("2x+3");
	polynom b1("2x^2+2x+3");
	polynom c1("2x^2+4x+6");
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
TEST(plus, test3)
{
	bool temp = false;
	polynom a3("2x+3");
	polynom b3("2x^2+2x+3");
	polynom c3("2x^2+4x+6");
	temp = false;
	if (c3 == b3 + a3)
		temp = true;
	EXPECT_TRUE(temp);
}
//Разность полиномов
TEST(minus, test1)
{
	polynom a1("2x+3");
	polynom b1("2x^2+2x+3");
	polynom c1("2x^2+4x+6");
	bool temp = false;
	if (a1 == c1 - b1)
		temp = true;
	polynom(x) = c1 - b1;
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
TEST(minus, test3)
{
	bool temp = false;
	polynom a3("x^2+x");
	polynom b3("6x^3+x^2+x");
	polynom c3("-6x^3");
	if (c3 == a3 - b3)
		temp = true;
	EXPECT_TRUE(temp);
}
//Умножение полинома на числа -1 1 0
TEST(mult, test1)
{
	polynom a1("2x+3");
	bool temp = false;
	if (a1 == a1*1)
		temp = true;
	EXPECT_TRUE(temp);
}
TEST(mult, test2)
{
	polynom a1("2x+3");
	polynom a2("0");
	bool temp = false;
	if (a2 == a1 * 0)
		temp = true;
	EXPECT_TRUE(temp);
}
TEST(mult, test3)
{
	polynom a1("-6x^3");
	polynom b1("6x^3");
	bool temp = false;
	if (b1 == a1 * -1)
		temp = true;
	EXPECT_TRUE(temp);
}
//Умножение 2х полиномов
TEST(mult1, test1)
{
	bool temp = false;
	polynom a1("x^2+x");
	polynom b1("x");
	polynom c1("x^3+x^2");
	if (c1 == a1 * b1)
		temp = true;
	EXPECT_TRUE(temp);
}
TEST(mult1, test2)
{
	bool temp = false;
	polynom a2("0");
	polynom b2("0");
	polynom c2("0");
	temp = false;
	if (c2 == a2 * b2)
		temp = true;
	EXPECT_TRUE(temp);
}
TEST(mult1, test3)
{
	bool temp = false;
	polynom a1("x^2+x");
	polynom b1("0");
	polynom c1("0");
	if (c1 == a1 * b1)
		temp = true;
	EXPECT_TRUE(temp);
}
//Сложение с числом
TEST(plus1, test1)
{
	polynom a1("2x+3");
	polynom c1("2x+6");
	bool temp = false;
	if (c1 == a1 + 3)
		temp = true;
	EXPECT_TRUE(temp);
}
TEST(plus1, test2)
{
	bool temp = false;
	polynom a2("x");
	polynom c2("x+1");
	temp = false;
	if (c2 == a2 + 1)
		temp = true;
	EXPECT_TRUE(temp);
}
TEST(plus1, test3)
{
	bool temp = false;
	polynom a3("2x+3");
	polynom b3("2x^2+2x+3");
	polynom c3("2x^2+4x+6");
	temp = false;
	if (c3 == b3 + a3)
		temp = true;
	EXPECT_TRUE(temp);
}
//Вычитание с числом
TEST(minus1, test1)
{
	polynom a1("2x+3");
	polynom c1("2x+1");
	bool temp = false;
	if (c1 == a1 - 2)
		temp = true;
	EXPECT_TRUE(temp);
}
TEST(minus1, test2)
{
	bool temp = false;
	polynom a2("x");
	polynom c2("x-1");
	temp = false;
	if (c2 == a2 - 1)
		temp = true;
	EXPECT_TRUE(temp);
}
TEST(minus1, test3)
{
	bool temp = false;
	polynom a3("x^2+x");
	polynom c3("x^2+x-1");
	if (c3 == a3 - 1)
		temp = true;
	EXPECT_TRUE(temp);
}