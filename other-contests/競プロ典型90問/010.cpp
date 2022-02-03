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
    ll N; cin >> N;
    vl A(N, 0), B(N, 0);
    rep(i, N) {
        ll C, P; cin >> C >> P;
        C--;
        A[i] = !C * P;
        B[i] = C * P;
    }

    vl sum_A(N+1, 0), sum_B(N+1, 0);
    rep(i, N) {
        sum_A[i+1] += sum_A[i] + A[i];
        sum_B[i+1] += sum_B[i] + B[i];
    }

    ll Q; cin >> Q;
    vl L(Q), R(Q); 
    rep(i, Q) cin >> L[i] >> R[i];
    rep(i, Q) {
        cout << sum_A[R[i]] - sum_A[L[i]-1] << " " << sum_B[R[i]] - sum_B[L[i]-1] << endl;
    }

    return 0;
}