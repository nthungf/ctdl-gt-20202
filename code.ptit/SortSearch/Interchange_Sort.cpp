/*
Hãy thực hiện thuật toán sắp xếp đổi chỗ trực tiếp trên dãy N số nguyên.
Ghi ra các bước thực hiện thuật toán.
Dữ liệu vào:
Dòng 1 ghi số N (không quá 100).
Dòng 2 ghi N số nguyên dương (không quá 100).
Kết quả:
Ghi ra màn hình từng bước thực hiện thuật toán.
Mỗi bước trên một dòng, các số trong dãy cách nhau đúng một khoảng trống.
*/

#include <bits/stdc++.h>
using namespace std;

void output(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int sortCheck(vector<int> a) {
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] > a[i + 1])
            return 0;
    }
    return 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int i = 0, buoc = 1;
    while (i < n && !sortCheck(a)) {
        cout << "Buoc " << buoc++ << ": ";
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i])
                swap(a[j], a[i]);
        }
        output(a);
        ++i;
    }

    return 0;
}