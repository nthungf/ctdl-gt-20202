/*
Cho số tự nhiên N và một hoán vị X[] của 1, 2, .., N.
Nhiệm vụ của bạn là đưa ra hoán vị tiếp theo của X[].
Ví dụ N=5, X[] = {1, 2, 3, 4, 5} thì hoán vị tiếp theo
của X[] là {1, 2, 3, 5, 4}.
*/

#include <bits/stdc++.h>
using namespace std;

void output(vector<int> a, int n) {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void reverse(vector<int> &a, int x, int y) {
    while (x < y) {
        swap(a[x++], a[y--]);
    }
}

void gen(vector<int> &a, int n) {
    int j = n - 1;
    while (a[j] > a[j + 1])
        j--;
    if (j > 0) {
        int min_index = j + 1;
        for (int k = j + 1; k <= n; k++) {
            if (a[k] < a[min_index])
                min_index = k;
        }
        swap(a[j], a[min_index]);
        reverse(a, j + 1, n);
        output(a, n);

    } else {
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        gen(a, n);
    }
    return 0;
}