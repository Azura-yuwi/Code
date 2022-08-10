#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

vector<ll> primes;
vector<ll> pNum;
vector<ll> segTree;
int tsize; ll m; int n;

ll func(ll a, ll b)
{
    return (a*b)%m;
}

void build()
{
    for(int i = tsize-1; i >= 0; i--)
    {
        segTree[i] = func(segTree[2*i], segTree[2*i+1]);
    }
}

ll query(int l, int r) //interval [l, r)
{
    ll ans = 1;

    for(l += tsize, r += tsize; l < r; l /= 2, r /= 2) 
    {
        if(l&1) //&1 true -- > right component; left element + l < r --> you can move up the tree
        {
            ans = func(ans, segTree[l++]); //same as func(ans, segTree[l]); l++
        }

        if(r&1) //remember r), if r is right element -> right bound is an left element; r = left element --> you can move up the tree;
        {
            ans = func(ans, segTree[--r]); //same as func(ans, segTree[r-1]); r--;
        }
    }

    return ans;
}


int main()
{
    cin >> n >> m;

    for(int i = 2; i <= n; i++)
    {
        bool isP = true;

        for(ll p : primes)
        {
            if(i%p == 0)
            {
                isP = false;
                break;
            }
        }

        if(isP)
        {
            primes.pb(i);
        }
    }

    tsize = primes.size();
    pNum.assign(tsize, 0);
    segTree.assign(2*tsize, 1);

    

}