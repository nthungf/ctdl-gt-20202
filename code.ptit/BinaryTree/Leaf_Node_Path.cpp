/*
Cho một cây có N node, gốc tại 1.
Với mỗi node lá, bạn hãy in ra đường đi từ node gốc tới nó.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> ke[1010];

vector<int> res;
vector<vector<int> > ress;

bool cmp(vector<int> a, vector<int> b) { return a.back() < b.back(); }

void DFS(int u) {
    if (ke[u].empty()) {
        ress.push_back(res);
    }
    for (int i = 0; i < ke[u].size(); i++) {
        int v = ke[u][i];
        res.push_back(v);
        // cout << v << " ";
        DFS(v);
        res.pop_back();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        res.clear();
        ress.clear();
        for (int i = 0; i < 1010; i++) ke[i].clear();
        int n, v1, v2;
        cin >> n;
        for (int i = 1; i < n; i++) {
            cin >> v1 >> v2;
            ke[v1].push_back(v2);
        }
        res.push_back(1);
        DFS(1);
        sort(ress.begin(), ress.end(), cmp);
        for (int i = 0; i < ress.size(); i++) {
            for (int j = 0; j < ress[i].size(); j++) {
                cout << ress[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}