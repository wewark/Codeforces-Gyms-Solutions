#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, l, r;
};

int n, k;
vector<Node> node;

void insertNode(int cur, int x) {
    if (x > node[cur].x) {
        if (node[cur].r == -1) {
            node[cur].r = node.size();
            node.push_back(Node{x,-1,-1});
        }
        else insertNode(node[cur].r, x);
    }
    else {
        if (node[cur].l == -1) {
            node[cur].l = node.size();
            node.push_back(Node{x,-1,-1});
        }
        else insertNode(node[cur].l, x);
    }
}

void canonical(int cur, string& ret) {
    if (node[cur].l == -1) ret.push_back('0');
    else {
        ret.push_back('1');
        canonical(node[cur].l, ret);
    }
    if (node[cur].r == -1) ret.push_back('0');
    else {
        ret.push_back('1');
        canonical(node[cur].r, ret);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    set<string> st;
    for (int i = 0; i < n; ++i) {
        node.clear();
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            if (node.empty()) {
                node.push_back(Node{x, -1, -1});
            } else {
                insertNode(0, x);
            }
        }

        string s = "";
        canonical(0, s);
        st.insert(s);
    }
    cout << st.size() << endl;
    return 0;
}
