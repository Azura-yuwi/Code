#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

int n; vector<int> segTree;

int func(int a, int b)
{
    return a+b;
}

void upd(int p, int v)
{
    segTree[p += n] = v;

    for(p /= 2; p > 0; p /= 2)
    {
        segTree[p] = func(segTree[2*p], segTree[2*p+1]);
    }
}

int query(int l, int r) //interval [l, r)
{
    int ans = 0;
    
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

void build()
{
    for(int i = n-1; i > 0; i--)
    {
        segTree[i] = func(segTree[2*i], segTree[2*i+1]);
    }
}

int main()
{
    ifstream fin("sleepy.in");
    ofstream fout("sleepy.out");

    fin >> n;
    segTree.assign(2*n, 0);
    int v[n];

    for(int i = 0; i < n; i++)
    {
        fin >> v[i]; v[i]--;
    }

    int done = n-1;
    segTree[v[done] + n] = 1;

    while(done > 0 && v[done-1] < v[done])
    {
        done--;
        segTree[v[done] + n] = 1;
    }

    fout << done << endl;

    if(done == 0)
    {
        return 0;
    }

    build();

    for(int i = 0; i < done; i++)
    {
        fout << (done - i-1) + query(0, v[i]);
        if(i != done-1)
        {
            fout << " ";
        }
        upd(v[i], 1);
    }
}