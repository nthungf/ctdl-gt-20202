/*
Một máy ATM hiện có n (n ≤ 30) tờ tiền có giá trị
t[1], t[2], …, t[n]. Hãy tìm cách trả ít tờ nhất với
số tiền đúng bằng S (các tờ tiền có giá trị bất kỳ
và có thể bằng nhau, mỗi tờ tiền chỉ được dùng một lần).
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> a, used, res;
int minn, sum, dem;

// void output() {
//     for (int i = 0; i < res.size(); i++) {
//         cout << res[i] << " ";
//     }
//     cout << "\n";
// }

void Try(int i, int s) {
    for (int j = i; j < a.size(); j++) {
        if (!used[j]) {
            sum += a[j];
            used[j] = 1;
            // res.push_back(a[j]);
            ++dem;
            if (sum == s) {
                // output();
                if (dem < minn) {
                    minn = dem;
                }
            } else if (sum < s) {
                Try(j + 1, s);
            }
            sum -= a[j];
            // res.pop_back();
            --dem;
            used[j] = 0;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        minn = INT_MAX;
        sum = 0;
        int n, s;
        cin >> n >> s;
        a.resize(n);
        used.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            used[i] = 0;
        }
        sort(a.begin(), a.end(), greater<int>());
        Try(0, s);
        if (minn != INT_MAX) cout << minn << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}