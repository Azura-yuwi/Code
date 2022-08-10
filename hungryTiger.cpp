#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int n,q;
ll v[300005];
ll dp[300005];
vector<int> toUp[300005];
vector<ll> segTree;
int sz;

ll func(ll a, ll b)
{
    return max(a,b);
}

void upd(int p, ll v)
{
    segTree[p += sz] += v;

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

void printTree()
{
    cout << "printing" << endl;

    for(int i = sz; i < 2*sz; i++)
    {
        cout << segTree[i] << " ";
    }

    cout << endl;
}


int main()
{
    cin >> n >> q;
    pair<int,pair<int,int>> queries[q];
    ll out[q];

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for(int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r; l--; r--; queries[i] = mp(r, mp(l,i));
    }

    sort(queries, queries+q);
    segTree.assign(2*n, 0);
    sz = n;

    int at = 0;

    for(int r = 0; r < n; r++)
    {
        upd(r, v[r]);

        for(int i = r-1; i >= 0; i--)
        {
            if(v[i] >= v[r])
            {
                break;
            }

            upd(i, v[r]);
        }

        while(at < q && queries[at].f <= r)
        {
            out[queries[at].s.s] = query(queries[at].s.f, r+1);
            at++;
        }
    }

    for(int i = 0; i < q; i++)
    {
        cout << out[i] << endl;
    }
}