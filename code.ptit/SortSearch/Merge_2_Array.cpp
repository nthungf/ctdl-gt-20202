/*
Cho mảng A[] gồm n phần tử và mảng B[] gồm m phần tử.
Nhiệm vụ của bạn là hợp nhất hai mảng A[] và B[] để
được một mảng mới đã được sắp xếp
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int p = n + m;
        vector<int> a(p);
        for (int i = 0; i < p; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < p; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}