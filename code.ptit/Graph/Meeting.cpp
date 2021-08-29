/*
Có K người (1 ≤ K ≤ 100) đứng tại vị trí nào đó trong
N địa điểm cho trước (1 ≤ N ≤ 1,000) được đánh số từ 1..N.
Các điểm được nối với nhau bởi M đoạn đường một chiều
(1 ≤ M ≤ 10,000)
(không có đoạn đường nào nối một điểm với chính nó).

Mọi người muốn cùng tụ họp tại một địa điểm nào đó.
Tuy nhiên, với các đường đi cho trước, chỉ có một số
địa điểm nào đó có thể được chọn là điểm họp mặt.
Cho trước K, N, M và vị trí ban đầu của K người
cùng với M đường đi  một chiều, hãy xác định xem có
bao nhiêu điểm có thể được chọn làm điểm họp mặt.

Input
    Dòng 1: Ghi 3 số: K, N, và M
    Dòng 2 đến K+1: dòng i+1 chứa một số nguyên trong khoảng
        (1..N) cho biết địa điểm mà người thứ i đang đứng.
    Dòng K+2 đến M+K+1: Mỗi dòng ghi một cặp số A và B mô tả
        một đoạn đường đi một chiều từ A đến B
        (cả hai trong khoảng 1..N và A != B).
Output
    Số địa điểm có thể được chọn là điểm họp mặt.
*/

#include <bits/stdc++.h>
using namespace std;

int K, N, M;

int a[1010] = {0};
int vs[1010] = {0};
vector<int> ke[1010];

int BFS(int u) {
    int dem = 0;
    memset(vs, 0, sizeof(vs));
    queue<int> q;
    q.push(u);
    vs[u] = 1;
    while (!q.empty()) {
        int v = q.front();
        if (a[v] == 1) ++dem;
        q.pop();
        for (int i = 0; i < ke[v].size(); i++) {
            int vv = ke[v][i];
            if (!vs[vv]) {
                q.push(vv);
                vs[vv] = 1;
            }
        }
    }
    return dem;
}

int main() {
    cin >> K >> N >> M;
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    for (int i = 0; i < M; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        ke[v2].push_back(v1);
    }
    int count = 0;
    for (int i = 1; i <= N; i++) {
        // cout << BFS(i) << "\n";
        if (BFS(i) == K) ++count;
    }
    cout << count << "\n";

    return 0;
}