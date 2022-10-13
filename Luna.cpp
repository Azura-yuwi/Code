#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

vector<int> segTree;
int sz;

int func(int a, int b)
{
    return a+b;
}

void upd(int p, int v)
{
    segTree[p += sz] = v;

    for(p /= 2; p > 0; p /= 2)
    {
        segTree[p] = func(segTree[2*p], segTree[2*p+1]);
    }
}

int query(int l, int r) //[l,r)
{
    int ans = 0;

    for(l += sz, r += sz; l < r; l /= 2, r /= 2)
    {
        if(l&1)
        {
            ans = func(ans, segTree[l]); l++;
        }

        if(r&1)
        {
            ans = func(ans, segTree[r-1]); r--;
        }
    }

    return ans;
}

int main()
{
    int n; cin >> n;
    segTree.assign(4*n, 0);
    sz = 2*n; //cout << sz << endl;

    int end[n];
    int v[2*n];

    for(int i = 0; i < 2*n; i++)
    {
        cin >> v[i]; v[i]--; end[v[i]] = i;
    }

    int swap = 0;

    for(int i = 0; i < 2*n; i++)
    {
        if(end[v[i]] != -1)
        {
            //cout << v[i] << " " << i << " " << end[v[i]] << " " << query(i, end[v[i]]) << endl;
            swap += query(i, end[v[i]]);
            upd(end[v[i]], 1);
            end[v[i]] = -1;
        }
    }

    cout << swap+n << endl;
}