//USACO Guide Point Update Range Sum
//CSES Range Queries
//Segment Trees
//Basic Structure of Segment Tree;
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

template<class T> struct segment_tree
{
    const T INF = 1e18+10;
    int n; vector<T> segTree;

    T func(T a, T b)
    {
        return a+b;
    }

    void init(int size)
    {
        n = size;
        segTree.assign(2*n, INF);
    }

    void upd(int p, T v)
    {
        segTree[p += n] = v;

        for(p /= 2; p > 0; p /= 2)
        {
            segTree[p] = func(segTree[2*p], segTree[2*p+1]);
        }
    }

    T query(int l, int r) //interval [l, r)
    {
        T ans = 0;
    
        for(l += n, r += n; l < r; l /= 2, r /= 2) 
        {
            if(l&1)
            {
                ans = func(ans, segTree[l++]); //same as func(ans, segTree[l]); l++
            }

            if(r&1)
            {
                ans = func(ans, segTree[--r]); //same as func(ans, segTree[r-1]); r--;
            }
        }

        return ans;
    }
};

segment_tree<ll> tree;

int main()
{
    int n,q;
    cin >> n >> q;
    tree.init(n);

    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        tree.upd(i, a);
    }

    for(int i = 0; i < q; i++)
    {
        int t, a, b;
        cin >> t >> a >> b;
    
        if(t == 1)
        {
            tree.upd(a-1, b);
        }
        else
        {
            cout << tree.query(a-1,b) << endl;
        }
    }
}