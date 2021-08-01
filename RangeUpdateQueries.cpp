//USACO Guide Point Update Range Sum
//CSES Range Queries
//Segment Trees/BinaryIndexTree?
//for some reason this doesn't run on just this file, you can copy this to different file

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

template<class T> struct segment_tree
{
    const T INF = 0;
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
        segTree[p += n] += v;

        //cout << "UPDATING" << endl;
        //cout << "SET " << p << " " << v << endl;

        for(p /= 2; p > 0; p /= 2)
        {
            segTree[p] = func(segTree[2*p], segTree[2*p+1]);
           // cout << "SET " << p << " " << segTree[p] << endl;
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

    tree.init(n+2);

    int val[n+2];
    val[0] = 0;
    val[n+1] = 0;
    
    for(int i = 1; i <= n; i++)
    {
        cin >> val[i];
        tree.upd(i, val[i] - val[i-1]);
    }

    tree.upd(n+1, val[n+1] - val[n]);

    for(int i = 0; i < q; i++)
    {
        int t;
        cin >> t;

        if(t == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;
            tree.upd(a, u);
            tree.upd(b+1, -u);
        }
        else
        {
            int k;
            cin >> k;

            cout << tree.query(0, k+1) << endl;
        }
    }
}