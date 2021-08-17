//USACO Euler Tour Technique
//CSES Tree Algorthms
//Least Common Ancestor

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

vector<int> adj[200005];
int tin[100005];
int tour[200000];
int segTree[400010];
int on;

void dfs(int src, int p)
{
    tin[src] = on;
    tour[on++] = src;

    for(int i : adj[src])
    {
        if(i != p)
        {
            dfs(i,src);
            tour[on++] = src;
        }
    }
}

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

int main()
{

}
