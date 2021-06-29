//Problem: https://www.hackerrank.com/challenges/bitset-1/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;


constexpr unsigned exponent = 31;
constexpr unsigned twoToExp = 1u << exponent;

unsigned casePIsEven(unsigned n, unsigned s, unsigned p, unsigned q)
{
    if (p == 0)
    {
        if (s == q) 
        {
            return 1;
        }
        return 2;
    }
    if (s == 0 && q == 0) 
    {
        return 1;
    }
    unsigned a1minusa0 = (p - 1) * s + q;
    //unsigned numerator = exponent - __builtin_popcount((a1minusa0 & -a1minusa0) - 1);
    unsigned numerator = exponent - bitset<8>((a1minusa0 & -a1minusa0) - 1).count(); 
    unsigned denominator = bitset<8>((p & -p) - 1).count();
    unsigned m = numerator / denominator + ((numerator % denominator) == 0 ? 1 : 2);
    
    return min(m, n);
}

unsigned casePIsOdd(unsigned n, unsigned s, unsigned p, unsigned q)
{
    if (p ==1 )
    {
        return q == 0 ? 1 : min(n, twoToExp / (q & -q));
    }
    if ( s == 0 && q == 0)
    {
        return 1;
    }
    unsigned m = 1;
    unsigned long long pMinus1 = p - 1;
    unsigned long long a1Minusa0 = pMinus1 * s + q;
    unsigned long long pTom = p;
    unsigned long long mask = (twoToExp * (pMinus1 & - pMinus1) / 
        (a1Minusa0 & - a1Minusa0)) - 1;  
    while (m < n && (pTom & mask) != 1) 
    {
        pTom = pTom * pTom;;
        m += m;
    }
    
    return min(m, n);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */       
    unsigned n,
             s,
             p,
             q,
             distintNumsInSeq;
             
    cin >> n >> s >> p >> q;
    cout << ((p % 2) == 0 ? casePIsEven(n, s, p, q) : casePIsOdd(n, s, p, q)); 
    
    return 0;
}
