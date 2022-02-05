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
    int N, K; cin >> N >> K;
    vi a(N); rep(i, N) cin >> a[i];
    map<int, int> m;

    int r = 0, s = 0;
    int ans = 0;
    rep(l, N) {
        while(r < N && (s < K || (s == K && m[a[r]] != 0))) {
            m[a[r]]++;
            if(m[a[r]] == 1) s++;
            r++;
        }
        chmax(ans, r-l);

        m[a[l]]--;
        if(m[a[l]] == 0) s--;
    }
    cout << ans << endl;

    return 0;
}