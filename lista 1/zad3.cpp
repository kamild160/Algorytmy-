#include<iostream>
#include<cstdlib>
using namespace std;

int oblicz(double a[],int n, double x)
{
    int wynik = a[0];

    for(int i=1;i<=n;i++)
        wynik = wynik*x + a[i];

    return wynik;
}

int main()
{
    double *wspolczynniki;
    int stopien;
    double x;

    cout<<"Podaj stopień wielomianu: ";
    cin>>stopien;

    wspolczynniki = new double [stopien+1];

    //wwspółczynniki
    for(int i=0;i<=stopien;i++)
    {
        cout<<"Podaj współczynnik stojący przy potędze "<<stopien-i<<": ";
        cin>>wspolczynniki[i];
    }

    cout<<"Podaj x: ";
    cin>>x;

    cout<<"W( "<<x<<" ) = "<< oblicz(wspolczynniki,stopien,x)<<endl;



    return 0;
}