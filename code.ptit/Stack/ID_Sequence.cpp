/*
Cho dãy ký tự S chỉ bao gồm các ký tự I hoặc D.
Ký tự I được hiểu là tăng (Increasing)
ký tự D được hiểu là giảm (Decreasing).
Sử dụng các số từ 1 đến 9, hãy đưa ra số nhỏ nhất
được đoán nhận từ S. Chú ý, các số không được phép lặp lại
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<int> a;
        string res;
        for (int i = 0; i <= s.size(); ++i) {
            a.push(i + 1);
            if (i == s.size() || s[i] == 'I') {
                while (!a.empty()) {
                    char tmp = '0' + a.top();
                    res = res + tmp;
                    a.pop();
                }
            }
        }
        cout <<res <<"\n";
    }
    return 0;
}
