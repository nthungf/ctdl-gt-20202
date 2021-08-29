/*
 * Hãy viết chương trình liệt kê các mã Gray có độ dài n.
 */
// phương pháp soi gương

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 0) {
            cout << "\n";
            continue;
        }
        vector<string> a, b;
        a.emplace_back("0");
        a.emplace_back("1");
        while (a[0].size() < n) {
            b = a;
            reverse(b.begin(), b.end());
            for (int i = 0; i < a.size(); ++i) {
                a[i].insert(0, "0");
            }
            for (int i = 0; i < b.size(); ++i) {
                b[i].insert(0, "1");
                a.push_back(b[i]);
            }
        }
        for (int i = 0; i < a.size(); ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}