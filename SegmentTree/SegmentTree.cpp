#include <iostream>

using namespace std;

int n,p,a,b,m,x,y,ans;

void down(int);
struct Node 
{
    int l;      //左区间
    int r;      //右区间
    int w;      //区间和 (目测也可以理解为 权重
    int f;
}tree[10000];

//线段树 建树
void build(int k, int ll, int rr)
{
    tree[k].l = ll; 
    tree[k].r = rr;
    if (tree[k].l == tree[k].r)
    {
        cin >> tree[k].w;
        return;
    }

    int m = (ll+rr)/2;
    build(k*2, ll, m);
    build(k*2+1, m+1, rr);
    tree[k].w = tree[k*2].w + tree[k*2+1].w;
}

inline void down(int k)
{
    tree[k*2].f += tree[k].f;
    tree[k*2+1].f += tree[k].f;
    tree[k*2].w += tree[k].f * (tree[k*2].r - tree[k*2].l);
    tree[k*2+1].w += tree[k].f * (tree[k*2+1].r - tree[k*2+1].l);
    tree[k].f = 0;
}

void ask(int k)
{
    if (tree[k].l == tree[k].r)
    {
        ans = tree[k].w;
        return;
    }

    int mid = (tree[k].l + tree[k].r) / 2;
    if (tree[k].f)
        down(k);
    if (x <= mid)
        ask(2*k);
    else 
        ask(2*k+1);
}

void add(int k)
{
    if (tree[k].l >= a && tree[k].r <= b) 
    {
        tree[k].w += (tree[k].r - tree[k].l + 1);
        tree[k].f += x;
        return;
    }

    if (tree[k].f)
        down(k);
    int m = (tree[k].l + tree[k].r) / 2;
    if (a <= m)
        add(k*2);
    if (b > m)
        add(k*2+1);
    tree[k].w = tree[k*2].w + tree[k*2+1].w;
}

void sum(int k)
{
    if (tree[k].l >= x && tree[k].r <= y)
    {
        ans += tree[k].w;
        return;
    }

    int m = (tree[k].l + tree[k].r) / 2;
    if (y > m) sum(k*2+1);
}

inline void change_interval(int k)
{
    if (tree[k].l >= a && tree[k].r < b)
    {
        
    }
}
