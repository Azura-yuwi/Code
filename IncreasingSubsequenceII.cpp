//USACO Guide Point Update Range Sum
//CSES Range Queries
//Segment Trees/BinaryIndexTree?

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int n; vector<int> segTree;
const int mod = 1e9 + 7;

int func(int a, int b)
{
    return (a + b)%mod;
}

void upd(int p, int v)
{
    segTree[p += n] = v;

    for(p /= 2; p > 0; p /= 2)
    {
        segTree[p] = func(segTree[2*p],segTree[2*p+1]);
    }
}

int query(int l, int r)
{
    int ans = 0;

    for(l += n, r += n; l < r; l /= 2, r /= 2)
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
    cin >> n; segTree.assign(2*n, 0);
    pair<int, int> vals[n];
    int get[n];

    for(int i = 0; i < n; i++)
    {
        int a; cin >> a; vals[i] = mp(a, i); get[n] = 0;
    }

    sort(vals, vals+n);

    int ans = 0;

    int i = 0; 

    while(i < n)
    {
        int start = i;
        
        while(i < n && vals[i].first == vals[start].first)
        {
            int num, pos; tie(num, pos) = vals[i];
            int getn = query(0, pos);
            ans += (getn + 1); ans %= mod;
            get[i] = getn+1;
            i++;
            //cout << "num " << num << " pos " << pos << " get " << getn << " " << get[i-1] << endl;
        }

        while(start < i)
        {
            upd(vals[start].second, get[start]);
           // cout << "updated " << vals[start].first << " " << vals[start].second << " " << get[start] << endl;
            start++;
        }
    }

    cout << ans << endl;
}
