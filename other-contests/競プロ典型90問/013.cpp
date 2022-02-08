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

struct Edge {
    int to;
    ll cost;
};

int main() {
    ll N, M; cin >> N >> M;
    vector<vector<Edge>> G(N);
    rep(i, M) {
        int a, b; cin >> a >> b;
        a--; b--;
        ll c; cin >> c;
        G[a].pb(Edge{b, c});
        G[b].pb(Edge{a, c});
    }

    vl dist_from_0(N, INF); dist_from_0[0] = 0;
    vl dist_from_N_1(N, INF); dist_from_N_1[N-1] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push(mp(0, 0));
    while(!pq.empty()) {
        pair<ll, int> p = pq.top(); pq.pop();
        int to; ll d;
        tie(d, to) = p;
        if(d > dist_from_0[to]) continue;
        for(Edge e: G[to]) {
            if(chmin(dist_from_0[e.to], d+e.cost)) pq.push(mp(dist_from_0[e.to], e.to));
        }
    }

    pq.push(mp(0, N-1));
    while(!pq.empty()) {
        pair<ll, int> p = pq.top(); pq.pop();
        int to; ll d;
        tie(d, to) = p;
        if(d > dist_from_N_1[to]) continue;
        for(Edge e: G[to]) {
            if(chmin(dist_from_N_1[e.to], d+e.cost)) pq.push(mp(dist_from_N_1[e.to], e.to));
        }
    }

    rep(k, N) {
        cout << dist_from_0[k] + dist_from_N_1[k] << endl;
    }

    return 0;
}