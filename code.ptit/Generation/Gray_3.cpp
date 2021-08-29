/*
 *  Hãy viết chương trình chuyển đổi một xâu
 *  mã nhị phân X có độ dài n thành một xâu mã Gray.
 */

// The Most Significant Bit(MSB) of the gray code
// is always equal to the MSB of the given binary code.

// Other bits of the output gray code can be obtained by
// XORing binary code bit at that index and previous index.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string b, g;
        cin >> b;
        g.resize(b.size());
        g[0] = b[0];
        for (int i = 1; i < b.size(); ++i) {
            if (b[i] == b[i - 1])
                g[i] = '0';
            else
                g[i] = '1';
        }
        cout << g << '\n';
    }
    return 0;
}
