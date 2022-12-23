#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

vector<ll> sTree; 
vector<pair<ll,int>> pTree; //maxSum, leftmost
int sz;


void upd(int p, int v)
{
    sTree[p += sz]= v;
    pTree[p] = mp(v,p-sz);

    for(p /= 2; p > 0; p /= 2)
    {
        sTree[p] = sTree[2*p] + sTree[2*p+1];
        pTree[p] = mp(max(pTree[2*p].first, pTree[2*p+1].first + sTree[2*p]), pTree[2*p].second);
    }
}

ll sQuery(int l, int r)
{
    ll ans = 0;

    for(l += sz, r += sz; l < r; l /=2, r/= 2)
    {
        if(l&1)
        {
            ans += sTree[l++];
        }

        if(r&1)
        {
            ans += sTree[--r];
        }
    }

    return ans;
}

ll query(int l, int r) //[l,r)
{
    ll ans = LLONG_MIN;

    for(l += sz, r += sz; l < r; l /= 2, r /= 2)
    {
        if(l&1)
        {
            ans = max(ans, pTree[l].first + sQuery(0, pTree[l].second)); l++;
        }

        if(r&1)
        {
            r--;
            ans = max(ans, pTree[r].first + sQuery(0, pTree[r].second));
        }
    }

    return ans;
}

void printTree()
{
    cout << "printing s treee" << endl;
    for(int i : sTree)
    {
        cout << i << " ";
    }
    
    cout << endl;

    cout << "printing p tree" << endl;
    for(pair<ll,int> get : pTree)
    {
        cout << get.first << " ";
    }

    cout << endl;
}

int main()
{
    int n,q; cin >> n >> q; sz = n;
    sTree.assign(2*n, 0);
    pTree.assign(2*n, mp(LLONG_MIN, 0));

    for(int i = 0; i < n; i++)
    {
        ll get; cin >> get; 
        upd(i, get);
    }

    //printTree();

    for(int i = 0; i < q; i++)
    {
        int type; cin >> type;

        if(type == 1)
        {
            int k; ll u; cin >> k >> u; k--;
            upd(k, u);
        }
        else
        {
            int a,b; cin >> a >> b;
            cout << max((ll)0, query(a-1, b) - sQuery(0, a-1))<< endl;
        }
    }
}