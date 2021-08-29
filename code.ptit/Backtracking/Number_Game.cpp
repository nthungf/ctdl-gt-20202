/*
Nam có N thẻ bài, mỗi thẻ ghi một con số từ 1 tới N.
Không có 2 thẻ nào ghi hai số trùng nhau.
Nam muốn xếp thứ tự các thẻ bài sao cho không có hai con số nào
liền kề nhau ở cạnh nhau.

Ví dụ với N = 4 thì cách xếp 3142 là hợp lệ nhưng cách xếp 1324 không hợp lệ.

Hãy giúp Nam liệt kê tất cả các cách xếp thỏa mãn theo thứ tự từ điển.
*/

#include <bits/stdc++.h>
using namespace std;

int a[10], vs[10];
int n;

void output() {
    for (int i = 1; i <= n; i++) {
        cout << a[i];
    }
    cout << "\n";
}

void Try(int i) {
    int x = a[i - 1];
    for (int j = 1; j <= n; j++) {
        if (!vs[j] && j != x + 1 && j != x - 1) {
            a[i] = j;
            vs[j] = 1;
            if (i == n) {
                output();
            } else
                Try(i + 1);
            vs[j] = 0;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(vs, 0, sizeof(vs));
        a[0] = -1;
        Try(1);
    }
    return 0;
}