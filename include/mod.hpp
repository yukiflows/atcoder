#include <bits/stdc++.h>
using namespace std;

long long modpow(long long a, long long x, long long mod) {
    long long ret = 1;
    long long p = a;
    while(x > 0) {
        if(x & 1) ret *= p;
        p *= p;
        ret %= mod;
        p %= mod;
    }
    return ret;
}

long long modinv(long long a, long long mod) {
    return modpow(a, mod-2)
}