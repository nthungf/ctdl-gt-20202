/*
Một mảng được sắp được chia thành hai đoạn tăng dần
được gọi là mảng sắp xếp vòng.
Ví dụ mảng A[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3, 4}
là mảng sắp xếp vòng.
Cho mảng A[] gồm n phần tử, hãy tìm vị trí của phần tử
x trong mảng A[] với thời gian log(n).
*/

#include <bits/stdc++.h>
using namespace std;

// int binarySearch(vector<int> a, int x) {
//     int left = 0, right = a.size() - 1;
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (x == a[mid]) return mid;
//         else if (x < a[mid])
//             right = mid - 1;
//         else if (x > a[mid])
//             left = mid + 1;
//     }
//     return -1;
// }

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        // sort(a.begin(), a.end());
        // cout << binarySearch(a, x) << "\n";
        for (int i = 0; i < n; i++) {
            if (a[i] == x) {
                cout << i + 1 << "\n";
                break;
            }
        }
    }
    return 0;
}