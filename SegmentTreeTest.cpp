#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define T pair<int, pair<int,int>> 

int gcd(int a, int b)
{
    if(a > b) swap(a,b);

    if(b%a == 0) return a;

    return gcd(b%a, a);
}

T func(T a, T b)
{
    int GCD =  gcd(a.s.f, b.s.f);
    int num = 0;

    if(GCD == a.s.f)
    {
        num += a.s.s;
    }

    if(GCD == b.s.f)
    {
        num += b.s.s;
    }

    return mp(min(a.f,b.f), mp(GCD, num));
}

vector<T> tree;
int tSize;

void build()
{
    for(int i = tSize-1; i >= 0; i--)
    {
        tree[i] = func(tree[2*i], tree[2*i+1]);
    }
}

void upd(int p, int v)
{
    tree [p += tSize] = mp(v, mp(v,1));

    for(p /= 2; p > 0; p /= 2 )
    {
        tree[p] = func(tree[2*p], tree[2*p+1]);
    }
}

int Mquery(int l, int r)
{
    int ans = INT_MAX;

    for(l += tSize, r += tSize; l < r; l /= 2, r /= 2)
    {

        if(l&1) //right node
        {
            ans = min(ans, tree[l].f); l++;
        }

        if(r&1) 
        {
           ans = min(ans, tree[r-1].f); r--; 
        }
    }

    return ans;
}


int query(int l, int r, char c)
{
    T ans = mp(tree[l+tSize].f, mp(tree[l+tSize].s.f, 0));

    for(l += tSize, r += tSize; l < r; l /= 2, r /= 2)
    {

        if(l&1) //right node
        {
            ans = func(ans, tree[l]); l++;
        }

        if(r&1) 
        {
           ans = func(ans, tree[r-1]); r--; 
        }
    }

    if(c == 'G') return ans.s.f;
    return ans.s.s;
}

int main()
{
    int n,m; cin >> n >> m;
    tree.assign(2*n, mp(1, (mp(1,0))));
    tSize = n;

    for(int i = 0; i < n; i++)
    {
        int a; cin >> a; tree[i+n] = mp(a, mp(a,1));
    }

    build();

    for(int i = 0; i < m; i++)
    {
        int l,r; char c; cin >> c >> l >> r;

        if(c == 'C')
        {
            upd(l-1, r);
        }
        else if (c == 'M')
        {
            cout << Mquery(l-1, r) << endl;
        }
        else
        {
            cout << query(l-1, r, c) << endl;
        }
    }
}