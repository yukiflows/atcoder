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

int H, W;
vs c;

int dh[] = {-1, 0, 1, 0};
int dw[] = {0, 1, 0, -1};

vvi dist;
vector<vector<bool>> visited;

void dfs(int h, int w, int d) {
    d++;  
    rep(i, 4) {
        int nh = h + dh[i];
        int nw = w + dw[i];
        if(0 <= nh && nh < H && 0 <= nw && nw < W && c[nh][nw] == '.' && !visited[nh][nw]) {
            chmax(dist[nh][nw], d);
            visited[nh][nw] = true;
            dfs(nh, nw, d);
            visited[nh][nw] = false;
        }
    }
    d--;
}

int main() {
    cin >> H >> W;
    c.resize(H); rep(i, H) cin >> c[i];

    int ans = -1;
    rep(sh, H) {
        rep(sw, W) {
            dist = vvi(H, vi(W, 0));
            visited = vector<vector<bool>>(H, vector<bool>(W, false));
            if(c[sh][sw] == '#') continue;
            dist = vvi(H, vi(W, 0));
            dfs(sh, sw, 0);
            chmax(ans, dist[sh][sw]);
        }
    }
    if(ans < 3) ans = -1;
    cout << ans << endl;

    return 0;
}