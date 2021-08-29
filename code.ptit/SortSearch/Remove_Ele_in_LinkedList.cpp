/*
Problem
*/

#include <iostream>
using namespace std;

int n, m;

struct node {
    int d;
    node *next;
} * start;

void addNode(int val) {
    node *s;
    node *tmp = new node();
    tmp->d = val;
    tmp->next = NULL;
    if (start == NULL) {
        start = tmp;
        start->next = NULL;
    } else {
        s = start;
        while (s->next != NULL) {
            s = s->next;
        }
        s->next = tmp;
    }
}

void delVal(int m) {
    if (start == NULL) return;
    node *s = start;
    int pos = 0;
    while (s != NULL) {
        if (s->d == m) {
            if (pos == 0) {
                node *tmp = start;
                start = start->next;
                tmp->next = NULL;
                free(tmp);
            } else {
                node *ss = start;
                node *ptr;
                for (int i = 0; i < pos; ++i) {
                    ptr = ss;
                    ss = ss->next;
                }
                ptr->next = ss->next;
                ss->next = NULL;
                free(ss);
                // cout << pos << " ";
            }
            s = start;
            pos = 0;
            continue;
        }
        pos++;
        s = s->next;
    }
}

void printList() {
    node *s = start;
    while (s != NULL) {
        cout << s->d << " ";
        s = s->next;
    }
    cout << "\n";
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        addNode(x);
    }
    cin >> m;
    delVal(m);
    printList();
    return 0;
}
