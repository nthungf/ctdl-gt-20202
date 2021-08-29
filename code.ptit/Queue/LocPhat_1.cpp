/*
Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8.
Cho số tự nhiên N.
Hãy liệt kê các số lộc phát có không quá N chữ số.
In đáp án theo thứ tự giảm dần.
*/

#include <bits/stdc++.h>
using namespace std;

int cmp(string x, string y) {
    long long xx = 0, yy = 0;
    for (int i = 0; i < x.size(); i++) {
        xx = xx * 10 + (x[i] - '0');
    }
    for (int i = 0; i < y.size(); i++) {
        yy = yy * 10 + (y[i] - '0');
    }
    return (xx > yy);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        queue<string> s1, s2;
        s1.push("6");
        s2.push("8");
        //
        vector<string> res1;
        while (s1.front().size() <= n) {
            string ss1 = s1.front();
            s1.pop();
            // cout << s1 << " ";
            res1.push_back(ss1);
            string ss2 = ss1;
            s1.push(ss1 += "8");
            s1.push(ss2 += "6");
        }
        //
        vector<string> res2;
        while (s2.front().size() <= n) {
            string ss1 = s2.front();
            s2.pop();
            // cout << s1 << " ";
            res2.push_back(ss1);
            string ss2 = ss1;
            s2.push(ss1 += "6");
            s2.push(ss2 += "8");
        }
        //
        vector<string> res3;
        for (int i = 0; i < res1.size(); i++) {
            res3.push_back(res1[i]);
        }
        for (int i = 0; i < res2.size(); i++) {
            res3.push_back(res2[i]);
        }
        //
        sort(res3.begin(), res3.end(), cmp);
        // cout << res3.size() << "\n";
        for (int i = 0; i < res3.size(); i++) {
            cout << res3[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}