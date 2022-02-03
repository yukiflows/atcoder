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
    int N; cin >> N;
    vs ans;
    rep(bits, 1 << N) {
        string s = "";
        rep(i, N) {
            if(bits >> i & 1) s.pb('(');
            else s.pb(')');
        }
        int nest = 0;
        bool ok = true;
        rep(i, N) {
            if(s[i] == '(') nest++;
            else nest--;
            if(nest < 0) ok = false;
        }
        if(nest != 0) ok = false;
        if(ok) ans.pb(s);
    }
    sort(all(ans));

    rep(i, (int)ans.size()) cout << ans[i] << endl;

    return 0;
}
