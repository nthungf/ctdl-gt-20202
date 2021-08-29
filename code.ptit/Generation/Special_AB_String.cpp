/*
 * Hãy viết chương trình liệt kê tất cả các xâu AB
 * có độ dài N chứa duy nhất một dãy K kí tự A liên tiếp.
 */
#include <bits/stdc++.h>
using namespace std;
int ok = 1;

void nextBinary(string &x) {
    int i = x.size() - 1;
    while (i >= 0 && x[i] == 'B') {
        x[i] = 'A';
        i--;
    }
    if (i >= 0)
        x[i] = 'B';
    else
        ok = 0;
}

int check(string tmp) {

    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    if (tmp == "AB")
        return 1;
    return 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    string x;
    x.resize(n - k);
    fill(x.begin(), x.end(), 'A');
    string s;
    s.resize(k);
    fill(s.begin(), s.end(), 'A');

    vector<string> res;

    while (ok) {
        for (int i = 0; i <= x.size(); i++) {
            string tmp = x;
            if (x[i] != 'A' && x[i - 1] != 'A') {
                tmp.insert(i, s);
                if (check(tmp)) {
                    res.push_back(tmp);
                }
            }
        }
        nextBinary(x);
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
    }
    cout << "\n";
    return 0;
}