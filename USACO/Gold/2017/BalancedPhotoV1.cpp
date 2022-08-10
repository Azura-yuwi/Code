//USACO Guide Point Update Range Sum
//USACO 2017 Jan Gold P1
//Segment Trees/BinaryIndexTree?

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
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
    ifstream fin("bphoto.in");
    ofstream fout("bphoto.out");

    fin >> n;
    pair<int,int> cows[n];
    segTree.assign(2*n, 0);

    for(int i = 0; i < n; i++)
    {
        int h; fin >> h; cows[i] = mp(h,i);
    }

    sort(cows, cows + n, greater<pair<int,int>>());
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        int val, pos; tie(val, pos) = cows[i];
        int l = query(0, pos);
        int r = query(pos+1, n);

        if(l > 2*r || r > 2*l)
        {
            ans++;
        }

        upd(pos, 1);
    }

    fout << ans << endl;
}
