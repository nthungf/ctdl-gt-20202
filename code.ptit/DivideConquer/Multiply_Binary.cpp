/*
Cho hai xâu nhị phân biểu diễn hai số.
Nhiệm vụ của bạn là đưa ra tích của hai số.
Ví dụ với xâu S1=”1100” và S2=”1010” ta sẽ có kết quả là 120.
*/

#include <bits/stdc++.h>
using namespace std;

long long binToDec(string s) {
    long long n = 0;
    for (int i = 0; i < s.size(); i++) {
        n = n * 2 + s[i] - '0';
    }
    return n;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        long long n1, n2;
        n1 = binToDec(s1);
        n2 = binToDec(s2);
        cout << n1 * n2 << "\n";
    }
    return 0;
}