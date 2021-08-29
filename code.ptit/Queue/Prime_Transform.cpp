/*
Problem
*/

#include <bits/stdc++.h>
using namespace std;
#define max 10000

int check[max] = {0}, vs[max] = {0};
vector<int> p;

int res;

void preCalc() {
    for (int i = 2; i < max; ++i)
        if (check[i] == 0)
            for (int j = 2 * i; j < max; j += i) check[j] = 1;

    for (int i = 1000; i < max; ++i)
        if (!check[i]) p.push_back(i);
}

int oneDiff(int s, int t) {
    int dem = 0;
    while (s > 0) {
        if (s % 10 != t % 10) ++dem;
        if (dem > 1) break;
        s /= 10;
        t /= 10;
    }
    return (dem == 1);
}

void BFS(int u, int t) {
    res = 0;
    for (int i = 0; i < max; ++i) vs[i] = 0;
    queue<int> q;
    q.push(u);
    vs[u] = 1;
    int ok = 0, dem = 0;
    int pre[max] = {0};
    pre[u] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int x = 0; x < p.size(); ++x) {
            int i = p[x];
            if (oneDiff(v, i) && !vs[i]) {
                // cout << v << " " << i << "\n";
                q.push(i);
                vs[i] = 1;
                pre[i] = v;
                if (i == t) {
                    ok = 1;
                    break;
                }
            }
        }
        if (ok) break;
    }
    int x = t;
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
        BFS(s, t);
    }
    return 0;
}
