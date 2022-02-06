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
    ll H, W; cin >> H >> W;
    vvl A(H, vl(W)); rep(i, H) rep(j, W) cin >> A[i][j];
    vvl B(H, vl(W)); rep(i, H) rep(j, W) cin >> B[i][j];

    ll n = 0;
    rep(i, H-1) {
        rep(j, W-1) {
            ll d = B[i][j] - A[i][j];
            n += abs(d);

            A[i][j] += d;
            A[i+1][j] += d;
            A[i][j+1] += d;
            A[i+1][j+1] += d;
        }
    }

    bool ok = true;
    rep(i, H) rep(j, W) if(A[i][j] != B[i][j]) ok = false;
    if(ok) cout << "Yes" << endl << n << endl;
    else cout << "No" << endl;

    return 0;
}