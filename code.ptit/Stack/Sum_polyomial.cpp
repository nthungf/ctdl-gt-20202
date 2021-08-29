/*
Cho hai đa thức có bậc không quá 10000
(chỉ viết ra các phần tử có hệ số khác 0).
Hãy sử dụng danh sách liên kết đơn để viết
chương trình tính tổng hai đa thức đó.
*/

#include <bits/stdc++.h>
using namespace std;

struct dt {
    int heso, somu;
};

list<dt> a1, a2, res;
string s1, s2;

void split(string &x) {
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == '*' || x[i] == 'x' || x[i] == '^' || x[i] == '+')
            x[i] = ' ';
    }
}

int toInt(string x) {
    int n = 0;
    for (int i = 0; i < x.size(); i++) {
        n = n * 10 + (x[i] - '0');
    }
    return n;
}

void Clear() {
    a1.clear();
    a2.clear();
    res.clear();
    s1.clear();
    s2.clear();
}

void Init() {
    Clear();
    getline(cin, s1);
    split(s1);
    getline(cin, s2);
    split(s2);
    istringstream i1(s1), i2(s2);
    vector<int> b1, b2;
    while (i1 >> s1) {
        int tmp = toInt(s1);
        b1.push_back(tmp);
        // cout << tmp << " ";
    }
    while (i2 >> s2) {
        int tmp = toInt(s2);
        b2.push_back(tmp);
        // cout << tmp << " ";
    }
    for (int i = 0; i < b1.size(); i += 2) {
        dt tmp = {b1[i], b1[i + 1]};
        a1.push_back(tmp);
    }
    for (int i = 0; i < b2.size(); i += 2) {
        dt tmp = {b2[i], b2[i + 1]};
        a2.push_back(tmp);
    }
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        Init();
        list<dt>::iterator ir;
        // for (ir = a1.begin(); ir != a1.end(); ir++) {
        //     cout << ir->heso << "*x^" << ir->somu << " + ";
        // }
        // cout << s1 << "\n" << s2 << "\n";

        while (!a1.empty() && !a2.empty()) {
            dt d1 = a1.front(), d2 = a2.front();
            if (d1.somu > d2.somu) {
                res.push_back(d1);
                a1.pop_front();
            } else if (d1.somu < d2.somu) {
                res.push_back(d2);
                a2.pop_front();
            } else {
                dt tmp = {d1.heso + d2.heso, d1.somu};
                res.push_back(tmp);
                a1.pop_front();
                a2.pop_front();
            }
        }
        while (!a1.empty()) {
            res.push_back(a1.front());
            a1.pop_front();
        }
        while (!a2.empty()) {
            res.push_back(a2.front());
            a2.pop_front();
        }
        int dem = 0;
        for (ir = res.begin(); ir != res.end(); ir++) {
            cout << ir->heso << "*x^" << ir->somu;
            if (dem < res.size() - 1) {
                cout << " + ";
            } else
                cout << "\n";
            ++dem;
        }
        cout << "\n";
    }
    return 0;
}