//USACO Gold 2017 December

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

template<class T> struct segment_tree
{
    const T INF = 0;
    int n; vector<T> segTree;

    T func(T a, T b) //function of segment tree
    {
        return max(a,b);
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
            if(l&1) //&1 true -- > right component; left element + l < r --> you can move up the tree
            {
                ans = func(ans, segTree[l++]); //same as func(ans, segTree[l]); l++
            }

            if(r&1) //remember r), if r is right element -> right bound is an left element; r = left element --> you can move up the tree;
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
    ifstream fin("hayfeast.in");
    ofstream fout("hayfeast.out");

    int n; ll m; fin >> n >> m;
    //cout << "get " << n << " " << m; 
    tree.init(n);

    ll s[n];
    ll fl[n];

    for(int i = 0; i < n; i++)
    {
        ll a,b; fin >> a >> b;
        fl[i] = a; s[i] = b;
        //cout << "update  "<< i << " " << a << " " << b << endl;
        tree.upd(i, s[i]);
    }

    int r = 1;
    ll sum = fl[0];
    ll ans = LLONG_MAX;

    for(int i = 0; i < n; i++)
    {
        while(r < n && sum < m)
        {
            sum += fl[r];
            r++;
        }

        //cout << i << " " << r << " " << sum << " " << tree.query(i,r) << endl;

        if(sum >= m)
        {
            ans = min(ans, tree.query(i, r));
        }

        sum -= fl[i];
    }

    fout << ans;
}