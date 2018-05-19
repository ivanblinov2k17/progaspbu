#pragma once
#include <iostream>
#include <stack>
#include <string>
#include "../../../googletest-master/googletest/include/gtest/gtest.h"
bool is_opening(char t);
bool is_closing(const char& t);
bool is_right_cons(std::string & s);