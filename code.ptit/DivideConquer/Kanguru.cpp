/*
Có N con kanguru trong vườn thú, con thứ i
có chiều cao bằng A[i].
Con kanguru có chiều cao X có thể chứa được một con
có chiều cao bằng Y trong túi của nó nếu như X >= 2*Y.

Một con đã chứa một con kanguru rồi,
thì không thể nhảy vào túi một con kanguru khác.

Bầy Kanguru rất thích chơi trốn tìm,
vì vậy chúng thường xuyên nhảy vào túi của nhau.
Các bạn hãy tính toán xem trong trường hợp tối ưu,
số con kanguru nhìn thấy trong vườn thú ít nhất bằng bao nhiêu?
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
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        int dem = 0;
        int l = 0, r = n / 2;
        while (l < n / 2 && r < n) {
            if (a[l] >= 2 * a[r]) {
                dem++;
                a[l] = a[r] = -1;
                l++;
                r++;
            } else
                r++;
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] != -1) ++dem;
        }
        cout <<dem<<"\n";
    }
    return 0;
}
