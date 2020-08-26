#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
#define TASK "city"
const int N = 1e5 + 10;
const int LOGN = 17;

struct Fenwick {
    vector<int> s;
    Fenwick(){}
    Fenwick(int n): s(n) {}

    void upd(int v, int val) {
        while (v < s.size()) {
            s[v] += val;
            v |= v + 1;
        }
    }

    int getSum(int l, int r) const {
        return getPref(r) - getPref(l - 1);
    }

    int getPref(int v) const {
        int ret = 0;
        for (; v >= 0; v = (v & (v + 1)) - 1)
            ret += s[v];
        return ret;
    }
};

vector<int> g[N];
Fenwick tree;

int jump[LOGN][N], lev[N];
int tin[N], tout[N], timeDfs, currentLca;

bool compareByTin(int x, int y) {
    return tin[x] < tin[y];
}

set<int, bool (*)(int, int)> occupated(compareByTin);

int up(int x, int diff) {
    for (int i = 0; diff > 0; diff >>= 1, i++)
        if (diff&1)
            x = jump[i][x];
    return x;
}

int lca(int x, int y) {
    if (lev[x] < lev[y])
        swap(x, y);
    x = up(x, lev[x] - lev[y]);
    if (x == y)
        return x;
    for (int i = LOGN - 1; i >= 0; --i)
        if (jump[i][x] != jump[i][y]) {
            x = jump[i][x];
            y = jump[i][y];
        }
    return jump[0][x];
}

void dfs(int v, int p) {
    jump[0][v] = p;
    for (int i = 1; (1<<i) <= lev[v]; ++i)
        jump[i][v] = jump[i - 1][jump[i - 1][v]];
    tin[v] = timeDfs++;
    for (auto to: g[v])
        if (to != p) {
            lev[to] = lev[v] + 1;
            dfs(to, v);
        }
    tout[v] = timeDfs++;
}

bool isParent(int p, int x) {
    return tin[p] <= tin[x] && tin[x] <= tout[p];
}

bool isBlack(int x) {
    return currentLca != -1 && isParent(currentLca, x) && tree.getSum(tin[x], tout[x]) != 0;
}

int upToBlack(int x) {
    for (int i = LOGN - 1; i >= 0; --i)
        if (lev[jump[i][x]] >= lev[currentLca] && !isBlack(jump[i][x]))
            x = jump[i][x];
    return jump[0][x];
}

int countBlack(int x, int v, int currentLca) {
    if (currentLca == -1 || x == v || !isParent(currentLca, x))
        return 0;
    if (tree.getSum(tin[x], tout[x]) == 0)
        x = upToBlack(x);
    if (!isParent(v, x))
        return 0;
    if (isParent(currentLca, v))
        return lev[x] - lev[v];
    return lev[x] - lev[currentLca] + 1;
}

int main() {
    

    int n, m;
    cin >> n;
    int x, y;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &x, &y);
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, 0);
    tree = Fenwick(timeDfs);

    cin >> m;
    currentLca = -1;
    for (int i = 0; i < m; ++i) {
        int t, x, y;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d", &x);
            --x;
            if (occupated.find(x) != occupated.end()) {
                occupated.erase(x);
                tree.upd(tin[x], -1);
                if (occupated.size() == 0) currentLca = -1;
                else currentLca = lca(*occupated.begin(), *occupated.rbegin());
            } else {
                occupated.insert(x);
                tree.upd(tin[x], 1);
                currentLca = lca(*occupated.begin(), *occupated.rbegin());
            }
        } else if (t == 2) {
            scanf("%d%d", &x, &y);
            --x;
            --y;
            int v = lca(x, y);
            int cntX = countBlack(x, v, currentLca);
            int cntY = countBlack(y, v, currentLca);
            printf("%d\n", cntX + cntY + isBlack(v));
        }
    }
    return 0;
}
