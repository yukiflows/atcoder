#include <bits/stdc++.h>

#define pb push_back
#define pf push_front
#define mp make_pair
#define mt make_tuple

#define all(v)  (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define unique(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

#define rep(i, n)   for(int i = 0; i < (n); i++) 
#define reps(i, n)  for(int i = 1; i <= (n); i++)
#define rrep(i, n)  for(int i = (n)-1; i > 0; i--)
#define rreps(i, n) for(int i = (n); i >= 0; i--)

using namespace std;

using ll = long long;
using ull = unsigned long long;

using pi  = pair<int, int>;
using pl  = pair<long long, long long>;

using vi  = vector<int>;
using vl  = vector<long long>;
using vs  = vector<string>;

using vvi  = vector<vector<int>>;
using vvl  = vector<vector<long long>>;

using vvvi = vector<vector<vector<int>>>;
using vvvl = vector<vector<vector<long long>>>;

const long long INF = 1e9+7;
const long long MOD = 1e9+7;

template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if(a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if(a < b) a = b; return compare;}

ll modpow(ll a, ll x) {
    ll ret = 1;
    ll p = a;
    while(x > 0) {
        if(x & 1) ret *= p;
        p = p*p;
        ret %= MOD;
        p %= MOD;
        x >>= 1;
    }
    return ret;
}

ll modinv(ll a) {
    return modpow(a, MOD-2);
}

int main() {
    ull L, R; cin >> L >> R;
    ull a = 1;
    ull ans = 0;
    while(a <= R) {
        ull left = max(a, L);
        ull right = R;
        ull n = right - left + 1;
        ull s = ((n % MOD) * (left % MOD) % MOD) + (((n % MOD) * ((n-1) % MOD) % MOD) * modinv(2)) % MOD; 
        s %= MOD;
        ans += s;
        ans %= MOD;
        a *= 10;
    }
    cout << ans << endl;

    return 0;
}