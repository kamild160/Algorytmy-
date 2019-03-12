#include "ulamek.h"
#include <string>


ulamek::ulamek()
{
	this->licznik = 1;
	this->mianownik = 1;
}

int ulamek::NWD(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;

	do
	{
		if (a > b) a -= b;
		else b -= a;
	} while (a != b);

	return a;
}

ulamek::ulamek(int licznik, int mianownik)
{
	if (!licznik || !mianownik)
		this->licznik = 0;
		this->mianownik = 0;

	int nwd = NWD(licznik, mianownik);

	this->licznik = licznik / nwd;
	this->mianownik = mianownik / nwd;
}

ulamek::~ulamek()
{
}

int ulamek::wspMian(int a, int b)
{
	int iloczyn = a * b;

	do
	{
		if (a > b) a -= b;
		else b -= a;
	} while (a != b);

	return iloczyn / a;
}

std::ostream& operator<<(std::ostream & out, const ulamek & a)
{
	return out << a.licznik << "/" << a.mianownik;
}

std::istream& operator>>(std::istream & in, const ulamek & a)
{
	std::string slash = "/";
	in >> a.licznik >> slash >> a.mianownik;
	return in;
}

ulamek ulamek::operator+(ulamek b)
{
	int oldA = this->mianownik;
	int oldB = b.mianownik;

	int nww = wspMian(this->mianownik, b.mianownik);

	double ratioA = nww / oldA;
	double ratioB = nww / oldB;

	return ulamek(((this->licznik*ratioA) + (b.licznik*ratioB)), nww);
}

ulamek ulamek::operator-(ulamek b)
{
	int oldA = this->mianownik;
	int oldB = b.mianownik;

	int nww = wspMian(this->mianownik, b.mianownik);

	double ratioA = nww / oldA;
	double ratioB = nww / oldB;

	return ulamek(((this->licznik*ratioA) - (b.licznik*ratioB)), nww);
}

ulamek ulamek::operator*(ulamek b)
{
	int newLicznik = this->licznik * b.licznik;
	int newMianownik = this->mianownik * b.mianownik;

	return ulamek(newLicznik, newMianownik);
}

ulamek ulamek::operator/(ulamek b)
{
	int newLicznik = this->licznik * b.mianownik;
	int newMianownik = this->mianownik * b.licznik;

	return ulamek(newLicznik, newMianownik);
}

ulamek ulamek::operator-()
{
	int newLicznik = this->licznik * - 1;

	return ulamek(newLicznik, this->mianownik);
}