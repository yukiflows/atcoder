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
    vvi imos(1010, vi(1010, 0));
    rep(i, N) {
        int lx, ly, rx, ry; cin >> lx >> ly >> rx >> ry;
        imos[lx][ly]++;
        imos[lx][ry]--;
        imos[rx][ly]--;
        imos[rx][ry]++;
    }

    vvi sum(1010, vi(1010, 0));

    rep(i, 1005) {
        rep(j, 1005) {
            sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + imos[i][j];
        }
    }

    vi a(N+1, 0);
    rep(i, 1005) {
        rep(j, 1005) {
            a[sum[i][j]]++;
        }
    }

    reps(i, N) cout << a[i] << endl;

    return 0;
}