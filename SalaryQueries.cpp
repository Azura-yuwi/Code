//USACO Guide Point Update Range Sum
//CSES Range Queries
//Segment Trees/BinaryIndexTree?

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

    void upd(int p, T v) //v = +- 1
    {
        segTree[p += n] += v;

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

segment_tree<int> tree;

int main()
{
    int n,q;
    cin >> n >> q;

    tree.init(1e9 + 1);

    int sal[n];

    for(int i = 0; i < n; i++)
    {
        cin >> sal[i];
        tree.upd(sal[i], 1);
    }

    for(int i = 0; i < q; i++)
    {
        char type; cin >> type;
        int a,b; cin >> a >> b;

        if(type == '!')
        {
            tree.upd(sal[a], -1);
            tree.upd(b, 1);
            sal[a] = b;
        }
        else
        {
            cout << tree.query(a,b+1) << endl;
        }
    }


}