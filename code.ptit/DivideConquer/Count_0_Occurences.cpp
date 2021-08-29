#include <bits/stdc++.h>
using namespace std;

int count(vector<int> a, int l, int r) {
    if (l <= r) {
        int mid = (r + l) / 2;
        if ((mid == r || a[mid + 1] == 1) && a[mid] == 0) {
            return mid + 1;
        }
        if (a[mid] == 0)
            return count(a, mid + 1, r);
        else
            return count(a, l, mid - 1);
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int x = count(a, 0, n - 1);
        if (x >= 0)
            cout << x << "\n";
    }
    return 0;
}