/*
Cho số nguyên N. Nhiệm vụ của bạn cần tìm
số nguyên X nhỏ nhất là bội của N, và X chỉ chứa
hai chữ số 0 và 9.
*/

#include <bits/stdc++.h>
using namespace std;

int ok = 1;

void gen(string &x) {
    int i = x.size() - 1;
    while (i >= 0 && x[i] == '1') {
        x[i] = '0';
        i--;
    }
    if (i >= 0)
        x[i] = '1';
    else
        ok = 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ok = 1;
        int n;
        cin >> n;
        string x;

        x.resize(17);
        fill(x.begin(), x.end(), '0');
        while (ok) {
            gen(x);
            // cout << x << " ";
            long long sss = 0;
            for (int i = 0; i < x.size(); i++) {
                sss = sss * 10 + (x[i] - '0');
            }
            sss *= 9;
            if (sss % n == 0) {
                cout << sss << '\n';
                ok = 0;
            }
        }
    }
    return 0;
}