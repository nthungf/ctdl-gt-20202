/*
Cho số tự nhiên N. Hãy tìm số nguyên dương X
nhỏ nhất được tạo bởi số 9 và số 0 chia hết cho N.
Ví dụ với N = 5 ta sẽ tìm ra  X = 90.
*/

#include <bits/stdc++.h>
using namespace std;

long long strToInt(string s) {
    long long n = 0;
    for (long long i = 0; i < s.size(); i++) {
        n = n * 10 + (s[i] - '0');
    }
    return n;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        queue<string> s;
        s.push("9");
        while (s.size() > 0) {
            string s1 = s.front();
            s.pop();
            // cout << s1 << ' ';
            long long num = strToInt(s1);
            if (num % n == 0) {
                cout << num << "\n";
                break;
            }
            string s2 = s1;
            s.push(s1 += "0");
            s.push(s2 += "9");
        }
    }
    return 0;
}