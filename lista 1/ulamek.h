#pragma once
#include <iostream>
class ulamek
{
public:
	int licznik;
	int mianownik;

	int wspMian(int a, int b);
	int NWD(int a, int b);

	ulamek();
	ulamek(int licznik, int mianownik = 1);
	~ulamek();

	ulamek operator+(ulamek b);
	ulamek operator-(ulamek b);
	ulamek operator*(ulamek b);
	ulamek operator/(ulamek b);

	friend std::ostream& operator<<(std::ostream& out, const ulamek& a);
	friend std::istream& operator>>(std::istream& in, const ulamek& a);

	ulamek operator-();
};

