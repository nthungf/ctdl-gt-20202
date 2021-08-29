/*
Cho đồ thị vô hướng G=<V, E>
được biểu diễn dưới dạng danh sách cạnh.
Hãy viết chương trình thực hiện chuyển đổi biểu diễn
đồ thị dưới dạng danh sách kề.
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
int cmp(Adjacency x, Adjacency y) { return (x.v < y.v); }

int cmpp(Adjacency x, Adjacency y) { return (x.v == y.v); }

int main() {
    int t;
    cin >> t;
    while (t--) {
        int v, e;
        cin >> v >> e;
        vector<Edge> edg(e);

        vector<Adjacency> adj;
        for (int i = 0; i < e; i++) {
            cin >> edg[i].v1 >> edg[i].v2;
            vector<int> vtmp;
            Adjacency tmp = {edg[i].v1, vtmp};
            adj.push_back(tmp);
            tmp = {edg[i].v2, vtmp};
            adj.push_back(tmp);
        }
        sort(adj.begin(), adj.end(), cmp);
        adj.erase(unique(adj.begin(), adj.end(), cmpp), adj.end());

        for (int i = 0; i < e; i++) {
            for (int j = 0; j < adj.size(); j++) {
                if (edg[i].v1 == adj[j].v) {
                    adj[j].vv.push_back(edg[i].v2);
                } else if (edg[i].v2 == adj[j].v) {
                    adj[j].vv.push_back(edg[i].v1);
                }
            }
        }

        for (int i = 0; i < adj.size(); i++) {
            cout << adj[i].v << ": ";
            for (int j = 0; j < adj[i].vv.size(); j++) {
                cout << adj[i].vv[j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}