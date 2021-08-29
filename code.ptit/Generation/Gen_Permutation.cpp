/*
Cho số nguyên dương N. Nhiệm vụ của bạn là
hãy liệt kê tất cả các hoán vị của 1, 2, .., N.
Ví dụ với N = 3 ta có kết quả: 123, 132, 213, 231, 312, 321.
*/

#include <bits/stdc++.h>
using namespace std;

int check = 0;

void output(vector<int> a, int n) {
    for (int i = 1; i <= n; i++) {
        cout << a[i];
    }
    cout << " ";
}

void reverse(vector<int> &a, int x, int y) {
    while (x < y) {
        swap(a[x++], a[y--]);
    }
}

void gen(vector<int> &a, int n) {
    int j = n - 1;
    while (a[j] >= a[j + 1])
        j--;
    if (j > 0) {
        int k = j + 1;
        for (int i = j + 1; i <= n; i++) {
            if (a[i] > a[j] && a[i] < a[k]) {
                k = i;
            }
        }
        swap(a[j], a[k]);
        reverse(a, j + 1, n);
    } else
        check = 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        check = 0;
        int n;
        cin >> n;
        vector<int> a(n + 2);
        for (int i = 0; i <= n + 1; i++) {
            a[i] = i;
        }
        while (!check) {
            output(a, n);
            gen(a, n);
        }
        cout << "\n";
    }
    return 0;
}