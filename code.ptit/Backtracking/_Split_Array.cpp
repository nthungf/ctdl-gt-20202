/*
Cho mảng các số nguyên A[] gồm N phần tử.
Hãy chia mảng số nguyên A[] thành K tập con khác rỗng
sao cho tổng các phần tử của mỗi tập con đều bằng nhau.
Mỗi phần tử thuộc tập con xuất hiện duy nhất một lần
trong tất cả các tập con.
Ví dụ với A[] = {2, 1, 4, 5, 6}, K = 3
ta có kết quả {2, 4}, {1, 5}, {6}.
*/

#include <bits/stdc++.h>
using namespace std;
#define max 30

int n, k, sumarray, sum, dem, check;
int used[max];

vector<int> a;

vector<int> store;

void Init() {
    store.clear();
    sumarray = 0;
    sum = 0;
    check = 0;
    dem = 0;
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sumarray += a[i];
        used[i] = 0;
    }
}

void Result() {
    for (auto i : store) {
        cout << i << " ";
    }
}

void Mark() {
    for (int i = 0; i < store.size(); i++) {
        a.erase(remove(a.begin(), a.end(), store[i]), a.end());
    }
}

void A() {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    // cout << "\n";
}

// phan tu thu i
void Try(int i) {
    for (int j = 0; j < n; j++) {
        if (!used[j]) {
            sum += a[j];
            store.push_back(a[j]);
            used[j] = 1;
            if (sum == sumarray) {
                // Result();
                // A();
                // cout << " -->  ";
                Mark();
                // A();
                // cout << "= " << sum << "\n";
                check = 1;
                i = 0;
                store.clear();
                sum = 0;
                ++dem;
                return;
            } else if (sum < sumarray) {
                Try(i + 1);
            }
            if (sum > 0)
                sum -= a[j];
            if (!store.empty())
                store.pop_back();
            used[j] = 0;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        if (sumarray % k != 0) {
            cout << 0;
        } else {
            // sort(a, a + n);
            sort(a.begin(), a.end());
            sumarray /= k;
            Try(0);
            // cout << dem;
            dem == k ? cout << 1 : cout << 0;
        }
        cout << "\n";
    }
    return 0;
}