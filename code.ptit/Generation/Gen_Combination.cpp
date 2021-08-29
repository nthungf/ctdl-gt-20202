/*
Cho hai số nguyên dương N và K.
Nhiệm vụ của bạn là hãy liệt kê tất cả
các tập con K phần tử của 1, 2, .., N.
Ví dụ với N=5, K=3 ta có 10 tập con của
1, 2, 3, 4, 5 như sau:
{1, 2, 3}, {1, 2, 4},{1, 2, 5},
{1, 3, 4},{1, 3, 5},{1, 4, 5},{2, 3, 4},
{2, 3, 5},{2, 4, 5},{3, 4, 5}.
*/

#include <bits/stdc++.h>
using namespace std;

int check = 0;

void output(vector<int> a, int k) {
    for (int i = 1; i <= k; i++) {
        cout << a[i];
    }
    cout << " ";
}

void gen(vector<int> &a, int n, int k) {
    int i = k;
    while (a[i] == n - k + i)
        i--;
    if (i > 0) {
        a[i]++;
        for (int j = i + 1; j <= k; j++) {
            a[j] = a[i] + j - i;
        }
    } else {
        check = 1;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        check = 0;
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);

        // init
        for (int i = 0; i <= k; i++) {
            a[i] = i;
        }
        //
        while (!check) {
            output(a, k);
            gen(a, n, k);
        }
        cout << "\n";
    }
    return 0;
}