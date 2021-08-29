/*

*/

#include <bits/stdc++.h>
using namespace std;

class node {
  public:
    int data, level;

    node() {
        data = 0;
        level = 0;
    }
    node(int u, int v) {
        data = u;
        level = v;
    }
};

vector<node> ke[100010];

void BFS(node s) {
    int height = 0;
    queue<node> q;
    q.push(s);
    while (!q.empty()) {
        node u = q.front();
        q.pop();
        // cout << u.data << "(" << u.level << ") ";
        for (int i = 0; i < ke[u.data].size(); i++) {
            ke[u.data][i].level = u.level + 1;
            node v = ke[u.data][i];
            // v.level = u.level + 1;
            if (v.level > height) height = v.level;
            q.push(v);
        }
    }
    cout << height << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 100010; i++) ke[i].clear();
        int n;
        node v1, v2;
        cin >> n >> v1.data >> v2.data;
        ke[v1.data].push_back(v2);
        for (int i = 2; i < n; i++) {
            cin >> v1.data >> v2.data;
            ke[v1.data].push_back(v2);
        }
        node s(1, 0);
        BFS(s);
        // cout << height << "\n";
    }
    return 0;
}