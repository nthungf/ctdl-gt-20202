/*
 * Xâu ký tự str được gọi là xâu AB nếu mỗi ký tự trong xâu
 * hoặc là ký tự ‘A’ hoặc là ký tự ‘B’.
 * Ví dụ xâu str=”ABBABB” là xâu AB độ dài 6.
 * Nhiệm vụ của bạn là hãy liệt kê tất cả các xâu AB có độ dài n.
 */

#include <bits/stdc++.h>
using namespace std;

void output(vector<int> a) {
    for (int i = 1; i < a.size(); ++i) {
        a[i] == 0 ? cout << 'A' : cout << 'B';
        //        cout << a[i];
    }
    cout << ' ';
}

int check;
void gen(vector<int> &a) {
    int i = a.size() - 1;
    while (a[i] == 1)
        i--;
    if (i > 0) {
        a[i] = 1;
        for (int j = i + 1; j < a.size(); ++j) {
            a[j] = 0;
        }
    } else
        check = 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        check = 0;
        int n;
        cin >> n;
        vector<int> a(n + 1);
        while (!check) {
            output(a);
            gen(a);
        }
        cout << "\n";
    }
    return 0;
}