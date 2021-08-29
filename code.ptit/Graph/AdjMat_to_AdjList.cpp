/*

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> ke[1010];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                ke[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < ke[i].size(); j++) {
            cout << ke[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}