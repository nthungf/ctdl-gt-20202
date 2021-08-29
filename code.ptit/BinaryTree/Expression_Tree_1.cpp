/*
Cây biểu thức là một cây nhị phân trong đó mỗi node
trung gian là một phép toán, mỗi node lá là một toán hạng.
Đối với cây biểu thức, duyệt theo thứ tự trước được
biểu thức trung tố, duyệt theo thứ tự sau được biểu thức
hậu tố, duyệt theo thứ tự giữa ta được biểu thức tiền tố.
Chú ý, cây biểu thức luôn là cây nhị phân đầy
(mỗi node trung gian đều có hai node con).

Cho biểu thức hậu tố P, hãy sử dụng cây biểu thức
để đưa ra biểu thức trung tố tương ứng với biểu thức P.
*/

#include <bits/stdc++.h>
using namespace std;

class node {
  public:
    char data;
    node *left, *right;

    node(int p) {
        this->data = p;
        this->left = this->right = NULL;
    }
};

bool isOperator(char x) { return (x == '+' || x == '-' || x == '*' || x == '/'); }

string s;

node *buildTree() {
    stack<node *> st;
    for (int i = 0; i < s.size(); i++) {
        if (!isOperator(s[i])) {
            node *tmp = new node(s[i]);
            st.push(tmp);
        } else {
            node *op = new node(s[i]);
            node *op1 = st.top();
            st.pop();
            node *op2 = st.top();
            st.pop();
            op->left = op2;
            op->right = op1;
            st.push(op);
        }
    }
    node *root = st.top();
    st.pop();
    return root;
}

void inOrder(node *root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data;
        inOrder(root->right);
    }
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, s);
        node *root = NULL;
        root = buildTree();
        inOrder(root);
        cout << "\n";
    }
    return 0;
}