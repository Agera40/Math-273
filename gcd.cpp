#include "gcd.hpp"

int gcd(int m, int n)
{
    if (m == n) return m;
    if (m > n) {
        m = m - n;
    }
    else {
        n = n - m;
    }
    return gcd(m, n);
}

int gcd_modulus(int m, int n)
{
    if (m == 0) return n;
    if (n == 0) return m;
    if (m > n) m %= n;
    else n %= m; return gcd_modulus(m, n);
}
