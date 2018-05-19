

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include "gtest/gtest.h"
#include "../bracket_sequence/func.h"

	TEST(q_sort, test1)
	{
		vector<int> a(5,1);
		vector<int> x(5,1);
		std::sort(x.begin(),x.end());
		q_sort(a);
		EXPECT_EQ(a,x);
		a = { 0, 2, 3, 5, 4, 3 };
		x = a;
		std::sort(x.begin(), x.end());
		q_sort(a);
		EXPECT_EQ(a,x);
		a = { 123, 2, 3, 6, 4, 10 };
		x = a;
		std::sort(x.begin(), x.end());
		q_sort(a);
		EXPECT_EQ(a, x);
	}

	TEST(merge_sort, test1)
	{
		vector<int> a(5, 1);
		vector<int> x(5, 1);
		std::sort(x.begin(), x.end());
		q_sort(a);
		EXPECT_EQ(a, x);
		a = { 0, 2, 3, 5, 4, 3 };
		x = a;
		std::sort(x.begin(), x.end());
		q_sort(a);
		EXPECT_EQ(a, x);
		a = { 123, 2, 3, 6, 4, 10 };
		x = a;
		std::sort(x.begin(), x.end());
		q_sort(a);
		EXPECT_EQ(a, x);
	}

	
