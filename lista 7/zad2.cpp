#include <bits/stdc++.h>      
using namespace std; 
  

unsigned int f(unsigned int n) 
{ 
unsigned int count = 0; 
while (n) 
{ 
    count += n & 1; 
    n >>= 1; 
} 
return count; 
} 
  

int main() 
{ 
    int i = 11; 
    cout << countSetBits(i); 
    return 0; 
} 
