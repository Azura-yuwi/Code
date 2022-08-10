#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector<ll> segTree;
int sz;
int n;
vector<int> pos;
int maxReach[200005];
int he[200005];

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

void build()
{
    for(int i = sz - 1; i > 0; i--)
    {
        segTree[i] = func(segTree[2*i], segTree[2*i+1]);
    }
}


int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x, h;
        cin >> x >> h;
        he[i] = h;
        pos.pb(x);
    }

    segTree.assign(2*n, 0);
    sz = n;

    for(int i = 0; i < n; i++)
    {
        segTree[i+n] = i;
    }

    build();

    for(int i = n-1; i >= 0; i--)
    {
        maxReach[i] = i;
        int onlyReach = upper_bound(pos.begin(), pos.end(), (pos[i] + he[i])) - pos.begin();
        maxReach[i] = query(i, onlyReach);
        upd(i, maxReach[i]);
        //cout << " for " << i << " can Reach " << maxReach[i] <<"\n";
    }

    for(int i = 0; i < n; i++)
    {
        cout << maxReach[i] - i + 1 << " ";
    }

    return 0;
}