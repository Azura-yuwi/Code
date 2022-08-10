//USACO Gold 2017 February
//Range Query -- Segment Tree

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

template<class T> struct segment_tree
{
    const T INF = 0;
    int n; vector<int> segTree;

    T func(T a, T b) //function of segment tree
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

segment_tree<int> tree;

int main()
{
    ifstream fin("circlecross.in");
    ofstream fout("circlecross.out");

    int n; fin >> n;
    tree.init(2*n);
    vector<pair<int,int>> A;
    A.assign(n, mp(-1,-1));

    for(int i = 0; i < 2*n; i++)
    {
        int a; fin >> a; a--;
        if(A[a].f == -1)
        {
            A[a].f = i;
        }
        else
        {
            A[a].s = i;
        }
    }

    sort(A.begin(), A.end());
    int cross = 0;

    for(int i = 0; i < n; i++)
    {
        int st = A[i].f; int en = A[i].s;
        cross += tree.query(st,en);
        tree.upd(en, 1);
    }

    fout << cross;
}