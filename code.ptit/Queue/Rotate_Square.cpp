/*
Có một chiếc bảng hình chữ nhật với 6 miếng ghép,
trên mỗi miếng ghép được điền một số nguyên trong khoảng từ 1 đến 6.
Tại mỗi bước, chọn một hình vuông (bên trái hoặc bên phải),
rồi quay theo chiều kim đồng hồ.
Yêu cầu: Cho một trạng thái của bảng, hãy tính số phép biến đổi
ít nhất để đưa bảng đến trạng thái đích.
*/

#include <bits/stdc++.h>
using namespace std;

struct table {
    char a1, a2, a3;
    char b1, b2, b3;
    bool operator==(table &p) {
        return (p.a1 == a1 && p.a2 == a2 && p.a3 == a3 && p.b1 == b1 && p.b2 == b2 && p.b3 == b3);
    }
};

table Rotate_Left(table x) {
    table tmp = x;
    tmp.a1 = x.b1;
    tmp.a2 = x.a1;
    tmp.b2 = x.a2;
    tmp.b1 = x.b2;
    return tmp;
}

table Rotate_Right(table x) {
    table tmp = x;
    tmp.a2 = x.b2;
    tmp.a3 = x.a2;
    tmp.b3 = x.a3;
    tmp.b2 = x.b3;
    return tmp;
}

void output(table x) {
    cout << x.a1 << " " << x.a2 << " " << x.a3 << "\n"
         << x.b1 << " " << x.b2 << " " << x.b3 << "\n";
}

void BFS(table a, table b) {
    table pre[7][7][7][7][7][7];
    memset(pre, 0, sizeof(pre));
    bool vs[7][7][7][7][7][7];
    memset(vs, 0, sizeof(vs));

    queue<table> q;
    q.push(a);
    // output(a);
    vs[a.a1 - '0'][a.a2 - '0'][a.a3 - '0'][a.b1 - '0'][a.b2 - '0'][a.b3 - '0'] = true;

    while (!q.empty()) {
        table v = q.front();
        // output(v);
        q.pop();
        if (v == b) break;
        table vl = Rotate_Left(v);
        table vr = Rotate_Right(v);
        if (!vs[vl.a1 - '0'][vl.a2 - '0'][vl.a3 - '0'][vl.b1 - '0'][vl.b2 - '0'][vl.b3 - '0']) {
            q.push(vl);
            pre[vl.a1 - '0'][vl.a2 - '0'][vl.a3 - '0'][vl.b1 - '0'][vl.b2 - '0'][vl.b3 - '0'] = v;
            vs[vl.a1 - '0'][vl.a2 - '0'][vl.a3 - '0'][vl.b1 - '0'][vl.b2 - '0'][vl.b3 - '0'] = true;
        }
        if (!vs[vr.a1 - '0'][vr.a2 - '0'][vr.a3 - '0'][vr.b1 - '0'][vr.b2 - '0'][vr.b3 - '0']) {
            q.push(vr);
            pre[vr.a1 - '0'][vr.a2 - '0'][vr.a3 - '0'][vr.b1 - '0'][vr.b2 - '0'][vr.b3 - '0'] = v;
            vs[vr.a1 - '0'][vr.a2 - '0'][vr.a3 - '0'][vr.b1 - '0'][vr.b2 - '0'][vr.b3 - '0'] = true;
        }
    }
    table tmp = b;
    int dem = 0;
    while (!(tmp == a)) {
        tmp =
            pre[tmp.a1 - '0'][tmp.a2 - '0'][tmp.a3 - '0'][tmp.b1 - '0'][tmp.b2 - '0'][tmp.b3 - '0'];
        ++dem;
    }
    cout << dem << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        table a, b;
        cin >> a.a1 >> a.a2 >> a.a3 >> a.b1 >> a.b2 >> a.b3;
        cin >> b.a1 >> b.a2 >> b.a3 >> b.b1 >> b.b2 >> b.b3;
        // output(a);
        // output(Rotate_Left(a));
        // output(Rotate_Right(a));
        // output(b);
        BFS(a,b);
    }
    return 0;
}
