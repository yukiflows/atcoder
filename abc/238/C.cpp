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
#define rrep(i, n)  for(int i = (n)-1; i >= 0; i--)
#define rreps(i, n) for(int i = (n); i > 0; i--)

using namespace std;

using ll = long long;

using pi = pair<int, int>;
using pl = pair<long long, long long>;

using vi = vector<int>;
using vl = vector<long long>;
using vs = vector<string>;
using vb = vector<bool>;

using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;

using vvvi = vector<vector<vector<int>>>;
using vvvl = vector<vector<vector<long long>>>;

const long long INF = 1e9+7;
// const long long MOD = 1e9+7;
const long long MOD = 998244353;

template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if(a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if(a < b) a = b; return compare;}

long long modpow(long long a, long long x, long long mod) {
    long long ret = 1;
    long long p = a;
    while(x > 0) {
        if(x & 1) ret *= p;
        p *= p;
        x >>= 1;
        ret %= mod;
        p %= mod;
    }
    return ret;
}

long long modinv(long long a, long long mod) {
    return modpow(a, mod-2, mod);
}

int main() {
    ll N; cin >> N;

    ll l = 1, r = 1;
    ll ans = 0;
    while(r < N+1) {
        r = min(r*10, N+1);
        ll n = r-l;
        ans += (n % MOD) * ((n+1) % MOD) % MOD * modinv(2, MOD) % MOD;
        ans %= MOD;
        if(r == N+1) break;
        l *= 10;
    }
    cout << ans << endl;

    return 0;
}