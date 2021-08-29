/*
Hãy xây dựng một cây nhị phân tìm kiếm cân bằng
từ dãy số A[] =(a0, a1, .., an-1}.
Đưa ra phép duyệt theo thứ tự trước
(preorder) của cây tìm kiếm cân bằng.

Ví dụ với dãy
A[] = {40, 28, 45, 38, 33, 15, 25, 20, 23, 35, 30}
ta sẽ có phép duyệt theo thứ tự trước của
cây nhị phân tìm kiếm cân bằng với node gốc là 33 :
33, 25, 20, 15, 23, 28, 30, 40, 38, 35, 45.
*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

void postOrder(int l, int r) {
    if (l > r || l >= n || r >= n) return;
    int num = r - l + 1;
    int mid = l + num / 2;
    if (num % 2 == 0) mid--;
    int root = a[mid];
    if (l <= mid - 1) postOrder(l, mid - 1);
    if (mid + 1 <= r) postOrder(mid + 1, r);
    cout << root << " ";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int mid = n / 2;
        if (n % 2 == 0) mid--;
        postOrder(0, n - 1);
        cout << "\n";
    }
    return 0;
}