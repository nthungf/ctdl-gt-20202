/*
Cho mảng A[] gồm n phần tử. Hãy tìm dãy con liên tục
của mảng A[R], .., A[L] sao cho khi sắp xếp lại dãy con
ta nhận được một mảng được sắp xếp.
Ví dụ với A[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60}
ta chỉ cần sắp xếp lại dãy con từ A[4],.., A[9]:
{30, 25, 40, 32, 31, 35} để có mảng được sắp.
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
        vector<int> b = a;
        sort(a.begin(), a.end());

        int l = 0, r = n - 1;
        int i = 0;
        while (a[i] == b[i]) {
            l++;
            i++;
        }
        i = n - 1;
        while (a[i] == b[i]) {
            r--;
            i--;
        }
        cout << l + 1 << " " << r + 1 << "\n";
    }
    return 0;
}