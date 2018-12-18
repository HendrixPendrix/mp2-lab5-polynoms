#pragma once

#include "list.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Monom
{
	int coef;
	int pow;
public:
	int GetCoef()
	{
		return coef;
	}
	int GetPow()
	{
		return pow;
	}
	Monom(int _coef = 0, int _pow = 0)
	{
		coef = _coef;
		pow = _pow;
	}
	Monom& operator=(const Monom &tmp)
	{
		coef = tmp.coef;
		pow = tmp.pow;
		return *this;
	}
	bool operator==(const Monom &tmp)
	{
		if ((coef == tmp.coef) && (pow == tmp.pow))
			return true;
		else return false;
	}
	bool IsIdentPow(Monom tmp)
	{
		if (GetPow() == tmp.GetPow())
			return true;
		else return false;
	}
	Monom operator+(const Monom &tmp)
	{
		if (pow != tmp.pow)
			throw "error";
		Monom q;
		q.coef = coef + tmp.coef;
		q.pow = pow;
		return q;
	}
	Monom operator-(const Monom &tmp)
	{
		Monom q;
		if (pow != tmp.pow)
			throw "error";
		q.coef = coef - tmp.coef;
		q.pow = pow;
		return q;
	}

	friend ostream& operator<<(ostream& os, const Monom& tmp);
};
ostream& operator<<(ostream& os, Monom& tmp)
{
	os << tmp.GetCoef();
	os << "X^" << (tmp.GetPow() / 100);
	os << "Y^" << (tmp.GetPow() % 100 / 10);
	os << "Z^" << (tmp.GetPow() % 10);
	return os;
}
class Polynom
{
private:
	string polynom;
	List <Monom> pol;
public:
	Polynom(string _pol = "")
	{
		polynom = _pol;
		if (polynom != "")
			FillPolynom();
	}
	~Polynom()
	{
		pol.Clear();
	}
	bool IsOperation(char p)
	{
		if (p == '+' || p == '-')
			return true;
		else return false;
	}
	bool IsOperand(char op)
	{
		if (op == 'x' || op == 'y' || op == 'z')
			return true;
		else return false;
	}
	int Const(string q)
	{
		if (q.empty())
			return 1;
		if (q.size() == 1)
		{
			if (q[0] == '+')
				return 1;
			else if (q[0] == '-')
			{
				return -1;
			}
		}
		return atoi(q.c_str());
	}
	void FillPolynom()
	{
		vector<string> strpol;
		int i = 0;
		do
		{
			string tmp;
			do
			{
				tmp += polynom[i];
				i++;
			} while (!IsOperation(polynom[i]) && i != polynom.size());

			strpol.push_back(tmp);
		} while (i < polynom.size());
		for (int i = 0; i < strpol.size(); i++)
		{
			string tmp;
			int j = 0;
			while (IsOperand(strpol[i][j]) == false && j != strpol[i].size())
			{
				tmp += strpol[i][j];
				j++;
			}
			if (j != strpol[i].size())
			{
				int _pow = 0;
				for (j; j < strpol[i].size(); j++)
				{
					if (strpol[i][j] == 'z')
					{
						if (j + 1 == strpol[i].size() || strpol[i][j + 1] != '^')
							_pow++;
						else
						{
							j = j + 2;
							_pow += strpol[i][j] - '0';
						}
					}
					else if (strpol[i][j] == 'y')
					{
						if (j + 1 == strpol[i].size() || strpol[i][j + 1] != '^')
							_pow += 10;
						else
						{
							j = j + 2;
							_pow += strpol[i][j] - '0' * 10;
						}
					}
					else if (strpol[i][j] == 'x')
					{
						if (j + 1 == strpol[i].size() || strpol[i][j + 1] != '^')
						{
							_pow += 100;
						}
						else
						{
							j = j + 2;
							_pow += (int)(strpol[i][j] - '0') * 100;
						}
					}
				}
				Monom s(Const(tmp), _pow);
				pol.PushBack(s);
			}
			else
			{
				Monom s(Const(tmp), 0);
				pol.PushBack(s);
			}
		}

	}
	Polynom operator+(Polynom &tmp)
	{
		Polynom q;
		int size;
		if (pol.GetCount() >= tmp.pol.GetCount())
			size = pol.GetCount();
		else size = tmp.pol.GetCount();
		for (int i = 0; i < size; i++)
		{
			if (pol[i].GetPow() == tmp.pol[i].GetPow())
				if (pol[i] + tmp.pol[i] == 0)
					continue;
			q.pol.PushBack(pol[i] + tmp.pol[i]);
		}
		return q;
	}
	Polynom operator-(Polynom &tmp)
	{
		Polynom q;
		int size;
		if (pol.GetCount() >= tmp.pol.GetCount())
			size = pol.GetCount();
		else size = tmp.pol.GetCount();
		for (int i = 0; i < size; i++)
			if (pol[i].GetPow() == tmp.pol[i].GetPow())
				q.pol.PushBack(pol[i] - tmp.pol[i]);
		return q;
	}
	Polynom& operator=(Polynom &p)
	{
		pol=p.pol;
		polynom = p.polynom;
		return *this;
	}
	friend ostream& operator<<(ostream& os, Polynom& tmp);
};
ostream& operator<<(ostream& os, Polynom& tmp)
{
	for (int i = 0; i < tmp.pol.GetCount(); i++)
	{
		os << tmp.pol[i];
	}
	return os;
}
