#include <bits/stdc++.h>
using namespace std;

vector<int> node;

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