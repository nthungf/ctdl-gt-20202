/*
Cho hai số N, K và một tập con K phần tử
X[] =(X1, X2,.., XK) của 1, 2, .., N.
Nhiệm vụ của bạn là hãy đưa ra tập con K phần tử
trước đó của X[]. Ví dụ N=5, K=3, X[] ={2, 3, 5}
thì tập con trước đó của X[] là {2, 3, 4}.
Chú ý nếu tập con trong input là đầu tiên thì
trước đó là tập con cuối cùng.
*/

#include <bits/stdc++.h>
using namespace std;

int ok = 1;

void nextCombination(vector<int> &s, int n, int k) {
    int i = k;
    while (i > 0 && s[i] == n - k + i)
        i--;
    if (i > 0) {
        s[i]++;
        for (int j = i + 1; j <= k; j++) {
            s[j] = s[i] + j - i;
        }

    } else
        ok = 0;
}

void output(vector<int> a) {
    for (int i = 1; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ok = 1;
        int n, k;
        cin >> n >> k;
        vector<int> input(k + 1);
        for (int i = 1; i <= k; i++) {
            cin >> input[i];
        }
        vector<int> s(k + 1);
        for (int i = 1; i <= k; i++) {
            s[i] = i;
        }
        vector<int> tmp;
        for (int i = n - k; i <= n; i++) {
            tmp.push_back(i);
        }

        int check = 0;
        while (ok) {
            if (input == s) {
                check = 1;
                break;
            }
            tmp = s;
            nextCombination(s, n, k);
        }
        if (check == 1)
            output(tmp);
    }
    return 0;
}