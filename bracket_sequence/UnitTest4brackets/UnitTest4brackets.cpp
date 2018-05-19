

#include <iostream>
#include <stack>
#include <string>
#include "gtest/gtest.h"
#include "../bracket_sequence/func.h"
#include "../bracket_sequence/func.cpp"

	TEST(is_opening, test1)
	{
		EXPECT_FALSE(is_opening(' '));
		EXPECT_FALSE(is_opening('}'));
		EXPECT_FALSE(is_opening('3'));
	}

	TEST(is_openingTest, Positive)
	{
		EXPECT_TRUE(is_opening('('));
		EXPECT_TRUE(is_opening('{'));
		EXPECT_TRUE(is_opening('['));
		EXPECT_TRUE(is_opening('<'));
	}
	TEST(is_closingTest, Negative)
	{
		EXPECT_FALSE(is_closing(' '));
		EXPECT_FALSE(is_closing('{'));
		EXPECT_FALSE(is_closing('3'));
	}
	TEST(is_closingTest, Positive)
	{
		EXPECT_TRUE(is_closing(')'));
		EXPECT_TRUE(is_closing('}'));
		EXPECT_TRUE(is_closing(']'));
		EXPECT_TRUE(is_closing('>'));
	}
	TEST(is_right_consTest, Negative)
	{
		std::string s;
		s = "(";
		EXPECT_FALSE(is_right_cons(s));
		s = "((()))((";
		EXPECT_FALSE(is_right_cons(s));
		s = ")<>";
		EXPECT_FALSE(is_right_cons(s));
	}
	TEST(is_right_consTest, Positive)
	{
		std::string s;
		s = "{}";
		EXPECT_TRUE(is_right_cons(s));
		s = "((()))";
		EXPECT_TRUE(is_right_cons(s));
		s = "((()))<><[]>";
		EXPECT_TRUE(is_right_cons(s));
	}
