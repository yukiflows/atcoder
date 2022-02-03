#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define all(v) (v).begin() (v).end()
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end())

#define rep(i, n)   for(int i = 0; i < (n); i++) 
#define reps(i, n)  for(int i = 1; i <= (n); i++)
#define rrep(i, n)  for(int i = (n)-1; i > 0; i--)
#define rreps(i, n) for(int i = (n); i >= 0; i--)

using namespace std;

using ll = long long;

using vi  = vector<int>;
using vl  = vector<long>;
using vll = vector<long long>;
using vs  = vector<string>;

using vvi  = vector<vector<int>>;
using vvl  = vector<vector<long>>;
using vvll = vector<vector<long long>>;

template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if(a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if(a < b) a = b; return compare;}

ll N, L, K;
vl A;

bool C(ll x) {
    ll count = 0; 
    ll prev = 0;
    reps(i, N+1) {
        if(A[i]-A[prev] >= x) count++, prev = i;
    }
    return count > K;
}

int main() {
    cin >> N >> L >> K;
    A.resize(N+2);
    A[0] = 0;
    reps(i, N) cin >> A[i];
    A[N+1] = L;

    ll l = 0, r = 1e9;
    while(r-l > 1) {
        ll m = (l+r) / 2;
        if(C(m)) l = m;
        else r = m;
    }

    cout << l << endl;

    return 0;
}