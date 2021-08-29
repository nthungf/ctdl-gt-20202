/*
 * Cho dãy số A[] gồm có N phần tử đã được sắp xếp tăng dần và số K.
 * Nhiệm vụ của bạn là kiểm tra xem số K có xuất hiện trong dãy số hay không.
 * Nếu có hãy in ra vị trí trong dãy A[], nếu không in ra “NO”.
 */

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> a, int k) {
    int left = 0, right = a.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (k == a[mid])
            return mid;
        else if (k < a[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int res = binarySearch(a, k);
        if (res == -1)
            cout << "NO\n";
        else
            cout << res + 1 << "\n";
    }
    return 0;
}