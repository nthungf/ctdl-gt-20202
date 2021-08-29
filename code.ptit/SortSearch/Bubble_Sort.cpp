/*
Hãy thực hiện thuật toán sắp xếp nổi bọt trên dãy N số nguyên.
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
    int buoc = 1;
    while (!sortCheck(a)) {
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        }
        cout << "Buoc " << buoc++ << ": ";
        output(a);
    }

    return 0;
}