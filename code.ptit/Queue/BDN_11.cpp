/*
Ta gọi số nguyên dương K là một số BDN nếu các chữ số
trong K chỉ bao gồm các 0 hoặc 1 có nghĩa.
Ví dụ số K = 1, 10, 101. Cho số tự nhiên N (N<2^63).
Hãy cho biết có bao nhiêu số BDN nhỏ hơn N.
Ví dụ N=100 ta có 4 số BDN bao gồm các số: 1, 10, 11, 100.
*/

// tim so nhi phan lon nhat nho hon n

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll strtoll(string s) {
    ll n = 0;
    for (int i = 0; i < s.size(); ++i) {
        n = n * 10 + (s[i] - '0');
    }
    return n;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, dem = 0;
        cin >> n;
        queue<string> s;
        s.push("1");
        while (strtoll(s.front()) <= n) {
            string s1 = s.front();
            s.pop();
            // cout << s1 << " ";
            ++dem;
            string s2 = s1;
            s.push(s1 += "0");
            s.push(s2 += "1");
        }
        cout<<dem << "\n";
    }
    return 0;
}
