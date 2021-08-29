/*
Cho mảng A[] gồm N phần tử chưa được sắp xếp.
Nhiệm vụ của bạn là sắp xếp các phần tử của mảng A[]
theo thứ tự tăng dần bằng thuật toán Merge Sort.
*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int l, int mid, int r) {
    int n1 = mid - l + 1, n2 = r - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = a[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = a[mid + i + 1];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
        }
    }
    while (i < n1) {
        a[k++] = L[i++];
    }
    while (j < n2) {
        a[k++] = R[j++];
    }
}

void mergeSort(vector<int> &a, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
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
        mergeSort(a, 0, n - 1);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}