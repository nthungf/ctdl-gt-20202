/*
 * Cho một ngăn xếp các số nguyên.
 * Các thao tác gồm 3 lệnh: push, pop và show.
 * Trong đó thao tác push kèm theo một giá trị cần thêm (không quá 1000).
 * Hãy viết chương trình ghi ra kết quả của các lệnh show.
 */

#include <bits/stdc++.h>
using namespace std;

void show(stack<int> a) {
    vector<int> b;
    while (!a.empty()) {
        int x = a.top();
        b.push_back(x);
        a.pop();
    }
    reverse(b.begin(), b.end());
    if (b.size() > 0) {
        for (int i = 0; i < b.size(); ++i) {
            cout << b[i] << " ";
        }
        cout << "\n";
    } else
        cout << "empty\n";
}

int stringToInt(string s) {
    int num = 0;
    for (int i = 0; i < s.size(); ++i) {
        num = num * 10 + (s[i] - '0');
    }
    return num;
}

int main() {
    stack<int> a;
    vector<string> s;
    string ss;
    while (getline(cin, ss)) {
        if (ss.empty())
            break;
        //
        vector<string> sss;
        istringstream is(ss);
        string tmp;
        while (is >> tmp)
            sss.push_back(tmp);
        //
        if (sss[0] == "push") {
            int x = stringToInt(sss[1]);
            a.push(x);
        }
        if (sss[0] == "pop" && !a.empty())
            a.pop();
        else if (sss[0] == "show")
            show(a);
    }
    for (int i = 0; i < s.size(); ++i) {
        cout << s[i] << " ";
    }

    return 0;
}