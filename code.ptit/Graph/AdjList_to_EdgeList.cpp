/*
Cho đơn đồ thị G vô hướng liên thông
được mô tả bởi danh sách kề.
Hãy in ra danh sách cạnh tương ứng của G.
*/

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v1, v2;
};
struct Adjacency {
    int v;
    vector<int> vv;
};
int cmp(Edge x, Edge y) {
    if (x.v1 != y.v1)
        return x.v1 < y.v1;
    return x.v2 < y.v2;
}

int cmpp(Edge x, Edge y) { return (x.v1 == y.v1 && x.v2 == y.v2); }

int strToInt(string s) {
    int num;
    for (int i = 0; i < s.size(); i++) {
        num = num * 10 + (s[i] - '0');
    }
    return num;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<Adjacency> ad;
    for (int i = 1; i <= n; i++) {
        string ln;
        getline(cin, ln);
        istringstream is(ln);
        vector<int> list;
        string tmp;
        while (is >> tmp) {
            list.push_back(strToInt(tmp));
        }
        Adjacency adtmp;
        adtmp = {i, list};
        ad.push_back(adtmp);
    }

    vector<Edge> ed;
    for (int i = 0; i < ad.size(); i++) {
        for (int j = 0; j < ad[i].vv.size(); j++) {
            Edge etmp;
            if (ad[i].vv[j] > ad[i].v)
                etmp = {ad[i].v, ad[i].vv[j]};
            ed.push_back(etmp);
        }
    }
    // for (int i = 0; i < ed.size(); i++) {
    //     if (ed[i].v1 > ed[i].v2)
    //         swap(ed[i].v1, ed[i].v2);
    // }
    // sort(ed.begin(), ed.end(), &cmp);
    ed.erase(unique(ed.begin(), ed.end(), &cmpp), ed.end());
    for (int i = 0; i < ed.size(); i++) {
        cout << ed[i].v1 << " " << ed[i].v2 << "\n";
    }

    return 0;
}