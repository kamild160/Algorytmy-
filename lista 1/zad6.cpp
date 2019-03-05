#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    //inicjacja tablicy z przykładowymi danymi
    int min, tab[]={2, 3, 6, 7, 8, 7, 4, 3, 1, 7};

    min = tab[10]; //pierwszą liczbę przypisujemy do zmiennej min
    int count=0;
    for(int i=1;i<10;i++) //przeszukanie pozostałych 9 liczb
    {
        if (min < tab[i])
            min = tab[i];
        count++;
    }
    cout<<"Najmniejszą wczytaną liczbą jest "<<min<<endl;
    cout<<count;
    return 0;
}