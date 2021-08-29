/*
Sau khi thi trượt môn Cấu trúc dữ liệu và giải thuật,
một số sinh viên D19 CNTT - PTIT quyết định bỏ học,
đầu tư thuê đất để trồng rau.
Mảnh đất thuê là một hình chữ nhật
N x M (1≤ N≤ 100; 1≤ M≤ 100) ô đất hình vuông.
Nhưng chỉ sau đó vài ngày, trận lụt khủng khiếp
đã diễn ra làm một số ô đất bị ngập.
Mảnh đất bỗng biến thành các cái ao.
Và sinh viên D19 lại dự định chuyển sang nuôi cá.
Các bạn ấy muốn biết mảnh đất được chia thành bao nhiêu cái ao
đểcó thể tính toán nuôi cá cho hợp lý. Hãy giúp các bạn ấy nhé.
Chú ý: Ao là gồm một số ô đất bị ngập có chung đỉnh.
Dễ nhận thấy là một ô đất có thể có tối đa 8 ô chung đỉnh.
*/

#include <bits/stdc++.h>
using namespace std;

int N, M;
char a[110][110];
int vs[110][110];

int xM[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int yM[] = {-1, -1, -1, 0, 0, 1, 1, 1};

struct pos {
    int x, y;
};

bool isSafe(int x, int y) { return 0 <= x && x < N && 0 <= y && y < M && a[x][y] == 'W'; }

void BFS(pos tmp) {
    queue<pos> q;
    q.push(tmp);
    vs[tmp.x][tmp.y] = 1;
    while (!q.empty()) {
        pos v = q.front();
        // cout << v.x << " " << v.y << "\n";
        q.pop();
        for (int i = 0; i < 8; i++) {
            int xN = v.x + xM[i];
            int yN = v.y + yM[i];
            if (isSafe(xN, yN) && !vs[xN][yN]) {
                pos t = {xN, yN};
                q.push(t);
                vs[xN][yN] = 1;
            }
        }
    }
}

int main() {
    // memset(a, 0, sizeof(a));
    cin >> N >> M;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        istringstream is(s);
        for (int j = 0; j < M; j++) {
            a[i][j] = s[j];
        }
    }
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!vs[i][j] && a[i][j] == 'W') {
                pos tmp = {i, j};
                // cout << i << "-" << j << "\n";
                BFS(tmp);
                ++count;
            }
        }
    }
    cout << count << "\n";

    return 0;
}