/*
Hãy xây dựng một cây nhị phân tìm kiếm cân bằng từ dãy số
A[] =(a0, a1, .., an-1}.
Đưa ra nội dung node gốc của cây tìm kiếm cân bằng.
Ví dụ với dãy A[]={40, 28, 45, 38, 33, 15, 25, 20, 23, 35, 30}
ta sẽ có cây nhị phân tìm kiếm cân bằng với node gốc là 33.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int mid = n / 2;
        if (n % 2 == 0) mid = n / 2 - 1;
        sort(a.begin(), a.end());
        cout << a[mid] << "\n";
    }
    return 0;
}