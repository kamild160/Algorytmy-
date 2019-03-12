#include <iostream>

int potegaRec(int x, int n)
{
	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return x;
	}
	else if (n % 2)
	{
		int temp = potegaRec(x, n / 2);
		return temp * temp;
	}
	else
	{
		return x * potegaRec(x, n-1);
	}
}

int potegaIt(int x, int n)
{
	int wynik = 1;
	while (n > 0)
	{
		if (n % 2 != 0)
		{
			wynik = x * wynik;
		}
		n = n / 2;
		x = x * x;
	}
	return wynik;
}
