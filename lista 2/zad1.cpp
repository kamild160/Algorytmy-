#include<iostream>

using namespace std;

int main() {

    int tablica[6] = {1, 2, 3, 4, 5, 6};
    int liczba = 20;
    int n = 6;
    int s;
    int l = 0;
    int p = n - 1;
    while (true) {
        if (l > p) {
            cout << "Błąd, nie ma takiej liczby " << endl;
            break;
        }
        s = (l + p) / 2;

        if (tablica[s] == liczba) {
            cout << "Odnaleziono liczbe " << liczba << " w tabeli  " <<endl;
            break;

        } else if (tablica[s] < liczba)
            l = s + 1;
        else
            p = s - 1;
    }
    return 0;
}