/*
Cho mảng A[] gồm N số và thực hiện các thao tác
theo nguyên tắc dưới đây:
    Ta chọn một mảng con sao cho phần tử ở giữa của mảng con
    cũng là phần tử ở giữa của mảng A[] (trong trường hợp N lẻ).

    Đảo ngược mảng con đã chọn trong mảng A[]. Ta được phép
    chọn mảng con và phép đảo ngược mảng con bao nhiêu lần tùy ý.
*/

#include <bits/stdc++.h>
using namespace std;

int check(vector<int> &a, vector<int> &b) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i] && a[i] != b[a.size() - 1 - i])
            return 0;
    }
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b.begin(), b.end());

        // for (int i = 0; i < n; i++) {
        //     cout << a[i] << " ";
        // }
        // cout << "\n";
        // for (int i = 0; i < n; i++) {
        //     cout << b[i] << " ";
        // }
        // cout << "\n";

        check(a, b) ? cout << "Yes" : cout << "No";
        cout << "\n";
    }
    return 0;
}