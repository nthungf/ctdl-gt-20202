/*
Cho mảng A[] gồm n phần tử, hãy tìm cặp phần tử
có tổng gần nhất so với 0. Đưa ra tổng đó.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int minn = a[0] + a[1], sum = 0, l = 0, r = n - 1;
        while (l < r) {
            sum = a[l] + a[r];
            if (abs(sum) < abs(minn)) minn = sum;
            if (sum < 0) l++;
            else
                r--;
        }
        cout << minn << "\n";
    }
    return 0;
}