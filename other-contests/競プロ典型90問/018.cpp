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
    double T, L, X, Y; cin >> T >> L >> X >> Y;
    int Q; cin >> Q;
    vector<double> ans;
    rep(i, Q) {
        double E; cin >> E;
        double y = -L/2*sin(E / T * 2 * acos(-1));
        double z = -L/2*cos(E / T * 2 * acos(-1)) + L/2;
        double r = sqrt(X*X + (Y-y)*(Y-y));
        double t = atan(z/r) * 180 / acos(-1);
        ans.pb(t);
    }
    cout << setprecision(10);
    rep(i, Q) cout << ans[i] << endl;

    return 0;
}