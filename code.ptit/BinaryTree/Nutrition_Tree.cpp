/*
Cho một cây có N đỉnh và gốc tại đỉnh 1.
Mỗi nút lá có chức năng tổng hợp chất dinh dưỡng,
đồng thời lan truyền năng lượng cũng như các chất dinh dưỡng
cho nút cha của nó để thực hiện quá trình tổng hợp.

Quá trình lan truyền năng lượng sẽ làm tăng giá trị dinh dưỡng lên 1.
Tức là nếu một nút tổng hợp được giá trị dinh dưỡng bằng V,
sẽ giúp cho nút cha của nó sẽ tổng hợp được giá trị dinh dưỡng bằng V+1.
Nếu một nút cha có nhiều nút con, giá trị dinh dưỡng của nó bằng
tổng của giá trị dinh dưỡng của các nút con gửi lên.

Biết rằng mỗi nút lá ban đầu tổng hợp được chất dinh dưỡng có giá trị 1.
Nhiệm vụ của bạn là hãy xác định xem mỗi nút của cây tổng hợp được
bao nhiêu giá trị dinh dưỡng?

Input:
    Dòng đầu tiên là số lượng đỉnh N (N <= 200 000).
    Dòng tiếp theo gồm N-1 số nguyên, a[2], a[3], …, a[N]
    lần lượt là cha của các nút 2, 3, …, N.

Output:
    In ra N số nguyên, số nguyên thứ i cho biết giá trị
    dinh dưỡng mà nút i tổng hợp được.
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int pre[200010];
int a[200010];

void Sum(int u) {
    int ok = 0;
    for (int i = 1; i <= n; i++) {
        // u co node con i
        if (pre[i] == u) {
            ok = 1;
            Sum(i);
            a[u] += (a[i] + 1);
            // a[u]++;
        }
    }
    // u ko co node con => node la
    if (!ok) a[u] = 1;
    return;
}

int main() {
    memset(pre, 0, sizeof(pre));
    // memset(a, 0, sizeof(a));
    for (int i = 0; i < 200010; i++) a[i] = 1;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> pre[i];
    }
    Sum(1);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}