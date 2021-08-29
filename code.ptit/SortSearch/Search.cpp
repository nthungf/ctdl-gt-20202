/*
Cho mảng A[] gồm n phần tử đã được sắp xếp.
Hãy đưa ra 1 nếu X có mặt trong mảng A[], ngược lại đưa ra -1.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, check = 0;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == x) {
                cout << "1\n";
                check = 1;
            }
        }
        if (!check)
            cout << "-1\n";
    }
    return 0;
}