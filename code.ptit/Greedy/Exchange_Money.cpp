/*
Tại ngân hàng có các mệnh giá bằng 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000.
Tổng số tiền cần đổi có giá trị bằng N. Hãy xác định xem có ít nhất bao nhiêu
tờ tiền sau khi đổi tiền?
*/
// số tờ 1000 + số tờ nhỏ hơn 1000
#include <bits/stdc++.h>
using namespace std;

int soTo(int t) {
    switch (t) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 1;
    case 3:
        return 2;
    case 4:
        return 2;
    case 5:
        return 1;
    case 6:
        return 2;
    case 7:
        return 2;
    case 8:
        return 3;
    case 9:
        return 3;
    default:
        return 0;
    }
}

int stringToInt(string s) {
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        num = num * 10 + (s[i] - '0');
    }
    return num;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        // cout << s << '\n';
        int dem = 0;
        for (int i = 0; i < 3; i++) {
            int t = s[i] - '0';
            dem += soTo(t);
            s[i] = '0';
        }
        if (s.size() > 3)
            s.erase(s.begin(), s.begin() + 3);
        reverse(s.begin(), s.end());
        // cout << s << '\n';
        int soToNghin = stringToInt(s);
        // cout << soToNghin << " " << dem << '\n';
        cout << soToNghin + dem << '\n';
    }
    return 0;
}