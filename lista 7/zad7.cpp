int countIslands(int n, const bool a[][5])
    {
        UnionFind obj(n*n); // tworzymy obiekt z ilością pól równą N*N (w naszym przypadku 25).
        for(int i = 0; i < n; ++i) // pętla dla kolumn
            for(int j = 0; j < n; ++j) // pętla dla wierszy.
            {
                if(!a[i][j]) // jeli nie ma takiego elementu. // if-y sprawdzają czy w obrębie 1 są inne jedynki jesli tak scala je w wyspę.
                    continue;
                if(i+1 < n && a[i+1][j])
                    obj.make_union(i*n+j,(i+1)*n+j);
                if(i-1 >= 0 && a[i-1][j])
                    obj.make_union(i*n+j,(i-1)*n+j);
                if(j-1 >= 0 && a[i][j-1])
                    obj.make_union(i*n+j,i*n+j-1);
                if(j+1 < n && a[i][j+1])
                    obj.make_union(i*n+j,i*n+j+1); 
            }
        bool temp[n*n] = {0}; // kontener przetrzymujący zliczone wyspe
        int numberOfIslands = 0; // licznik wysp.
        for(int i = 0; i < n; ++i) // petla po kolumnach
            for(int j = 0; j < n; ++j) //pętla po wierszach
                if(a[i][j]) 
                {
                    int x = obj.find(i*n+j); // znajdz korzeń i zrób korzeń parentem i  // reprezentant 
                    if(!temp[x]) // jeśli wyspy nie ma w kontenerze temp
                    {
                        ++numberOfIslands; // zwieksz licznik
                        temp[x] = 1; // dodaj do reprezentanta do  kontenera
                    }
                        
                }  
        return numberOfIslands;
    }

int main()
{
    const int n = 5;
    bool t[n][n] = {{1,1,0,0,0},
                    {0,1,0,0,0},
                    {0,0,1,0,0},
                    {0,0,0,1,0},
                    {1,0,1,0,1}};
    std::cout << countIslands(n,t) << std::endl;
}