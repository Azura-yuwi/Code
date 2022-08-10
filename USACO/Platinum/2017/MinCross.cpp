#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

int n; vector<ll> segTree; //w/o ll doesn't pass test case 10

ll func(ll a, ll b)
{
    return a+b;
}

void upd(int p, ll v)
{
    segTree[p += n] = v;

    for(p /= 2; p > 0; p /= 2)
    {
        segTree[p] = func(segTree[2*p], segTree[2*p+1]);
    }
}

int query(int l, int r) //interval [l, r)
{
    ll ans = 0;
    
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
    ifstream fin("mincross.in");
    ofstream fout("mincross.out");

    fin >> n;
    segTree.assign(2*n, 0);
    int r1[n];
    int r2[n];

    int pos[n];
    int tpos[n];

    for(int i = 0; i < n; i++)
    {
        int a; fin >> a; a--;
        r1[i] = a; pos[a] = i;
    }

    for(int i = 0; i < n; i++)
    {
        fin >> r2[i]; r2[i]--; tpos[r2[i]] = i;
    }

    ll base = 0;

    for(int i = 0; i < n; i++)
    {
        base += query(pos[r2[i]], n);
        upd(pos[r2[i]], 1);
    }

    ll minB = base;
    ll b2 = base;

    for(int i = 0; i < n; i++)
    {
        base += (n - pos[r2[i]] - 1 - pos[r2[i]]);
        b2 += (n - tpos[r1[i]] - 1 - tpos[r1[i]]);
        minB = min(minB, min(base, b2));
    }
    
    fout << minB << endl;
}
