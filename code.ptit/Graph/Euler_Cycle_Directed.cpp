/*
Cho đồ thị có hướng liên thông yếu G=<V, E> được biểu diễn
dưới dạng danh sách cạnh. Hãy kiểm tra xem đồ thị có chu trình
Euler hay không?
*/

#include <bits/stdc++.h>
using namespace std;

int v, e;

vector<vector<int> > ke;

struct deg {
    int in, out;
};

vector<deg> D;

void Init() {
    cin >> v >> e;
    ke.clear();
    ke.resize(v + 1);
    D.clear();
    D.resize(v + 1);
    for (int i = 0; i < e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        ke[v1].push_back(v2);
    }
}

void degCalc() {
    for (int i = 1; i <= v; i++) {
        D[i].out = ke[i].size();
    }
    for (int i = 1; i <= v; i++) {
        for (int j = 0; j < ke[i].size(); j++) {
            D[ke[i][j]].in++;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        degCalc();

        int check = 1;
        for (int i = 1; i <= v; i++) {
            // cout << D[i].in << " " << D[i].out << "\n";
            if (D[i].in != D[i].out) {
                check = 0;
                break;
            }
        }
        check ? cout << "1" : cout << "0";
        cout << "\n";
    }
    return 0;
}