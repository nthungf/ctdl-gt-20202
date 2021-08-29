/*
Tý đang xây dựng một mạng xã hội và mời các bạn của mình dùng thử.
Bạn của bạn cũng là bạn. Vì vậy, Tý muốn mạng xã hội của mình
là hoàn hảo, tức với mọi bộ ba X, Y, Z, nếu X kết bạn với Y,
Y kết bạn với Z thì X và Z cũng phải là bạn bè của nhau
trên mạng xã hội.

Các bạn hãy xác định xem mạng xã hội hiện tại của Tý
có là hoàn hảo hay không?
Nếu có hãy in ra “YES”, “NO” trong trường hợp ngược lại.
*/

// check if any 2 nodes in a adjacency list are connected

#include <bits/stdc++.h>
using namespace std;

#define max 100010

vector<int> ke[max];
int N, M, ok;

bool isFen(int fen1, int fen2) {
    for (int i = 0; i < ke[fen1].size(); i++) {
        if (ke[fen1][i] == fen2) return true;
    }
    return false;
}

bool Check() {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < ke[i].size(); j++) {
            for (int k = j + 1; k < ke[i].size(); k++) {
                int fen1 = ke[i][j], fen2 = ke[i][k];
                // cout << fen1 << " " << fen2 << "\n";
                if (!isFen(fen1, fen2)) return false;
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < max; i++) ke[i].clear();
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            int v1, v2;
            cin >> v1 >> v2;
            ke[v1].push_back(v2);
            ke[v2].push_back(v1);
        }
        if (Check()) cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}