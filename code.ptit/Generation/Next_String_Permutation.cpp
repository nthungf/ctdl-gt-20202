/*
 * Hãy viết chương trình nhận vào một chuỗi
 * (có thể khá dài) các ký tự số và đưa ra màn hình
 * hoán vị kế tiếp của các ký tự số đó
 * (với ý nghĩa là hoán vị có giá trị lớn hơn
 * tiếp theo nếu ta coi chuỗi đó là một giá trị số nguyên).
 * Chú ý: CÁC KÍ TỰ SỐ TRONG DÃY CÓ THỂ TRÙNG NHAU.
 */

#include <bits/stdc++.h>
using namespace std;

int ok = 1;

void nextPermutation(string &n) {
    int i = n.size() - 2;
    while (n[i] >= n[i + 1])
        i--;
    if (i > 0) {
        int k = n.size() - 1;
        while (n[k] <= n[i])
            k--;
        swap(n[k], n[i]);
        int l = i + 1, r = n.size() - 1;
        while (l <= r) {
            swap(n[l], n[r]);
            l++;
            r--;
        }
    } else
        ok = 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ok = 1;
        string m, n;
        cin >> m >> n;
        nextPermutation(n);
        cout << m << " ";
        if (ok)
            cout << n;
        else
            cout << "BIGGEST";
        cout << "\n";
    }
}