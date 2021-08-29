/*
Cho ba số N, P, S. Trong đó, P là một số nguyên tố.
Nhiệm vụ của bạn là đưa ra tất cả N số nguyên tố
tính từ P có tổng bằng S.
Ví dụ với S = 28, P=7, N =2
ta có kết quả 11 + 17 = 28.
Với N = 3, P = 2, S = 23
ta có kết quả : {3, 7, 13}, {5, 7, 11}
*/

#include <bits/stdc++.h>
using namespace std;
#define max 300

int sum, dem;
vector<int> prime, res, used;
vector<vector<int> > resss;
vector<bool> check(max);

void sieve(int p, int s) {
    for (int i = 2; i <= s; i++) {
        if (!check[i]) {
            for (int j = i + i; j <= s; j += i) {
                check[j] = true;
            }
        }
    }
    for (int i = 2; i <= s; i++) {
        if (!check[i] && p < i) {
            prime.push_back(i);
        }
    }
}

void Output() {
    for (int i = 0; i < resss.size(); i++) {
        for (int j = 0; j < resss[i].size(); j++) {
            cout << resss[i][j] << " ";
        }
        cout << "\n";
    }
}

void Try(int x, int n, int s) {
    for (int j = x; j < prime.size(); j++) {
        if (!used[j]) {
            sum += prime[j];
            res.push_back(prime[j]);
            if (sum == s && res.size() == n) {
                resss.push_back(res);
                dem++;
            } else if (sum < s) {
                Try(j + 1, n, s);
            }
            sum -= prime[j];
            res.pop_back();
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        sum = 0;
        dem = 0;
        prime.clear();
        res.clear();
        resss.clear();
        fill(check.begin(), check.end(), false);
        int n, p, s;
        cin >> n >> p >> s;
        sieve(p, s);
        used.clear();
        used.resize(prime.size());
        //
        Try(0, n, s);
        cout << dem << "\n";
        Output();
    }
    return 0;
}