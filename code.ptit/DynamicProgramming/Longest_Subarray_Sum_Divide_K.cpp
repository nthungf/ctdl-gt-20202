/*
Cho một dãy gồm n ( n ≤ 1000) số nguyên dương A1, A2, ..., An
và số nguyên dương k (k ≤ 50).
Hãy tìm dãy con gồm nhiều phần tử nhất của dãy đã cho
sao cho tổng các phần tử của dãy con này chia hết cho k.
*/

// https://www.geeksforgeeks.org/longest-subarray-sum-divisible-k/

#include <bits/stdc++.h>
using namespace std;

int n, k, sum, maxx;

int main() {
    int t;
    cin >> t;
    while (t--) {
        sum = 0;
        maxx = 0;
        cin >> n >> k;
        vector<int> a(n), mod(n);
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            mod[i] = sum % k;
        }
        for (int i = 0; i < n; i++) {
            if (mod[i] == 0) maxx = i + 1;
            else if (map.find(mod[i]) == map.end()) {
                map[mod[i]] = i;
            } else {
                int j = i - map[mod[i]];
                if (maxx < j) {
                    maxx = j;
                }
            }
        }
        cout << maxx << "\n";
    }
    return 0;
}