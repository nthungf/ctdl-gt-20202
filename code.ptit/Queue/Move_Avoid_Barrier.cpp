/*
Cho một bảng kích thước N x N, trong đó có các ô trống ‘.’
và vật cản ‘X’. Các hàng và các cột được đánh số từ 0.

Mỗi bước di chuyển, bạn có thể đi từ ô (x, y) tới ô (u, v)
nếu như 2 ô này nằm trên cùng một hàng hoặc một cột,
và không có vật cản nào ở giữa.

Cho điểm xuất phát và điểm đích.
Bạn hãy tính số bước di chuyển ít nhất?
*/
// build graph and bfs

#include <bits/stdc++.h>
using namespace std;

struct pos {
    int x, y;
    bool operator!=(const pos &p) { return (p.x != x || p.y != y); }
    // bool operator=(pos p) { p.x = x || p.y = y; }
};

vector<pos> ke[110][110];
pos pre[110][110];
bool vs[110][110];
char a[110][110];
int n;

void Init() {
    cin >> n;
    for (int i = 0; i < 110; i++)
        for (int j = 0; j < 110; j++) {
            ke[i][j].clear();
        }

    memset(a, 0, sizeof(a));
    memset(vs, 0, sizeof(vs));
    memset(pre, 0, sizeof(pre));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];
}

void buildGraph(int x, int y) {
    int i, j;
    // cùng hàng x bên phải
    i = x;
    j = y - 1;
    while (j >= 0 && a[i][j] == '.') {
        ke[x][y].push_back({i, j});
        j--;
    }
    // cùng hàng x bên trái
    i = x;
    j = y + 1;
    while (j < n && a[i][j] == '.') {
        ke[x][y].push_back({i, j});
        j++;
    }
    // cùng cột y bên trên
    i = x - 1;
    j = y;
    while (i >= 0 && a[i][j] == '.') {
        ke[x][y].push_back({i, j});
        i--;
    }
    // cùng cột y bên dưới
    i = x + 1;
    j = y;
    while (i < n && a[i][j] == '.') {
        ke[x][y].push_back({i, j});
        i++;
    }
}

void BFS(pos start, pos end) {
    queue<pos> q;
    q.push(start);
    vs[start.x][start.y] = 1;
    while (!q.empty()) {
        pos front = q.front();
        // cout << a[front.x][front.y] << "\n";
        // cout << front.x << " " << front.y << "\n";
        q.pop();
        int x = front.x, y = front.y;
        for (int i = 0; i < ke[x][y].size(); i++) {
            pos next = ke[x][y][i];
            if (!vs[next.x][next.y]) {
                q.push(next);
                pre[next.x][next.y] = front;
                vs[next.x][next.y] = true;
            }
        }
    }
    int dem = 0;
    pos tmp = end;
    while (tmp != start) {
        ++dem;
        tmp = pre[tmp.x][tmp.y];
    }
    cout << dem << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == '.') buildGraph(i, j);
            }
        }
        pos start, end;
        cin >> start.x >> start.y >> end.x >> end.y;
        BFS(start, end);
    }
    return 0;
}