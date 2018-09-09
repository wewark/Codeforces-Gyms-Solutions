// Arab Collegiate Programming Contest 2012
// 100155B

#include <bits/stdc++.h>
using namespace std;

struct node;
node *empty;

struct node {
    node *ch[2], *p;
    char v;
    int sz;

    node() :  p(this), v(0), sz(0){
        ch[0] = ch[1] = this;
    }

    node(char v) : v(v), sz(1), p(empty){
        ch[0] = ch[1] = empty;
    }
};

node *root;

inline void push_up(node *nd) {
    nd->sz = 1 + nd->ch[0]->sz + nd->ch[1]->sz;
}

inline void push_down(node *nd) {

}

inline void setchild(node *p, node *c, int idx) {
    if (p != empty) {
        p->ch[idx] = c;
    }
    c->p = p;
}

inline int getdir(node *p, node *c) {
    return p->ch[1] == c;
}

inline void rotate(node *nd, int idx) {
    node *ch = nd->ch[idx], *p = nd->p;
    setchild(nd, ch->ch[!idx], idx);
    setchild(ch, nd, !idx);

    setchild(p, ch, getdir(p, nd));

    push_up(nd);
    push_up(ch);
}

inline void splay(node *nd) {
    while (nd->p != empty) {
        node *p = nd->p, *g = p->p;
        int pi = getdir(p, nd), gi = getdir(g, p);
        if (g == empty) {
            rotate(p, pi);
        } else if (pi == gi) { // TODO why log N?
            rotate(g, gi);
            rotate(p, gi);
        } else {
            rotate(p, pi);
            rotate(g, gi);
        }
    }
    root = nd;
}

inline node *getNodeAt(node *t, int idx) {
    idx = min(idx, t->sz - 1);
    while (push_down(t), t->ch[0]->sz != idx) {
        //cout << t->ch[0]->sz << endl;
        if (t->ch[0]->sz < idx) {
            idx -= t->ch[0]->sz + 1;
            t = t->ch[1];
        } else {
            t = t->ch[0];
        }
    }
    splay(t);
    return t;
}

inline void split(node *t, int presz, node *&pre, node *&suf) {
    if (presz == 0) {
        pre = empty;
        suf = t;
    }else{
        pre = getNodeAt(t, presz - 1);
        suf = pre->ch[1];
        pre->ch[1] = suf->p = empty;
        push_up(pre);
    }
}

inline void merge(node *pre, node *suf, node *&t){
    if (pre == empty){
        t = suf;
    }else{
        t = getNodeAt(pre, pre->sz - 1);
        setchild(t, suf, 1);
        push_up(t);
    }

}

inline void Add(node *&t , int i , char c){
    node *mid = new node(c);
    node *before, *after;
    split(t,i+1,before,after);
    merge(before,mid,before);
    merge(before,after,t);
}

inline void Print(node *&t , int i){
    node *before, *mid, *after;
    split(t,i + 1, before, after);
    split(before, i, before, mid);
    printf("%c",mid->v);
    merge(before, mid, before);
    merge(before, after, t);
}

const int N = 2e5 + 5;
char str[N];


int main()
{

    empty = new node();
    root = empty;
    scanf("%s",str);
    for(int i = 0 ; str[i] ; i++){
        merge(root,new node(str[i]),root);
    }

    while(true){
        scanf("%s",str);
        if(str[0] == 'E')return 0;
        if(str[0] == 'I'){
            int idx;
            scanf("%s%d",str,&idx);
            --idx;
            int n = strlen(str);
            for(int i = n-1 ; ~i ; i--){
                Add(root,idx,str[i]);
            }
        }else{
            int st , ed;
            scanf("%d%d",&st,&ed);
            for(int i = st ; i <= ed ; i++)
                Print(root,i);
            printf("\n");
        }
    }


    return 0;
}
