
#include "polynom.h"

void main()
{
	Polynom p("8x^2y+2xyz+9");
	Polynom p1("-3x^4+2x^2y-7");
	cout << p + p1 << endl;
}
