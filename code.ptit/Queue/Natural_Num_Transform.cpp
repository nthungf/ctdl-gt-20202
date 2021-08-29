/*
Cho số tự nhiên N (N<10^9) và hai phép biến đổi (a), (b) dưới đây.
    Thao tác (a): Trừ N đi 1 (N=N-1).
    Thao tác (b): N = max(u,v) nếu u*v =N (u>1, v>1).
Chỉ được phép sử dụng hai thao tác (a) hoặc (b),
hãy biến đổi N thành 1 sao số các thao tác (a), (b)
được thực hiện ít nhất.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void BFS(int n) {
    set<int> vs;
    queue<pair<int, int> > q;
    q.push(make_pair(n, 0));
    vs.insert(n);
    while (!q.empty()) {
        int v = q.front().first;
        int vc = q.front().second;
        if (v == 2) {
            cout << vc + 1 << "\n";
            break;
        }
        q.pop();
        for (int i = 2; i * i <= v; i++) {
            if (v % i == 0) {
                int x = v / i;
                if (vs.find(x) == vs.end()) {
                    q.push(make_pair(x, vc + 1));
                    vs.insert(x);
                }
            }
        }
        if (vs.find(v - 1) == vs.end()) {
            q.push(make_pair(v - 1, vc + 1));
            vs.insert(v - 1);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        BFS(n);
    }
    return 0;
}