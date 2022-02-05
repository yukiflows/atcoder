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

int main() {
    ll N, Q; cin >> N >> Q;
    vl A(N); rep(i, N) cin >> A[i];
    vl B(N); rep(i, N-1) B[i] = A[i+1] - A[i];
    vl ans(Q);
    ll E =0;
    rep(i, N) E += abs(B[i]);
    rep(i, Q) {
        ll L, R, V; cin >> L >> R >> V;
        L--; R--;
        ll x = abs(B[L-1]) + abs(B[R]);
        if(L >= 1) B[L-1] += V;
        if(R < N-1) B[R] -= V;
        ll y = abs(B[L-1]) + abs(B[R]);
        E += y - x;
        ans[i] = E;
    }

    rep(i, Q) cout << ans[i] << endl;

    return 0;
}