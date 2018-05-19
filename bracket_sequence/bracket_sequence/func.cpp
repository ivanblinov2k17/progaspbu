#include "func.h"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool is_right_cons(std::string & s)
{
	stack <char> temp;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (is_opening(s[i]))
		{
			temp.push(s[i]);
		}
		if (is_closing(s[i]))
		{
			if (!temp.empty() && is_opening(temp.top()))
			{
				temp.pop();
			}
			else
			{
				return false;
				break;
			}
		}
	}
	if (temp.empty())
		return true;
	else
		return false;
}
bool is_opening(char t)
{
	if (t == '(' || t == '{' || t == '[' || t == '<')
		return true;
	else
		return false;
}

bool is_closing(char t)
{
	if (t == ')' || t == '}' || t == ']' || t == '>')
		return true;
	else
		return false;
}