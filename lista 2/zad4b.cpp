#include <iostream>
using namespace std;
void odwrocpom(int *tab, int pocz, int kon)
{
    int tmp;

    while(pocz < kon) {
        tmp = tab[pocz];
        tab[pocz] = tab[kon];
        tab[kon] = tmp;
        pocz++;
        kon--;
    }
}


void przesun(int *tab, int n, int k)
{
   //1
    odwrocpom(tab, 0, n-1);
    //3
    odwrocpom(tab, 0, k-1);
    odwrocpom(tab, k, n-1);


}


