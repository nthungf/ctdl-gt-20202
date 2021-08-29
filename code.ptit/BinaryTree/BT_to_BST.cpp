/*
Cho cây nhị phân, nhiệm vụ của bạn là dịch chuyển cây nhị phân
thành cây nhị phân tìm kiếm. Phép dịch chuyển phải bảo toàn
được cấu trúc cây nhị phân ban đầu.
*/

#include <bits/stdc++.h>
using namespace std;

class node {
  public:
    int val;
    node *l, *r;

    node(int p) {
        this->val = p;
        this->l = this->r = NULL;
    }
    void addNode(node *pp, char x) {
        if (x == 'L' && this->l == NULL) this->l = pp;
        else if (x == 'R' && this->r == NULL)
            this->r = pp;
    }
};

node *Search(node *root, int u) {
    if (root == NULL || root->val == u) return root;
    else {
        node *p = NULL;
        p = Search(root->l, u);
        if (p == NULL) p = Search(root->r, u);
        return p;
    }
}

vector<int> a;
void inOrder(node *root, int *idx) {
    if (root == NULL) return;
    inOrder(root->l, idx);
    root->val = a[*idx];
    (*idx)++;
    // cout << root->val << " ";
    inOrder(root->r, idx);
}

void Output(node *root) {
    if (root == NULL) return;
    Output(root->l);
    cout << root->val << " ";
    Output(root->r);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, u, v;
        char x;
        a.clear();
        cin >> n >> u >> v >> x;
        a.push_back(u);
        a.push_back(v);
        node *root = new node(u);
        node *pp = new node(v);
        root->addNode(pp, x);
        for (int i = 1; i < n; i++) {
            cin >> u >> v >> x;
            a.push_back(u);
            a.push_back(v);
            pp = Search(root, u);
            node *ppp = new node(v);
            pp->addNode(ppp, x);
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        int i = 0;
        inOrder(root, &i);
        Output(root);
        cout << "\n";
    }
    return 0;
}