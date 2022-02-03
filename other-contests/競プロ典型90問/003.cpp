#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define unique(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

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

const long long INF = 1e9+7;
const long long MOD = 1e9+7;

template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if(a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if(a < b) a = b; return compare;}

ll N;
vvl G;
vl d;

void dfs(ll n) {
    for(ll next:G[n]) {
        if(chmin(d[next], d[n]+1)) dfs(next);
    }
}

int main() {
    cin >> N;
    G.resize(N);
    rep(i, N-1) {
        ll A, B; cin >> A >> B;
        A--; B--;
        G[A].pb(B);
        G[B].pb(A);
    }
    d = vl(N, INF);
    d[0] = 0;
    dfs(0);
    ll n = 0;
    rep(i, N) if(d[i] > d[n]) n = i;
    rep(i, N) d[i] = INF;
    d[n] = 0;
    dfs(n);
    cout << *max_element(all(d)) + 1 << endl;

    return 0;
}