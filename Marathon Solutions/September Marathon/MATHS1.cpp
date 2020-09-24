#include <iostream>
#include <cassert>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
#define TASK "queries"
const int N = 1e5 + 10;
const int M = 1e9;

int LOWER_BOUND_BIT[10][1<<10];

struct Trie {
    struct Node;
    struct Node {
        Node* to[11];
        int prefSum, mask, ownSum;
        ll ans;
        Node(): prefSum(0), mask(0), ans(0), ownSum(0) {}
    };

    const int H = 9;

    Node mem[1000000];
    int ptr;
    Trie():ptr(0), root(newNode()) {}

    Node* newNode() {
        return &mem[ptr++];
    }

    Node *root;
    Node* layer[2][1024];

    Node* insert(char* num, int len) {
        Node *v = root;
        for (int i = 0; i < H; ++i) {
            int c = (i < H - len ? 0 : num[i - H + len]);
            if (v->to[c] == NULL) {
                v->to[c] = newNode();
                if (c != 10)
                    v->mask |= 1<<c;
            }
            v = v->to[c];
        }
        return v;
    }

    void down(int x) {
        int digs[10], s = 0;
        while (s < H) {
            digs[s++] = x % 10;
            x /= 10;
        }

        for (int i = 0; i < H / 2; ++i)
            swap(digs[i], digs[H - i - 1]);

        int sz[2] = {0, 0}, id = 0;
        sz[0] = 1;
        layer[0][0] = root;
        for (int i = 0; i < H; ++i) {
            id = i&1;
            sz[id^1] = 0;
            int dig = digs[i];
            for (int j = 0; j < sz[id]; ++j) {
                Node* v = layer[id][j];
                int bit = LOWER_BOUND_BIT[dig][v->mask];
                if (bit != -1)
                    v->to[bit]->prefSum++;

                if (v->to[dig] != NULL)
                    layer[id^1][sz[id^1]++] = v->to[dig];

                if (v->to[10] != NULL) {
                    v->to[10]->prefSum += dig;
                    layer[id^1][sz[id^1]++] = v->to[10];
                }
            }
        }
        id = H&1;
        for (int i = 0; i < sz[id]; ++i)
            layer[id][i]->ownSum++;
    }

    void push(Node* v, ll ans, int h) {
        if (h == 0)
            v->ans = ans;
        else {
            int cursum = 0;
            for (int i = 10; i >= 0; --i) {
                if (v->to[i] != NULL)
                    cursum += v->to[i]->prefSum;
                if (v->to[i] != NULL)
                    push(v->to[i], ans * (i == 10 ? 10 : 1) + cursum + v->to[i]->ownSum, h - 1);
                if (i == 10)
                    cursum = 0;
            }
        }
    }
};

Trie trie;
int a[N];
Trie::Node *endNode[N];
char s[12];

int main() {
   
    int masks = 1<<10;
    for (int d = 0; d < 10; ++d)
        for (int i = 0; i < masks; ++i) {
            int last = -1;
            for (int j = 0; j < d; ++j)
                if ((i>>j)&1) last = j;
            LOWER_BOUND_BIT[d][i] = last;
        }

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    sort(a, a + n);

    for (int i = 0; i < m; ++i) {
        scanf("%s", s);
        int len = strlen(s);
        for (int j = 0; j < len; ++j)
            if (s[j] == '?')
                s[j] = 10;
            else
                s[j] -= '0';
        endNode[i] = trie.insert(s, len);
    }

    for (int i = 0; i < n; ++i)
        trie.down(a[i]);
    trie.push(trie.root, 0, trie.H);

    for (int i = 0; i < m; ++i)
        if (i + 1 != m)
            cout << endNode[i]->ans << "\n";
        else
            cout << endNode[i]->ans << endl;

    return 0;
}
