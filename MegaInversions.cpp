//Kattis

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

int n; vector<ll> segTree; 
vector<ll> smaller;

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

void updSmall(int p, ll v)
{
    smaller[p += n] = v;

    for(p /= 2; p > 0; p /= 2)
    {
        smaller[p] = func(smaller[2*p], smaller[2*p+1]);
    }
}

ll querySmall(int l, int r)
{
    ll ans = 0;
    
    for(l += n, r += n; l < r; l /= 2, r /= 2) 
    {
        if(l&1)
        {
            ans = func(ans, smaller[l++]); //same as func(ans, segTree[l]); l++
        }

        if(r&1)
        {
            ans = func(ans, smaller[--r]); //same as func(ans, segTree[r-1]); r--;
        }
    }

    return ans;
}

ll query(int l, int r) //interval [l, r)
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


int main()
{
    cin >> n;
    int val[n];
    ll inv[n];
    vector<int> pos[n];

    segTree.assign(2*n, 0);
    smaller.assign(2*n, 0);

    for(int i = 0; i < n; i++)
    {
        int a; cin >> a; a--;
        val[i] = a; pos[a].pb(i);
        inv[i] = 0;
    }

    ll ans = 0;

    for(int i = 0; i < n; i++)
    {
        //cout << "on num " << i << endl;

        for(int at : pos[i])
        {
            inv[at] = query(at, n); //holds existance
            ll mega = querySmall(at, n);
            ans += querySmall(at, n); //holds inversions

            //cout << "at " << at <<  " " << val[at] <<" inversions: " << inv[at] << " megas " << mega << endl;
        }

        for(int at : pos[i])
        {
            upd(at, 1);
            updSmall(at, inv[at]);
        }
    }

    cout << ans << endl;
}
