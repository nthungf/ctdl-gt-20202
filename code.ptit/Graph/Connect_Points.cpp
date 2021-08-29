/*
Cho N điểm trên mặt phẳng Oxy.
Để vẽ được đoạn thẳng nối A và B sẽ tốn chi phí
tương đương với khoảng cách từ A tới B.

Nhiệm vụ của bạn là nối các điểm với nhau, sao cho
N điểm đã cho tạo thành 1 thành phần liên thông duy nhất
và chi phí để thực hiện là nhỏ nhất có thể.
*/

#include <bits/stdc++.h>
using namespace std;

struct point {
    float x, y;
};

struct edge {
    int start, end;
    float d;
};

bool cmp(edge x, edge y) {
    if (x.d != y.d) return x.d < y.d;
    if (x.start != y.start) return x.start < y.start;
    return x.end < y.end;
}

int vs[110];
vector<edge> e;
int n;

void Kruskal() {
    float wt = 0;
    int k = 0;
    for (int i = 0; i < e.size(); i++) {
        // chon duoc canh e[i]
        if (!(vs[e[i].start] == 0 && vs[e[i].start] == vs[e[i].end])) {
            k++;
            cout << k << "\n";
            wt += e[i].d;
            if (k == n - 1) {
                cout << "wt: " << wt << "\n";
                return;
            }
        }
        int u = e[i].start, v = e[i].end;
        if (!vs[u] && !vs[v]) {
            vs[u] = vs[v] = k;
        } else if (!vs[u] && vs[v]) {
            vs[u] = vs[v];
        } else if (vs[u] && !vs[v]) {
            vs[v] = vs[u];
        } else if (vs[u] < vs[v]) {
            for (int j = 1; j <= n; j++) {
                if (vs[j] == vs[v]) vs[v] = vs[u];
            }
        } else if (vs[u] > vs[v]) {
            for (int j = 1; j <= n; j++) {
                if (vs[j] == vs[u]) vs[u] = vs[v];
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        e.clear();
        vector<point> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i].x >> a[i].y;
            for (int j = 1; j < i; j++) {
                float xx = a[i].x - a[j].x;
                float yy = a[i].y - a[j].y;
                float d = sqrtf(xx * xx + yy * yy);
                // cout << d << "\n";
                // e.push_back({i, j, d});
                e.push_back({j, i, d});
            }
        }
        sort(e.begin(), e.end(), cmp);

        for (int i = 0; i < e.size(); i++) {
            cout << e[i].start << " " << e[i].end << " " << e[i].d << "\n";
        }

        Kruskal();
    }
    return 0;
}