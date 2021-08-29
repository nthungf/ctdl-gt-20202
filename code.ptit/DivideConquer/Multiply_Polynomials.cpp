/*
Cho hai đa thức P và Q được biểu diễn như một mảng
bao gồm các hệ số của đa thức.
Ví dụ với P(x) = 5 + 0x1 +10x2 + 6x3 được biểu diễn
như mảng P[] ={5, 0, 10, 6}.
Hãy đưa ra đa thức R = P×Q theo các hệ số của R
với cách biểu diễn như trên.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int M, N;
        cin >> M >> N;
        vector<int> P(M), Q(N);
        for (int i = 0; i < M; ++i) {
            cin >> P[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> Q[i];
        }
        vector<int> R(M + N);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int gtri = P[i] * Q[j];
                int heso = i + j;
                R[heso] += gtri;
            }
        }
        for (int i = 0; i < M + N - 1; ++i) {
            cout << R[i] << " ";
        }
        cout <<"\n";
    }
    return 0;
}
