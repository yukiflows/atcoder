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

int main() {
    ll H, W; cin >> H >> W;
    vvl A(H, vl(W));
    rep(i, H) rep(j, W) cin >> A[i][j];
    vl sum_row(H, 0), sum_col(W, 0);

    rep(i, H) {
        ll sum = 0;
        rep(j, W) sum += A[i][j];
        sum_row[i] = sum;
    }
    rep(j, W) {
        ll sum = 0;
        rep(i, H) sum += A[i][j];
        sum_col[j] = sum;
    }

    rep(i, H) {
        rep(j, W) cout << sum_row[i] + sum_col[j] - A[i][j] << " ";
        cout << endl;
    }

    return 0;
}