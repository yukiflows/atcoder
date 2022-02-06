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
    ll K; cin >> K;
    vl divisor;
    for(ll i = 1; i*i <= K; i++) {
        if(K % i == 0) {
            divisor.pb(i);
            if(i != K/i) divisor.pb(K/i);
        }
    }
    sort(all(divisor));

    ll ans = 0;
    rep(i, (int)divisor.size()) {
        for(int j = i; j < (int)divisor.size(); j++) {
            if(K/divisor[i] < divisor[j]) continue;
            if(K %(divisor[i] * divisor[j]) != 0) continue;
            if(divisor[j] <= K / (divisor[i] * divisor[j])) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}