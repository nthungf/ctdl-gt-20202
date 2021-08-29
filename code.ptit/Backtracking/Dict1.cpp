/*
Cho tập từ ghi trong trừ điển dic[] và một bảng
hai chiều A[M][N] các ký tự.
Hãy tạo nên tất cả các từ có mặt trong từ điển dic[]
bằng cách nối các ký tự kề nhau trong mảng A[][].
Chú ý, phép nối các ký tự kề nhau trong mảng A[][]
được thực hiện theo 8 hướng nhưng không có phần tử
A[i][j] nào được lặp lại.
Ví dụ với từ điển dic[] ={ “GEEKS”, “FOR”, “QIUZ”, “GO”}
và mảng A[][] dưới đây sẽ cho ta kết quả: “GEEKS”, “QUIZ”
*/

#include <bits/stdc++.h>
using namespace std;

int k, m, n;
string dict[120];
string res;
char a[5][5];
int b[5][5];
int check;
int xMove[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int yMove[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void Init() {
    cin >> k >> m >> n;
    res.clear();
    check = 0;
    for (int i = 0; i < k; i++) {
        cin >> dict[i];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            b[i][j] = 0;
        }
    }
}

int Search(string res) {
    for (int i = 0; i < k; i++) {
        if (res == dict[i])
            return 1;
    }
    return 0;
}

int isSafe(int x, int y) {
    return (x >= 0 && y >= 0 && x < m && y < n && !b[x][y]);
}

void Try(int x, int y, string res) {
    if (Search(res)) {
        cout << res << " ";
        check = 1;
    }
    for (int l = 0; l < 8; l++) {
        // cout << res << "\n";
        int next_x = x + xMove[l];
        int next_y = y + yMove[l];
        if (isSafe(next_x, next_y)) {
            b[x][y] = 1;
            Try(next_x, next_y, res + a[next_x][next_y]);
            b[x][y] = 0;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res.clear();
                Try(i, j, res + a[i][j]);
            }
        }
        if (check == 0) {
            cout << "-1";
        }
        cout << "\n";
    }
    return 0;
}