//USACO Gold 2020 Open
//Range Update?

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

template<class T> struct segment_tree
{
    const T INF = 0;
    int n; vector<T> segTree;

    T func(T a, T b) //function of segment tree
    {
        return a + b;
    }

    void init(int size)
    {
        n = size;
        segTree.assign(2*n, INF);
    }

    void upd(int p, T v)
    {
        segTree[p += n] += v;

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
    ifstream fin("haircut.in");
    ofstream fout("haircut.out");

    int n; fin >> n;
    tree.init(n+1); //lengths 0 to n inclusive
    ll val[n+1];
    int hairs[n];

    for(int i = 0; i < n; i++)
    {
        val[i] = 0;
        fin >> hairs[i];
    }

    val[n] = 0;

    for(int i = 0; i < n; i++)
    {
        ll invs = tree.query(hairs[i] + 1, n+1);
        tree.upd(hairs[i], 1);
        val[hairs[i]] += invs;

        //cout << hairs[i] << " " << invs << " " << val[hairs[i]] << endl;
    }

    ll total = 0;

    for(int i = 0; i < n; i++)
    {
        fout << total << endl;
        total += val[i];
    }


}