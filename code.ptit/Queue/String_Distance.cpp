/*
Cho tập n xâu ký tự S và hai xâu s, t Î S.
Ta giả thiết các xâu ký tự S[i] Î S có độ dài bằng nhau.
Hãy tìm khoảng cách đường đi ngắn nhất từ s đến t.
Biết từ một xâu ký tự bất kỳ ta chỉ được phép dịch chuyển
đến xâu khác với nó duy nhất 1 ký tự
*/

#include <bits/stdc++.h>
using namespace std;

struct xau {
    string str;
    int lev, idx;
};

vector<xau> S;
int n;
string s, t;
xau st, en;
vector<xau> ke[1010];

bool oneDiff(string s, string t) {
    int dem = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != t[i]) ++dem;
        if (dem > 1) return false;
    }
    return (dem == 1);
}

void Init() {
    cin >> n;
    cin >> s >> t;
    S.clear();
    S.resize(n);
    for (int i = 0; i < 1010; i++) ke[i].clear();
    for (int i = 0; i < n; ++i) {
        cin >> S[i].str;
        S[i].idx = i;

        if (S[i].str == s) {
            S[i].lev = 1;
            st = S[i];
        } else if (S[i].str == t)
            en = S[i];

        for (int j = 0; j < i; j++) {
            if (oneDiff(S[i].str, S[j].str)) {
                ke[i].push_back(S[j]);
                ke[j].push_back(S[i]);
            }
        }
    }
}

void BFS() {
    unordered_map<string, int> vs;
    queue<xau> q;
    q.push(st);
    // cout << st.lev << "\n";
    vs.insert({s, 1});
    while (!q.empty()) {
        xau v = q.front();
        q.pop();
        // cout << v.str << "\n";
        if (v.str == t) {
            cout << v.lev << "\n";
            break;
        }
        if (!ke[v.idx].empty())
            for (int i = 0; i < ke[v.idx].size(); ++i) {
                xau vv = ke[v.idx][i];
                if (vs.find(vv.str) == vs.end()) {
                    xau tmp = {vv.str, v.lev + 1, vv.idx};
                    q.push(tmp);
                    vs.insert({vv.str, v.lev + 1});
                }
            }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        BFS();
        // for (int i = 0; i < n; i++) {
        //     cout << S[i].str << ": ";
        //     for (int j = 0; j < ke[i].size(); j++) {
        //         cout << ke[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }
    return 0;
}
