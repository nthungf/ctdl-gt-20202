/*
Cho danh sách liên kết đơn lưu giữ các số nguyên được
quản lý bởi con trỏ First.
Viết chương trình con lọc tất cả các phần tử có giá trị
trùng nhau trong danh sách liên kết đơn First,
chỉ để lại 1 phần tử đại diện cho nhóm trùng.
Sau khi lọc xong, liệt kê các phần tử  trong
danh sách liên kết đơn First.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        for (auto it : a) {
            cout << it << " ";
        }
        cout << "\n";
    }
    return 0;
}