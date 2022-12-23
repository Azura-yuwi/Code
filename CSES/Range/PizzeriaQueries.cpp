#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector<pair<int,int>> sTree; //leftQ, rightQ, 
vector<pair<int,int>> seg; //leftEnd, rightEnd
int sz;

void upd(int p, int v)
{
    sTree[p += sz] = mp(v,v);
    seg[p] = mp(p-sz, p-sz);
    
    for(p /= 2; p > 0; p /= 2)
    {
        seg[p] = mp(seg[2*p].f, seg[2*p+1].s);
        sTree[p] = mp(min(sTree[2*p].f, sTree[2*p+1].f + seg[2*p+1].f - seg[2*p].f), min(sTree[2*p+1].s, sTree[2*p].s + seg[2*p+1].s - seg[2*p].s));
    }
}

int lquery(int l, int r) //[l,r)
{
    int ans = INT_MAX;
    int oL = l; 

    for(l += sz, r += sz; l < r; l /= 2, r /= 2)
    {
        if(l&1)
        {
            ans = min(ans, sTree[l].first + seg[l].first - oL); l++;
        }

        if(r&1)
        {
            r--;
            ans = min(ans, sTree[r].first + seg[r].first - oL);
        }
    }

    return ans; 
}

int rquery(int l, int r)
{
    int ans = INT_MAX;
    int oR = r-1; 

    for(l += sz, r +=sz; l < r; l /= 2, r /= 2)
    {
        if(l&1)
        {
            ans = min(ans, sTree[l].second + oR - seg[l].second); l++;
        }

        if(r&1)
        {
            r--;
            ans = min(ans, sTree[r].second + oR - seg[r].second);
        }
    }

    return ans; 
}

int main()
{
    int n,q; cin >> n >> q;
    sz = n; sTree.assign(2*n, mp(INT_MAX, INT_MAX)); seg.assign(2*n, mp(0,0));

    for(int i = 0; i < n; i++)
    {
        int get; cin >> get; upd(i, get);
    }

    for(int i = 0; i < q; i++)
    {
        int type; cin >> type;

        if(type == 1)
        {
            int a,b; cin >> a >> b;
            upd(a-1, b);
        }
        else
        {
            int a; cin >> a; int left = rquery(0,a); int right = lquery(a-1, n);
            int ans = min(left,right);
            cout << ans << endl;
        }
    }
}