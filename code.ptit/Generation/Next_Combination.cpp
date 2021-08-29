/*
Cho hai số N, K và một tập con K phần tử
X[] =(X1, X2,.., XK) của 1, 2, .., N.
Nhiệm vụ của bạn là hãy đưa ra tập con K phần tử
tiếp theo của X[]. Ví dụ N=5, K=3, X[] ={2, 3, 4}
thì tập con tiếp theo của X[] là {2, 3, 5}.
*/

#include <bits/stdc++.h>
using namespace std;

void output(vector<int> a, int k) {
    for (int i = 1; i <= k; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
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
        output(a, k);
    } else {
        for (int i = 1; i <= k; i++) {
            cout << i << " ";
        }
        cout << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(k + 1);
        for (int i = 1; i <= k; i++) {
            cin >> a[i];
        }
        gen(a, n, k);
    }
    return 0;
}