//DP with range query
//Kind of Longest Increasing Subsequence

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pairiz
#define f first
#define s second

vector<ll> segTree;
int sz;

ll func(ll a, ll b)
{
    return max(a,b);
}

void upd(int p, ll v)
{
    segTree[p += sz] = v;

    for(p /= 2; p > 0; p /= 2)
    {
        segTree[p] = func(segTree[2*p], segTree[2*p+1]);
    }
}

ll query(int l, int r)
{
    ll ans = 0;

    for(l += sz, r += sz; l < r; l /= 2, r /= 2)
    {
        if(l&1)
        {
            ans = func(ans, segTree[l++]);
        }

        if(r&1)
        {
            ans = func(ans, segTree[--r]);
        }
    }

    return ans;
}


int main()
{
    int n; cin >> n;
    sz = n;
    segTree.assign(2*sz, 0);

    ll h[n];

    for(int i = 0; i < n; i++)
    {
        cin >> h[i]; h[i]--;
    }

    ll v[n];

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for(int i = 0; i < n; i++)
    {
        ll sum = query(0, h[i]);
        upd(h[i], sum + v[i]);
    }

    cout << query(0, n);
}