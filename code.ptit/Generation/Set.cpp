/*
Xét tất cả các tập hợp các số nguyên dương có các
phần tử khác nhau và không lớn hơn số n cho trước.
Nhiệm vụ của bạn là hãy đếm xem có tất cả bao nhiêu
tập hợp có số lượng phần tử bằng k và tổng của
tất cả các phần tử trong tập hợp bằng s?

Các tập hợp là hoán vị của nhau chỉ được tính là một.

Ví dụ với n = 9, k = 3, s = 23, {6, 8, 9}
là tập hợp duy nhất thỏa mãn.
*/

#include <bits/stdc++.h>
using namespace std;

int n, k, s, ok, dem;

vector<int> a;

void NextComb() {
    int i = k;
    while (a[i] == n - k + i) {
        i--;
    }
    if (i > 0) {
        a[i]++;
        for (int j = i + 1; j <= k; j++) {
            a[j] = a[i] + j - i;
        }
    } else
        ok = 0;
}

int Sum() {
    int sum = 0;
    for (int i = 1; i <= k; i++) {
        sum += a[i];
    }
    return sum;
}

int main() {
    while (cin >> n >> k >> s) {
        if (n == 0 && k == 0 && s == 0)
            break;
        if (n < k) {
            cout << 0 << "\n";
            continue;
        }
        ok = 1;
        dem = 0;
        a.clear();
        a.resize(k + 1);
        for (int i = 1; i <= k; i++) {
            a[i] = i;
        }
        while (ok) {
            if (Sum() == s)
                ++dem;
            NextComb();
        }
        cout << dem << '\n';
    }
    return 0;
}