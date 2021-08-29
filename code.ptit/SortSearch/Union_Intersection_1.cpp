/*
Cho mảng A[] gồm n phần tử, mảng B[] gồm m phần tử khác nhau.
Các phần tử của mảng A[] và B[] đã được sắp xếp.
Hãy tìm mảng hợp và giao được sắp giữa A[] và B[].
Ví dụ với A[] = {1, 3, 4, 5, 7}, B[]={2, 3, 5, 6}
ta có mảng hợp Union = {1, 2, 3, 4, 5, 6, 7},
mảng giao Intersection = {3, 5}.
In ra đáp án theo giá trị phần tử từ nhỏ đến lớn.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m), c;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            c.push_back(a[i]);
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
            c.push_back(b[i]);
        }
        sort(c.begin(), c.end());
        int x = c.size() + 1;
        vector<int> dem{x};
        for (int i = 1; i < c.size(); ++i) {
            if (c[i] == c[i - 1]) dem[i] = dem[i - 1] + 1;
        }
        // for (int i = 0; i < c.size(); ++i) {
        //     cout << c[i] << " " << dem[i] << "\n";
        // }
        for (int i = 0; i < c.size(); ++i) {
            if (dem[i] == 0) cout << c[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < c.size(); ++i) {
            if (dem[i] == 1) cout << c[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
