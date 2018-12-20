
#include "polynom.h"

void main()
{
	Polynom p("3x^5y^2z^5-5x^4y^3z^2+7x^3y^5z");
	Polynom p1("4x^3y^2z^6-6x^2yz^8");
	Polynom s = p + p1;
	cout << s.GetPol() << endl;
	system("pause");
}
