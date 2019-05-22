
    bool DoesPathExist(int n,const bool t[][5])
    {
        UnionFind obj(n*n); // tworzymy obiekt z ilością pól równą N*N.
        for(int i = 0; i < n; ++i) // pętla dla kolumn
            for(int j = 0; j < n; ++j) // pętla dla wierszy.
            {
                if(t[i][j]) // jesli pole istnieje 
                {
                    if(i+1 < n && t[i+1][j]) //down //  if-y sprawdzają czy w obrębie 1 są inne jedynki jesli tak scala je w wyspę.
                        obj.union(i*n+j,(i+1)*n+j);
                    if(i-1 >= 0 && t[i-1][j]) //up
                        obj.union(i*n+j,(i-1)*n+j);
                    if(j+1 < n && t[i][j+1]) //right
                        obj.union(i*n+j,i*n+j+1);
                 }
            }

        for(int i = 0; i < n; ++i)
            if(t[i][0]) // jeśli istnieje taki element
                for(int j = 0; j < n; ++j) // pętla po wierszach
                    if(t[j][n-1]) // jesli istenie taki element
                        if(obj.find(i*(n-1)) == obj.find(j*(n-1)+(n-1))) // sprawdza czy ścieżka istnieje jesli tak zwraca 1 
                            //(jeśli poczatkowy punkt ma tego samego reprezentanta co końcowy to zwróc 1 )
                            return 1;
        return 0;
    }

int main()
{
     const int n = 5;
        const bool t1[n][n] ={{1,1,1,1,1},
                              {0,1,0,0,1},
                              {0,0,1,0,1},
                              {0,0,0,0,1},
                              {1,0,1,0,1}};

        const bool t2[n][n] = {{1,1,0,0,0},
                               {1,0,0,0,1},
                               {1,1,0,0,0},
                               {0,1,0,1,0},
                               {1,1,1,1,1}};

        const bool t3[n][n] = {{0,1,1,0,0},
                               {0,0,1,0,1},
                               {0,1,1,0,0},
                               {0,0,1,1,0},
                               {1,1,0,1,1}};
    std::cout << DoesPathExist(n,t1) << std::endl;
    std::cout << DoesPathExist(n,t2) << std::endl;
    std::cout << DoesPathExist(n,t3) << std::endl;
}
