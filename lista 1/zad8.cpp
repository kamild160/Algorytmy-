#include "ulamek.h"
#include <iostream>

int main()
{
	ulamek a;
	ulamek b;

	std::cin >> a;
	std::cin >> b;

	ulamek plus = a + b;
	ulamek minus = a - b;
	ulamek mnoz = a * b;
	ulamek dziel = a / b;

	std::cout << a << " + " << b << " = " << plus;
	std::cout << a << " - " << b << " = " << minus;
	std::cout << a << " * " << b << " = " << mnoz;
	std::cout << a << " / " << b << " = " << dziel;

	getchar();
}
