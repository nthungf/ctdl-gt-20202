/*
Cho mảng A[] gồm n phần tử và số X.
Hãy đưa sắp xếp các phần tử của mảng theo
trị tuyệt đối của |X - A[i] |.
Ví dụ với A[] = {10, 5, 3, 9, 2} và X = 7
ta đưa ra mảng được sắp xếp theo nguyên tắc
kể trên: A[] = {5, 9, 10, 3, 2} vì
|7-10|=3, |7-5|=2, |7-3|=4, |7-9|=2, |7-2|=5.
*/

#include <bits/stdc++.h>
using namespace std;

struct bla {
    int dat;
    int abs;
};

int cmp(bla x, bla y) { return (x.abs < y.abs); }

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<bla> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].dat;
        }
        for (int i = 0; i < n; i++) {
            a[i].abs = abs(a[i].dat - x);
        }
        sort(a.begin(), a.end(), cmp);
        for (int i = 0; i < a.size(); i++) {
            cout << a[i].dat << " ";
        }
        cout << "\n";
    }
    return 0;
}