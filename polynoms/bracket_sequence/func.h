#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class polynom
{
private:
	vector <int> a;
	int n;
public:
	polynom()
	{
		n = 0;
	}
	polynom(string s)
	{
		if (s == "0")
		{
			n = 0;
			a.push_back(0);
		}
		int i = 0;
		int temp = 0;
		int temp2 = 0;
		int tempL = 1;
		size_t o;
		while ((o = s.find(' ')) != std::string::npos)
			s.erase(o, 1);

		while (s.find(' ') >= 0 && s.find(' ') <= s.length())
			s.erase(s.find(' '));
		while (i < s.length())
		{

			if (s[i] == '+')
			{
				tempL = 1;
				i++;
			}
			if (s[i] == '-')
			{
				tempL = -1;
				i++;
			}
			if (s[i] >= '0'&&s[i] <= '9')
			{
				while (s[i] >= '0'&&s[i] <= '9')
				{
					temp = temp * 10 + s[i] - 48;
					i++;
				}
				temp = tempL*temp;
			}

			if (i < s.length())
			{
				if (s.length() - i == 1 && s[i] == 'x')
				{
					temp2 = 1;
					i++;
				}

				else
					if (s[i] == 'x'&&s[i + 1] == '^')
					{
						i += 2;
						if (s[i] >= '0'&&s[i] <= '9')
						{
							while (s[i] >= '0'&&s[i] <= '9')
							{
								temp2 = temp2 * 10 + s[i] - 48;
								i++;
							}
						}
					}
					else
						if (s[i] == 'x'&&s[i + 1] != '^')
						{
							temp2 = 1;
							i++;
						}

				while (temp2 >= n)
				{
					a.push_back(0);
					n++;
				}

				a[temp2] = temp;
				temp = 0; temp2 = 0;

			}

			if (i == s.length())
			{
				a[0] = temp;
			}
		}
	}
	friend ostream& operator<<(ostream& os, const polynom & _a);
	friend istream& operator >> (istream& is, polynom & A);
	
	const polynom operator+(const polynom &_a)
	{
		if (this->n == 0 && _a.n == 0)
			return polynom("0");
		polynom A;
		A.n = max(this->n, _a.n);
		for (int i = 0; i < A.n; i++)
		{
			if (_a.n - 1 < i)
				A.a.push_back(this->a[i]);
			else
				if (this->n - 1 < i)
					A.a.push_back(_a.a[i]);
				else
					A.a.push_back(this->a[i] + _a.a[i]);
		}
		return A;
	}
	const polynom operator+(const int &_a)
	{
		polynom A;
		A.n = this->n;
		for (int i = 0; i < A.n; i++)
		{
			A.a.push_back(this->a[i]);
		}
		A.a[0] += _a;
		return A;
	}
	const polynom operator-(const polynom &_a)
	{
		polynom A;
		A.n = max(this->n, _a.n);
		for (int i = 0; i < A.n; i++)
		{
			if (_a.n - 1 < i)
				A.a.push_back(this->a[i]);
			else
				if (this->n - 1 < i)
					A.a.push_back((-1)*_a.a[i]);
				else
					A.a.push_back(this->a[i] - _a.a[i]);
		}
		int temp = 0;
		int j = 0;
		if (A.n>1)
			while (A.a[A.n - j - 1] == 0 && j < A.n)
			{
				temp++;
				j++;
			}
		A.n-=temp;
		return A;
	}
	const polynom operator-(const int &_a)
	{
		polynom A;
		A.n = this->n;
		for (int i = 0; i < A.n; i++)
		{
			A.a.push_back(this->a[i]);
		}
		A.a[0] -= _a;
		return A;
	}
	const polynom operator*(const polynom &_a)
	{
		polynom RES, TEMP;
		if (this->n == 0 || _a.n == 0)
			return polynom("0");
		int temp = 0;
		vector <int>::iterator it;
		for (int temp = 0; temp < this->n; temp++)
		{
			TEMP = _a;
			for (int i = 0; i < TEMP.n; i++)
			{
				TEMP.a[i] *= this->a[temp];
			}
			for (int i = 0; i < temp; i++)
			{
				it = TEMP.a.begin();
				TEMP.a.insert(it, 0);
			}
			TEMP.n += temp;
			RES = RES + TEMP;
		}
		return RES;

	}
	const polynom operator*(const int &_a)
	{
		polynom A;
		A.n = this->n;
		for (int i = 0; i < A.n; i++)
		{
			A.a.push_back(this->a[i] * _a);
		}
		if (_a == 0)
		{
			A.a.push_back(0);
			A.n = 0;
		}
		return A;
	}
	polynom& operator=(const polynom & _a)
	{
		if (n < _a.n)
		{
			for (int i = 0; i < n; i++)
			{
				a[i] = _a.a[i];
			}
			for (int i = n; i < _a.n; i++)
			{
				a.push_back(_a.a[i]);
			}
		}
		if (n == _a.n)
		{
			for (int i = 0; i < _a.n; i++)
			{
				a[i] = _a.a[i];
			}
		}
		if (n > _a.n)
		{
			for (int i = 0; i < _a.n; i++)
			{
				a[i] = _a.a[i];
			}
			for (int i = _a.n; i < n; i++)
			{
				a.pop_back();
			}
		}
		n = _a.n;
		return *this;
	}
	const bool operator==(const polynom &_a)
	{
		if (this->n == 0 && _a.n == 0)
			return true;
		if (this->n != _a.n)
			return false;
		for (size_t i = 0; i < _a.n; i++)
		{
			if (this->a[i] != _a.a[i])
				return false;
		}
		return true;
	}
	int nn()
	{
		return this->n;
	}
};

ostream& operator<<(ostream& os, const polynom & _a)
{
	for (int i = _a.n - 1; i >= 0; i--)
	{
		if (_a.a[i] != 0)
		{
			if (i == 1)
				os << _a.a[i] << "x + ";
			else
				if (i == 0)
					os << _a.a[i];
				else
					os << _a.a[i] << "x^" << i << " + ";
		}

	}
	if (_a.a[0] == 0)
		os << 0;
	os << endl;
	return os;
}
istream& operator >> (istream& is, polynom  & A)
{
	string s;
	is >> s;
	polynom * _aa = new polynom(s);
	A = *_aa;
	return is;
}