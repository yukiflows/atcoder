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
    int N, Q; cin >> N >> Q;
    vi A(N); rep(i, N) cin >> A[i];
    int c = 0;
    vi ans;
    rep(i, Q) {
        int T, x, y; cin >> T >> x >> y;
        x--; y--;
        x = (x-c+N) % N;
        y = (y-c+N) % N;
        if(T == 1) {
            swap(A[x], A[y]);
        } else if(T == 2) {
            c++;
            c %= N;
        } else {
            ans.pb(A[x]);
        }
    }

    rep(i, (int)ans.size()) cout << ans[i] << endl;

    return 0;
}