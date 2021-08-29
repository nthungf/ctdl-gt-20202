/*
Cho xâu ký tự S bao gồm các ký tự in thường.
Nhiệm vụ của bạn là kiểm tra xem ta có thể sắp đặt
lại các ký tự trong S để hai ký tự giống nhau đều
không kề nhau hay không?
Đưa ra 1 nếu có thể sắp đặt lại các ký tự trong S
thỏa mãn yêu cầu bài toán, ngược lại đưa ra -1.
*/

#include <bits/stdc++.h>
using namespace std;

struct F {
    char c;
    int freq;
};

int cmp(F x, F y) { return x.freq >= y.freq; }

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        F f[26];
        priority_queue<F> pq;
        char x = 'a';
        for (int i = 0; i < 26; i++) {
            f[i].c = x++;
        }
        for (int i = 0; i < s.size(); i++) {
            f[s[i] - 'a'].freq++;
        }
        for (int i = 0; i < 26; i++) {
            if (f[i].freq > 0)
                pq.push(f[i]);
        }
    }
    return 0;
}