/*
Hãy xây dựng một cây nhị phân tìm kiếm cân bằng từ dãy số
A[] =(a0, a1, .., an-1}.
Đếm số node lá của cây nhị phân tìm kiếm cân bằng.
Ví dụ với dãy A[]={40, 28, 45, 38, 33, 15, 25, 20, 23, 35, 30}
ta sẽ có phép duyệt theo thứ tự trước của cây nhị phân tìm kiếm
cân bằng với số node lá là 5 : 15, 23, 30, 35 45.
*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

int dem;
void preOrder(int l, int r) {
    if (l > r || l >= n || r >= n) return;

    int num = r - l + 1;
    int mid = l + num / 2;
    // if (num % 2 == 0) mid--;
    // int root = a[mid];
    if (l == r) {
        ++dem;
        // cout << root << " ";
    }
    if (mid < n) {
        if (l <= mid - 1) preOrder(l, mid - 1);
        if (mid + 1 <= r) preOrder(mid + 1, r);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        dem = 0;
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        preOrder(0, n - 1);
        cout << dem << "\n";
    }
    return 0;
}