/*
Cho xâu nhị phân X[], nhiệm vụ của bạn là hãy
đưa ra xâu nhị phân tiếp theo của X[].
Ví dụ X[] =”010101” thì xâu nhị phân
tiếp theo của X[] là “010110”.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string x;
        cin >> x;
        int j = x.size() - 1;
        while (x[j] == '1') j--;
        if (j == -1) {
            for (int i = 0; i < x.size(); i++) {
                cout << '0';
            }
            cout << '\n';
            continue;
        }
        x[j] = '1';

        for (int i = j + 1; i < x.size(); i++) {
            x[i] == '0' ? x[i] = '1' : x[i] = '0';
        }
        cout << x << "\n";
    }
    return 0;
}