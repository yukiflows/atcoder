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
#define rrep(i, n)  for(int i = (n)-1; i >= 0; i--)
#define rreps(i, n) for(int i = (n); i > 0; i--)

using namespace std;

using ll = long long;

using pi = pair<int, int>;
using pl = pair<long long, long long>;

using vi = vector<int>;
using vl = vector<long long>;
using vs = vector<string>;
using vb = vector<bool>;

using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;

using vvvi = vector<vector<vector<int>>>;
using vvvl = vector<vector<vector<long long>>>;

const long long INF = 1e9+7;
const long long MOD = 1e9+7;

template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if(a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if(a < b) a = b; return compare;}

bool judge(ll a, ll s) {
    bool exist = true;
    bool up = false;
    rep(i, 60) {
        ll b1 = (a >> i) & 1;
        ll b2 = (s >> i) & 1;

        if(b1 == 0) {
            if(up && b2 == 1) up = false;
        } else {
            if(!up && b2 == 1) exist = false;
            if(up && b2 == 0) exist = false;
            if(!up && b2 == 0) up = true;
        }
    }
    if(up) exist = false;

    return exist;
}

int main() {
    int T; cin >> T;
    vs ans;
    rep(i, T) {
        ll a, s; cin >> a >> s;
        if(judge(a, s)) ans.pb("Yes");
        else ans.pb("No");
    }
    rep(i, T) cout << ans[i] << endl;
    return 0;
}