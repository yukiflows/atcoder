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

const long long INF  = 1e9+7;
const long long INFL = 1e18;
const long long MOD  = 1e9+7;

template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if(a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if(a < b) a = b; return compare;}

int main() {
    ll N; cin >> N;
    vl A(N); rep(i, N) cin >> A[i];
    A.pb(-INFL);
    A.pb(INFL);
    sort(all(A));
    ll Q; cin >> Q;
    vl B(Q); rep(i, Q) cin >> B[i];
    rep(i, Q) {
        int j = lower_bound(all(A), B[i]) - A.begin();
        cout << min(A[j]-B[i], B[i]-A[j-1]) << endl;
    }

    return 0;
}