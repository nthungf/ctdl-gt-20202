/*

*/

#include <bits/stdc++.h>
using namespace std;

int toInt(string s) {
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        num = num * 10 + (s[i] - '0');
    }
    return num;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > m(n + 5, vector<int>(n + 5));
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
        istringstream is(s);
        while (is >> s) {
            int j = toInt(s);
            m[i][j] = 1;
            m[j][i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}