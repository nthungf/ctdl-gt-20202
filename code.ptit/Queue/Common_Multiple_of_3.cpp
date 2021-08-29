/*
Cho dãy số A[] có N phần tử là các chữ số từ 0 đến 9.
Nhiệm vụ của bạn là hãy chọn lấy một tổ hợp các phần tử và
sắp xếp chúng sao cho thu được số lớn nhất chia hết cho 3.
Nếu không tìm được số nào, in ra -1.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> du0, du1, du2;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
            if (x % 3 == 0) du0.push_back(x);
            else if (x % 3 == 1)
                du1.push_back(x);
            else if (x % 3 == 2) {
                du2.push_back(x);
            }
        }
        sort(du0.begin(), du0.end(), greater<int>());
        sort(du1.begin(), du1.end(), greater<int>());
        sort(du2.begin(), du2.end(), greater<int>());
        int ok = 1;
        if (sum % 3 == 1) {
            if (!du1.empty()) du1.pop_back();
            else
                ok = 0;
        } else if (sum % 3 == 2) {
            if (!du2.empty()) du2.pop_back();
            else {
                if (!du1.empty()) {
                    if (!du0.empty()) {
                        du1.pop_back();
                        du0.pop_back();
                    } else {
                        if (du1.size() >= 2) {
                            du1.pop_back();
                            du1.pop_back();
                        } else {
                            ok = 0;
                        }
                    }
                }
            }
        }
        if (ok) {
            vector<int> res = du0;
            for (int i = 0; i < du1.size(); i++) {
                res.push_back(du1[i]);
            }
            for (int i = 0; i < du2.size(); i++) {
                res.push_back(du2[i]);
            }
            sort(res.begin(), res.end(), greater<int>());
            if (res[0] == 0) {
                cout << "0\n";
                break;
            }
            for (int i = 0; i < res.size(); i++) {
                cout << res[i];
            }
            cout << "\n";
        } else
            cout << "-1\n";
    }
    return 0;
}