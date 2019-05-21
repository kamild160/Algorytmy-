
    size_t countIslands(const size_t& n, const bool a[][5])
    {
        UnionFind obj(n*n);
        for(size_t i = 0; i < n; ++i)
            for(size_t j = 0; j < n; ++j)
            {
                if(!a[i][j])
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
        bool temp[n] = {0};
        size_t numberOfIslands = 0;
        for(size_t i = 0; i < n; ++i)
            for(size_t j = 0; j < n; ++j)
                if(a[i][j])
                {
                    size_t x = obj.find(i*n+j);
                    if(!temp[x]++)
                        ++numberOfIslands;
                }  
        return numberOfIslands;
    }
}
int main()
{
    /* 0 - sea, 1 - island */
    constexpr size_t n = 5;
    bool t[n][n] = {{1,1,0,0,0},
                    {0,1,0,0,1},
                    {0,0,1,0,0},
                    {0,0,0,0,0},
                    {1,0,1,0,1}};
    std::cout << ASD::countIslands(n,t) << std::endl;
}
