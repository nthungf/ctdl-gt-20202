/*
Cho một dãy N viên bi gồm 3 màu xanh, trắng, đỏ xếp lẫn lộn.
Bằng cách đổi chỗ từng cặp viên bi cho nhau có thể xếp lại dãy bi
trên sao cho các viên bi xanh đứng trước, sau đó đến các viên bi
trắng và cuối cùng là các viên bi đỏ.
Tìm số lượng ít nhất các phép đổi chỗ cần thực hiện
*/

#include <bits/stdc++.h>
using namespace std;

int find_index(int p, vector<int> &a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] == p) return i;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'X') a[i] = 1;
        else if (s[i] == 'T')
            a[i] = 2;
        else if (s[i] == 'D')
            a[i] = 3;
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            res++;
            swap(a[i], a[find_index(b[i], a)]);
        }
    }
    cout << res << "\n";

    return 0;
}