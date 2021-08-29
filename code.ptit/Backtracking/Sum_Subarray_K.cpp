/*
 * Cho dãy số A[] = (a1, a2, .., an) và số tự nhiên K.
 * Hãy đưa ra tất cả các dãy con của dãy số A[] sao cho
 * tổng các phần tử của dãy con đó đúng bằng K.
 * Các phần tử của dãy số A[] được giả thuyết là nguyên dương
 * và không có các phần tử giống nhau. Ví dụ với dãy con
 * A[] = {5, 10, 15, 20, 25}, K = 50 ta có 3 dãy con
 * {5, 10, 15, 20}, {5, 20, 25}, {10, 15, 25}.
 */

#include <bits/stdc++.h>
using namespace std;

int sum, dem;
vector<int> res;
vector<int> a;
vector<bool> used;

void output() {
    if (!res.empty()) {
        cout << "[";
        for (int i = 0; i < res.size() - 1; i++) {
            cout << res[i] << " ";
        }
        cout << res[res.size() - 1] << "] ";
    }
}
void Try(int x, int k) {
    for (int j = x; j < a.size(); ++j) {
        sum += a[j];
        used[j] = true;
        res.push_back(a[j]);
        if (sum == k) {
            output();
            ++dem;
        } else if (sum < k)
            Try(j + 1, k);
        sum -= a[j];
        res.pop_back();
        used[j] = false;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        sum = 0;
        dem = 0;
        int n, k;
        cin >> n >> k;
        a.clear();
        a.resize(n);
        used.clear();
        used.resize(n);
        res.clear();
        fill(used.begin(), used.end(), false);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        Try(0, k);
        if (dem == 0)
            cout << "-1";
        cout << "\n";
    }
    return 0;
}
