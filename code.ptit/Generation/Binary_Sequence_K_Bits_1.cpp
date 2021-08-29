/*
 * Hãy in ra tất cả các xâu nhị phân độ dài N,
 * có K bit 1 theo thứ tự từ điển tăng dần.
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int check;

void output(vector<int> a) {
    for (int i = 1; i < a.size(); i++) {
        cout << a[i];
    }
    cout << "\n";
}

void gen(vector<int> &a) {
    int i = a.size() - 1;
    while (a[i] == 1)
        i--;
    if (i > 0) {
        a[i] = 1;
        for (int j = i + 1; j < a.size(); j++) {
            a[j] = 0;
        }
    } else
        check = 1;
}

int kBits1(vector<int> a, int k) {
    int dem = 0;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] == 1)
            ++dem;
    }
    if (dem == k)
        return 1;
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        a.clear();
        check = 0;
        int n, k;
        cin >> n >> k;
        a.resize(n + 1);
        while (!check) {
            if (kBits1(a, k))
                output(a);
            gen(a);
        }
    }
}