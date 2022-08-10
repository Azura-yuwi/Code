#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

//BIT vs Segmenttree
//BIT only works on functions that are invertible
//BIT represents culmulative stuff
//Ex: max and min are funcitons that are not invertible

vector<ll> bit; 
vector<ll> val;
int n,q;

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

int main()
{
    cin >> n >> q;
    bit.assign(n+1, 0);
    val.assign(n+1,0);

    for(int i = 1; i <= n; i++)
    {
        cin >> val[i];
        upd(i, val[i]);
    }

    for(int i = 0; i < q; i++)
    {
        int t,a,b; cin >> t >> a >> b;

        if(t == 1)
        {
            upd(a, -val[a]); //remove current value
            val[a] = b; upd(a, val[a]); //add new value
        }
        else
        {
            cout << query(b) - query(a-1) << endl;
        }
    }
}

