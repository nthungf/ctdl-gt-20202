/*
Cho số tự nhiên K và xâu ký tự các chữ số S.
Nhiệm vụ của bạn là đưa ra số lớn nhất bằng cách
thực hiện nhiều nhất K lần đổi chỗ các ký tự trong S.
Ví dụ K = 3 và S = “1234567” ta được “7654321”.
*/

#include <bits/stdc++.h>
using namespace std;

int k;
string s, maxx;

void Try(int i) {
    if (i == 0)
        return;
    for (int j = 0; j < s.size(); j++) {
        for (int l = j + 1; l < s.size(); l++) {
            if (s[j] < s[l]) {
                swap(s[j], s[l]);
                if (s > maxx) {
                    maxx = s;
                }
                Try(i - 1);
                swap(s[j], s[l]);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> k >> s;
        maxx = s;
        Try(k);
        cout << maxx << '\n';
    }
    return 0;
}