/*
Cho một cây biểu thức là một cây nhị phân đầy đủ bao gồm
các phép toán +, -, *. / và một số toán hạng có giá trị nguyên.
Nhiệm vụ của bạn là hãy tính toán giá trị biểu thức được
biểu diễn trên cây nhị phân đầy đủ.

*/

#include <bits/stdc++.h>
using namespace std;

class node {
  public:
    int val;
    string data;
    node *left, *right;
    node(string p) {
        this->val = 0;
        this->data = p;
        this->left = this->right = NULL;
    }
};

bool isOperator(char x) { return (x == '+' || x == '-' || x == '*' || x == '/'); }

int Op(int a, int b, char op) {
    switch (op) {
    case '+': return a + b; break;
    case '-': return a - b; break;
    case '*': return a * b; break;
    case '/': return a / b; break;
    }
    return 0;
}

vector<string> s;

node *buildTree() {
    queue<node *> st;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (!isOperator(s[i][0])) {
            node *tmp = new node(s[i]);
            st.push(tmp);
        } else {
            node *op = new node(s[i]);
            node *op1 = st.front();
            st.pop();
            node *op2 = st.front();
            st.pop();
            op->left = op2;
            op->right = op1;
            st.push(op);
        }
    }
    node *root = st.front();
    st.pop();
    return root;
}

int strToInt(string s) {
    int n = 0;
    for (int i = 0; i < s.size(); i++) {
        n = n * 10 + (s[i] - '0');
    }
    return n;
}

int Calc(node *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return (strToInt(root->data));
    int a = Calc(root->left);
    int b = Calc(root->right);
    // cout << a << " " << root->data << " " << b << "\n";
    root->val = Op(a, b, root->data[0]);
    return root->val;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        s.resize(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        node *root = NULL;
        root = buildTree();
        // cout << root->data << "\n";
        cout << Calc(root) << "\n";
    }
    return 0;
}