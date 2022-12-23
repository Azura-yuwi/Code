//USACO Guide Point Update Range Sum
//CSES Range Queries
//Segment Trees/BinaryIndexTree?

//note to self, disticnt just means don't count double, 
//i.e, the appearance of 2 '1's adds only 1 to the number of distinct values

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
        segTree[p += n] = v;
 
        for(p /= 2; p > 0; p /= 2)
        {
            segTree[p] = func(segTree[2*p], segTree[2*p+1]);
        }
    }
 
    T query(int l, int r) //interval [l, r)
    {
        T ans = INF;
    
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
int val[400005];
vector<pair<int,int>> queries[400005];
int sol[400005];
 
int main()
{
    int n,q;
    cin >> n >> q;
 
    tree.init(n);
    map<int,int> recent;
 
    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
 
    for(int i = 0; i < q; i++)
    {
        int a,b; cin >> a >> b; a--;
        queries[a].pb(mp(b, i));
    }
 
    for(int i = n-1; i >= 0; i--)
    {
        //update last index
        if(recent.find(val[i]) == recent.end())
        {
            tree.upd(i, 1);
            recent[val[i]] = i;
        }
        else
        {
            tree.upd(recent[val[i]], 0);
            tree.upd(i,1);
            recent[val[i]] = i; //don't need to update tree as inital values = 0;
        }
 
        //query
 
        for(pair<int,int> get : queries[i])
        {
            int end, ind; tie(end, ind) = get;
            sol[ind] = tree.query(i, end);
        }
 
    }
 
    for(int i = 0; i < q; i++)
    {
        cout << sol[i] << endl;
    }
}