// N vertices <-> N - 1 edges

#include <bits/stdc++.h>
using namespace std;

class node {
  public:
    int parent, value;
    char dir;
    int vs;
};

void BFS(node root, unordered_map<int, node> &m) {
    int sum = 0;
    queue<node> q;
    q.push(root);
    root.vs = 1;
    while (!q.empty()) {
        node frn = q.front();
        q.pop();
        int isLeaf = 1;
        for (int i = 0; i < m.size(); i++) {
            if (frn.value == m[i].parent) {
                isLeaf = 0;
                if (m[i].vs == 0) {
                    q.push(m[i]);
                    m[i].vs = 1;
                }
            }
        }
        // cout << frn.value << " " << frn.dir << " " << isLeaf << "\n";
        if (isLeaf && frn.dir == 'R') sum += frn.value;
    }
    cout << sum << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, u, v;
        char x;
        cin >> n;
        unordered_map<int, node> m;
        cin >> u >> v >> x;
        node root = {-1, u, 'N', 0};
        node tmp = {u, v, x, 0};
        m.insert(make_pair(0, tmp));
        for (int i = 1; i < n; i++) {
            cin >> u >> v >> x;
            node tmp = {u, v, x, 0};
            m.insert(make_pair(i, tmp));
        }
        BFS(root, m);
    }
}