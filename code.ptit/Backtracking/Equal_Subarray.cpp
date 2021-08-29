/*
Cho tập các số A[] = (a1, a2, .., an).
Hãy kiểm tra xem ta có thể chia tập A[] thành hai tập con
sao cho tổng các phần tử của hai tập con bằng nhau
hay không. Đưa ra YES nếu có thể thực hiện được,
ngược lại đưa ra NO.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> a, used;
int sum, check, sumarray;

void Try(int x, int k) {
    for (int j = 0; j < a.size(); j++) {
        if (!used[j]) {
            sum += a[j];
            used[j] = true;
            if (sum == k) {
                check = 1;
                return;
            } else if (sum < k) {
                Try(x + 1, k);
            }
            sum -= a[j];
            used[j] = false;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        sumarray = 0;
        sum = 0;
        check = 0;
        int n, k;
        cin >> n;
        a.clear();
        a.resize(n);
        used.resize(n);
        fill(used.begin(), used.end(), false);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sumarray += a[i];
        }
        //
        if (sumarray % 2 != 0) {
            cout << "NO\n";
            continue;
        }
        //
        k = sumarray / 2;
        sort(a.begin(), a.end());
        Try(0, k);
        if (check)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}