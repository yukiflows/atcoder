#include <bits/stdc++.h>

#define pb push_back
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

using pi = pair<int, int>;

using vi  = vector<int>;
using vl  = vector<long>;
using vll = vector<long long>;
using vs  = vector<string>;

using vvi  = vector<vector<int>>;
using vvl  = vector<vector<long>>;
using vvll = vector<vector<long long>>;

using vvvi = vector<vector<vector<int>>>;

const long long INF = 1e9+7;
const long long MOD = 1e9+7;

template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if(a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if(a < b) a = b; return compare;}

int main() {
    int H, W; cin >> H >> W;
    int rs, cs; cin >> rs >> cs; rs--; cs--;
    int rt, ct; cin >> rt >> ct; rt--; ct--;
    vs maze(H); rep(i, H) cin >> maze[i];
    vvvi dist(H, vvi(W, vi(4, INF)));

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, -1, 0, 1};

    deque<tuple<int, int, int>> q;
    rep(d, 4) {
        dist[rs][cs][d] = 0;
        q.push_front(mt(rs, cs, d));
    }

    while(!q.empty()) {
        int r, c, d;
        tie(r, c, d) = q.front();
        q.pop_front();

        int nr = r;
        int nc = c;

        if(d == 0) {
            nc++;
        } else if(d == 1) {
            nr--;
        } else if(d == 2) {
            nc--;
        } else {
            nr++;
        }

        if(0 <= nr && nr < H && 0 <= nc && nc < W && maze[nr][nc] == '.') {
            if(chmin(dist[nr][nc][d], dist[r][c][d])) q.push_front(mt(nr, nc, d));
            rep(j, 4) if(chmin(dist[nr][nc][j], dist[nr][nc][d]+1)) q.push_back(mt(nr, nc, j));
        }
    } 

    int ans = INF;
    rep(d, 4) chmin(ans, dist[rt][ct][d]);
    cout << ans << endl;

    return 0;
}