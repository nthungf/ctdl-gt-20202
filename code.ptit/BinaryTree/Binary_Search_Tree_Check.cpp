/*
Cho một mảng A[] gồm N phần tử. Nhiệm vụ của bạn là đưa ra 1 nếu mảng A[]
biểu diễn phép duyệt inorder của cây nhị phân tìm kiếm, ngược lại đưa ra 0.
*/

#include <bits/stdc++.h>
using namespace std;

bool Check(vector<int> a) {
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] >= a[i + 1]) return false;
    }
    return true;
}

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
        if (Check(a)) cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}