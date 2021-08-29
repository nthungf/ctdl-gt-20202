/*
Cho hai số nguyên dương S và T (S, T<10000) và hai thao tác (a), (b) dưới đây:
        Thao tác (a): Trừ S đi 1  (S = S-1) ;
        Thao tác (b): Nhân S với 2 ( S = S*2);
Hãy dịch chuyển S thành T sao cho số lần thực hiện các thao tác (a), (b) là ít nhất.
*/

#include <bits/stdc++.h>
using namespace std;
#define max 10000

int test(int s, int t) { return (t == s - 1 || t == s * 2); }
int vs[max], pre[max];

vector<vector<int> > ke(max);

void preCalc() {
    ke[0].push_back(0);
    for (int i = 1; i < max; ++i) {
        ke[i].push_back(i - 1);
        if (i * 2 < max) ke[i].push_back(i * 2);
    }
}

void BFS(int u, int t) {
    memset(vs, 0, sizeof(vs));
    memset(pre, 0, sizeof(pre));
    queue<int> q;
    q.push(u);
    vs[u] = 1;
    pre[u] = -1;
    int ok = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < ke[v].size(); ++i) {
            int x = ke[v][i];
            if (!vs[x] && test(v, x)) {
                q.push(x);
                vs[x] = 1;
                pre[x] = v;
                if (x == t) {
                    ok = 1;
                    break;
                }
            }
        }
        if (ok) break;
    }
    int x = t, dem = 0;
    while (x != u) {
        x = pre[x];
        ++dem;
    }
    cout << dem << "\n";
}

int main() {
    int t;
    cin >> t;
    preCalc();
    while (t--) {
        int s, t;
        cin >> s >> t;
        BFS(s,t);
    }
    return 0;
}
