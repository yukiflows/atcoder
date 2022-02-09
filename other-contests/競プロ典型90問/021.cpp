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
using vb  = vector<bool>;

using vvi  = vector<vector<int>>;
using vvl  = vector<vector<long long>>;

using vvvi = vector<vector<vector<int>>>;
using vvvl = vector<vector<vector<long long>>>;

const long long INF = 1e9+7;
const long long MOD = 1e9+7;

template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if(a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if(a < b) a = b; return compare;}

int N, M;

vvi Graph;
vvi rGraph;

vi order;
vb visited;

vi rorder;
vb rvisited;

int counter;

void dfs(int n, const vvi &graph, vi &order, vb &visited) {
    visited[n] = true;
    for(int next: graph[n]) {
        if(!visited[next]) dfs(next, graph, order, visited);
    }
    order[n] = counter++;
}

void rdfs(int n, const vvi &graph, vi &order, vb &visited) {
    visited[n] = true;
    order[n] = counter;
    for(int next: graph[n]) {
        if(!visited[next]) rdfs(next, graph, order, visited);
    }
}

int main() {
    cin >> N >> M;
    Graph.resize(N);
    rGraph.resize(N);
    rep(i, M) {
        int A, B; cin >> A >> B;
        A--; B--;
        Graph[A].pb(B);
        rGraph[B].pb(A);
    }

    order = vi(N, -1);
    visited = vb(N, false);
    counter = 0;
    rep(i, N) if(!visited[i]) dfs(i, Graph, order, visited);

    rorder = vi(N, -1);
    rvisited = vb(N, false);
    counter = 0;
    vector<pi> p(N);
    rep(i, N) p[i] = mp(order[i], i);
    sort(rall(p));
    rep(i, N) {
        int n = p[i].second;
        if(!rvisited[n]) {
            rdfs(n, rGraph, rorder, rvisited);
            counter++;
        }
    }

    map<int, ll> m;
    rep(i, N) m[rorder[i]]++;

    ll ans = 0;
    for(auto itr = m.begin(); itr != m.end(); itr++) {
        ll n = itr->second;
        ans += n * (n-1) / 2;
    }
    cout << ans << endl;

    return 0;
}