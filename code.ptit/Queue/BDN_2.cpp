/*
Số BDN của N là số P =M´N sao cho P là số BDN.
Cho số tự nhiên N (N<1000), hãy tìm số BDN nhỏ nhất của N.

Ví dụ. Với N=2, ta tìm được số BDN của N là P = 5´2=10.
N = 17 ta tìm được số BDN của 17 là P = 653´17=11101.
*/

// tim so nhi phan nho nhat chia het cho p

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
        ll p;
        cin >> p;
        queue<string> s;
        s.push("1");
        while (strtoll(s.front()) % p != 0) {
            string s1 = s.front();
            s.pop();
            // cout << s1 << " ";
            string s2 = s1;
            s.push(s1 += "0");
            s.push(s2 += "1");
        }
        cout << s.front() << "\n";
    }
    return 0;
}
