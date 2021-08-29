/*
Cho đơn đồ thị G vô hướng liên thông
được mô tả bởi danh sách kề.
Hãy in ra danh sách cạnh tương ứng của G.
*/

#include <bits/stdc++.h>
using namespace std;
#define max 1010

int n;
vector<vector<int> > ke;

int main() {
    cin >> n;
    cin.ignore();
    ke.resize(n + 2);
    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
        istringstream is(s);
        int y;
        while (is >> y) {
            ke[i].push_back(y);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < ke[i].size(); j++) {
            if (i < ke[i][j])
                cout << i << " " << ke[i][j] << "\n";
        }
    }

    return 0;
}