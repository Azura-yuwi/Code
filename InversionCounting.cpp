#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

vector<ll> bit; 

int n;

void upd(int i, ll v)
{
    for(; i <= n; i += i&(-i))
    {
        bit[i] += v;
    }
}

ll query(int i)
{
    ll sum = 0;
    for(; i > 0; i -= i&(-i))
    {
        sum += bit[i];
    }

    return sum;
}

