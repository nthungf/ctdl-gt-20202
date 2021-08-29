/*
Đường đi đơn trên đồ thị có hướng hoặc vô hướng đi qua
tất cả các đỉnh của đồ thị mỗi đỉnh đúng một lần được
gọi là đường đi Hamilton.
Cho đồ thị vô hướng G = <V, E>, hãy kiểm tra xem đồ thị
có đường đi Hamilton hay không?
*/
// permutation generation from 1 to V
// check every permutation

#include <bits/stdc++.h>
using namespace std;

set<int> ke[30];
int a[30][30];
int V, E;
vector<int> X;

bool DetectHamilton() {
    do {
        int check = 1;
        for (int i = 1; i < V; i++) {
            if (a[X[i]][X[i + 1]] == 0) {
                check = 0;
                break;
            }
        }
        if (check) return true;
    } while (next_permutation(X.begin(), X.end()));
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 30; i++) ke[i].clear();
        memset(a, 0, sizeof(a));
        X.clear();
        cin >> V >> E;
        int v1, v2;
        for (int i = 0; i < E; i++) {
            cin >> v1 >> v2;
            X.push_back(v1);
            X.push_back(v2);
            a[v1][v2] = 1;
            a[v2][v1] = 1;
        }
        sort(X.begin(), X.end());
        X.erase(unique(X.begin(), X.end()), X.end());
        if (DetectHamilton()) cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}