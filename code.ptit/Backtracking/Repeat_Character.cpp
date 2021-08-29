/*
Cho một dãy các xâu ký tự chỉ bao gồm các chữ cái in hoa từ A đến Z,
trong đó các ký tự trong mỗi xâu đều đã được sắp xếp theo
thứ tự từ điển và mỗi chữ cái chỉ xuất hiện nhiều nhất một lần
(tức là độ dài xâu tối đa là 26).
Nếu một ký tự xuất hiện trong hai xâu liên tiếp
thì được coi là một lần lặp.
Hãy tìm cách sắp xếp lại thứ tự các xâu sao cho
số lần lặp là nhỏ nhất có thể.
*/

#include <bits/stdc++.h>
using namespace std;

int n, vs[11], minn, sum;

vector<string> res, s;

int dem2Xau(string a, string b) {
    string tmp;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(tmp));
    return tmp.size();
}

void Try(int i) {
    for (int j = 0; j < n; j++) {
        if (!vs[j]) {
            res[i] = s[j];
            vs[j] = 1;
            int demm = 0;
            if (i > 0) {
                demm = dem2Xau(res[i], res[i - 1]);
            }
            sum += demm;
            // cout << sum << " ";
            if (i == n - 1) {
                if (sum < minn) minn = sum;
            } else if (sum < minn)
                Try(i + 1);
            res[i] = "";
            vs[j] = 0;
            sum -= demm;
        }
    }
}

int main() {
    cin >> n;
    minn = 100;
    sum = 0;
    memset(vs, 0, sizeof(vs));
    s.clear();
    s.resize(n);
    res.clear();
    res.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    Try(0);
    cout << minn << "\n";

    return 0;
}