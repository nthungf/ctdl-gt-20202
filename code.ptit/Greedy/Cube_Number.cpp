/*
Một số X được gọi là số khối lập phương nếu X
là lũy thừa bậc 3 của số Y (X= Y3).
Cho số nguyên dương N, nhiệm vụ của bạn là tìm
số khối lập phương lớn nhất bằng cách loại bỏ đi
các chữ số của N.
Ví dụ số 4125 ta có kết quả là 125 = 53.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

vector<string> a;
void preCalc(ll n) {
    a.push_back("1");
    for (ll i = 1; i <= cbrt(n); i++) {
        ll tmp = i * i * i;
        string s = to_string(tmp);
        a.push_back(s);
    }
}

bool compare(string ai, string nn) {
    // tat ca ki tu ai deu co trong nn theo thu tu
    string res;
    int mark = 0;
    for (int i = 0; i < ai.size(); i++) {
        for (int j = mark; j < nn.size(); j++) {
            // cout << ai[i] << " " << nn[j] << "\n";
            if (ai[i] == nn[j]) {
                res.push_back(ai[i]);
                mark = j + 1;
                break;
            }
        }
    }
    // cout << res << "\n";
    if (res == ai) return true;
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        a.clear();
        preCalc(n);
        string nn = to_string(n);
        int ok = 0;
        for (ll i = cbrt(n); i > 0; i--) {
            // compare a[i] and nn;
            // cout << a[i] << "--\n";
            if (compare(a[i], nn)) {
                cout << a[i] << "\n";
                ok = 1;
                break;
            }
        }
        if (!ok) cout << "-1\n";
    }
    return 0;
}