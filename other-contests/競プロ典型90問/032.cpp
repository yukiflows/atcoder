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

int main() {
    int N; cin >> N;
    vvi A(N, vi(N)); rep(i, N) rep(j, N) cin >> A[i][j];
    int M; cin >> M;
    vvi B(N, vi(N, 0));
    rep(i, M) {
        int X, Y; cin >> X >> Y;
        X--; Y--;
        B[X][Y] = B[Y][X] = 1;
    }
    vi p(N); rep(i, N) p[i] = i;

    int ans = INF;
    do {
        int t = 0;
        bool ok = true;
        rep(i, N-1) if(B[p[i]][p[i+1]]) ok = false;
        if(!ok) continue;

        rep(i, N) t += A[p[i]][i];
        chmin(ans, t);

    } while (next_permutation(all(p)));
    
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}