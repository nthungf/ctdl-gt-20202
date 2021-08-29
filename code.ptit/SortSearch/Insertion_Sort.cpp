/*
 * Hãy thực hiện thuật toán sắp xếp chèn trên dãy N số nguyên.
 * Ghi ra các bước thực hiện thuật toán.
 */

#include <bits/stdc++.h>
using namespace std;

void output(vector<int> a, int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << "Buoc 0: " << a[0] << "\n";
    for (int i = 1; i < n; ++i) {

        int curr = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > curr) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = curr;
        cout << "Buoc " << i << ": ";
        output(a, i + 1);
    }

    return 0;
}