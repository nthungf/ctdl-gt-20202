/*
Hãy viết chương trình chuyển đổi một xâu
mã Gray X có độ dài n thành một xâu mã nhị phân.
*/

// The Most Significant Bit (MSB) of the binary code
// is always equal to the MSB of the given gray code.
// Other bits of the output binary code can be
// obtained by checking gray code bit at that index.
// If current gray code bit is 0, then copy previous
// binary code bit, else copy invert of previous binary code bit.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string g, b;
        cin >> g;
        vector<vector<int> > A;
        b.resize(g.size());
        b[0] = g[0];
        // b[i] = b[i-1] XOR G[i]
        for (int i = 1; i < b.size(); i++) {
            if (b[i - 1] == g[i])
                b[i] = '0';
            else
                b[i] = '1';
        }
        cout << b << '\n';
    }
    return 0;
}