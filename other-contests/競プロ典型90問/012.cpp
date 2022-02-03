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

vi node;

int root(int x) {
    if(x == node[x]) return x;
    else return root(node[x]);
}

void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    node[rx] = ry;
}

bool same(int x, int y) { 
    return root(x) == root(y);
}

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

int main() {
    int H, W; cin >> H >> W;
    int Q; cin >> Q;
    vvi g(H, vi(W, 0));
    vs ans;
    node.resize(H*W);
    rep(i, H*W) node[i] = i;
    rep(i, Q) {
        int q; cin >> q;
        if(q == 1) {
            int r, c; cin >> r >> c;
            r--; c--;
            g[r][c] = 1;
            rep(j, 4) {
                int nr = r + dr[j];
                int nc = c + dc[j];
                if(0 <= nr && nr < H && 0 <= nc && nc < W && g[nr][nc] == 1) unite(r*W+c, nr*W+nc);
            }
        } else {
            int ra, ca, rb, cb; cin >> ra >> ca >> rb >> cb;
            ra--; ca--; rb--; cb--;
            if(g[ra][ca] == 1 && g[rb][cb] == 1 && same(ra*W+ca, rb*W+cb)) ans.pb("Yes");
            else ans.pb("No");
        }
    }

    rep(i, (int)ans.size()) cout << ans[i] << endl;

    return 0;
}