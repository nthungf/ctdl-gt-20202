/*
Cho xâu ký tự S bao gồm các ký tự in thường và số D.
Nhiệm vụ của bạn là kiểm tra xem ta có thể sắp đặt lại
các ký tự trong S để tất cả các ký tự giống nhau đều có
khoảng cách là D hay không?
Đưa ra 1 nếu có thể sắp đặt lại các ký tự trong S
thỏa mãn yêu cầu bài toán, ngược lại đưa ra -1.
*/

#include <bits/stdc++.h>
using namespace std;

#define max_char 26

struct F {
    char c;
    int freq;
};

int cmp(F x, F y) { return x.freq >= y.freq; }

int main() {
    int t;
    cin >> t;
    while (t--) {
        int D;
        cin >> D;
        string s;
        cin >> s;
        vector<F> a(max_char);
        for (int i = 0; i < max_char; i++) {
            a[i].c = 'A' + i;
        }
        for (int i = 0; i < s.size(); i++) {
            a[s[i] - 'A'].freq++;
        }
        sort(a.begin(), a.end(), cmp);
        for (int i = 0; i < max_char; i++) {
            cout << a[i].c << " " << a[i].freq << "\n";
        }

        sort(a.begin(), a.end(), cmp);

        string res;
        for (int i = 0; i < s.size(); i++) {
            res.push_back(' ');
        }
        int check = 1;
        for (int i = 0; i < a.size(); i++) {
            int d = 0, j = 0;
            for (int x = 0; x < s.size(); x++) {
                if (res[x] == ' ') {
                    j = x;
                    break;
                }
            }
            // cout << j << " ";
            while (d < a[i].freq) {
                if (j >= s.size()) {
                    check = 0;
                    break;
                }
                if (res[j] == ' ') {
                    res[j] = a[i].c;
                    ++d;
                    j += D;
                } else
                    j++;
            }
            if (!check)
                break;
        }
        // cout << res << "\n";
        if (check)
            cout << "1\n";
        else
            cout << "-1\n";
    }
    return 0;
}