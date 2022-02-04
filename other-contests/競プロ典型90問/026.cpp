#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define all(v)  (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
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

int N;
vvi G;
vi depth;

void dfs(int n) {
    for(int next: G[n]) {
        if(chmin(depth[next], depth[n]+1)) dfs(next);
    }
}

int main() {
    cin >> N;
    G.resize(N);
    depth = vi(N, INF);
    rep(i, N-1) {
        int A, B; cin >> A >> B;
        A--; B--;
        G[A].pb(B);
        G[B].pb(A);
    }
    depth[0] = 0;
    dfs(0);
    vi A, B;
    rep(i, N) {
        if(depth[i] % 2 == 0) A.pb(i+1);
        else B.pb(i+1);
    }

    if(A.size() >= N/2) {
        rep(i, N/2) cout << A[i] << " ";
        cout << endl;
    } else {
        rep(i, N/2) cout << B[i] << " ";
        cout << endl;
    }

    return 0;
}