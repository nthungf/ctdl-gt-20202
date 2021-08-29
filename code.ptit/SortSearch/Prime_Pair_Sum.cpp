/*
Cho số tự nhiên N. Hãy tìm cặp số nguyên tố
đầu tiên có tổng là N. Nếu không tồn tại cặp
số nguyên tố có tổng bằng N, hãy đưa ra -1.
*/

#include <bits/stdc++.h>
using namespace std;
#define max 1000000

vector<int> p;
void sieve() {
    bool check[max] = {false};
    check[0] = check[1] = true;
    for (int i = 2; i < max; i++) {
        if (!check[i]) {
            for (int j = i * 2; j < max; j += i) {
                check[j] = true;
            }
        }
    }
    for (int i = 0; i < max; i++) {
        if (!check[i])
            p.push_back(i);
    }
}

int isPrime(int n) { return binary_search(p.begin(), p.end(), n); }

int main() {
    int t;
    cin >> t;
    sieve();

    while (t--) {
        int n, check = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            if (isPrime(i) && isPrime(n - i)) {
                cout << i << " " << n - i << "\n";
                check = 1;
                break;
            }
        }
        if (!check)
            cout << "-1\n";
    }
    return 0;
}