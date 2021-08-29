/*
Cho một dãy số nguyên gồm N phần tử A[1], A[2], ... A[N].
Biết rằng dãy con tăng là 1 dãy A[i1],... A[ik]
thỏa mãn i1 < i2 < ... < ik và A[i1] < A[i2] < .. < A[ik].
Hãy cho biết dãy con tăng dài nhất của dãy này có bao nhiêu phần tử?
*/

// 1 2 5 4 6 2
// 1 2 3 3 4 2

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), l(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    l[0] = 1;
    for (int i = 1; i < n; i++) {
        int maxl = INT_MIN;
        for (int j = 0; j < i; j++) {
            if (l[j] > maxl && a[i] > a[j])
                maxl = l[j];
        }
        // cout << maxl << " ";
        l[i] = maxl + 1;
    }
    // for (int i = 0; i < n; i++) {
    //     cout << l[i] << " ";
    // }
    // cout << "\n";
    cout << *max_element(l.begin(), l.end());
    return 0;
}