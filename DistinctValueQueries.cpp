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
    const T INF;
    int n; vector<T> segTree;

    void func(T& a, T& b)
    {
        for(int i : b)
        {
            a.insert(i);
        }
    }

    void init(int size)
    {
        n = size;
        segTree.assign(2*n, INF);
    }

    void upd(int p, int v)
    {
        segTree[p += n].insert(v);

        for(p /= 2; p > 0; p /= 2)
        {
            func(segTree[p], segTree[2*p]);
            func(segTree[p], segTree[2*p+1]);
        }
    }

    int query(int l, int r) //interval [l, r)
    {
        T ans;
    
        for(l += n, r += n; l < r; l /= 2, r /= 2) 
        {
            if(l&1)
            {
                func(ans, segTree[l++]); //same as func(ans, segTree[l]); l++
            }

            if(r&1)
            {
                func(ans, segTree[--r]); //same as func(ans, segTree[r-1]); r--;
            }
        }

        return ans.size();
    }
};

segment_tree<unordered_set<int>> tree;

int main()
{
    int n,q;
    cin >> n >> q;

    tree.init(n);

    for(int i = 0; i < n; i++)
    {
        int add;   cin >> add;
        tree.upd(i, add);
    }

    for(int i = 0; i < q; i++)
    {
        int a,b;
        cin >> a >> b;
        cout << tree.query(a-1, b) << endl;
    }
}