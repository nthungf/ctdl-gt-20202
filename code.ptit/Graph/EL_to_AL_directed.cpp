/*
Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng
danh sách cạnh. Hãy viết chương trình thực hiện
chuyển đổi biểu diễn đồ thị dưới dạng danh sách kề.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int v, e;
        cin >> v >> e;
        vector<vector<int> > ad(v + 1);
        for (int i = 1; i <= e; i++) {
            int v1, v2;
            cin >> v1 >> v2;
            // cout << tmp1 << " " << tmp2 << "\n";
            ad[v1].push_back(v2);
        }
        for (int i = 0; i < ad.size(); i++) {
            sort(ad[i].begin(), ad[i].end());
        }
        for (int i = 1; i <= v; i++) {
            cout << i << ": ";
            for (int j = 0; j < ad[i].size(); j++) {
                cout << ad[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}