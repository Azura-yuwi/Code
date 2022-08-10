///CCC 2003 Senior 5

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int root[10001];
bool des[10001];

int find(int a)
{
    if(root[a] <= 0)
    {
        return a;
    }

    root[a] = find(root[a]);
    return root[a];
}

bool unite(int a, int b)
{
    a = find(a); b = find(b);

    if(a == b) return false;

    if(a > b) {swap(a,b);}
    //now a has more elements than b

    root[a] += root[b];
    root[b] = a;
    return true;
}

int main()
{
    int c,r,d; cin >> c >> r >> d;
    pair<int, pair<int,int>> edges[r];

    for(int i = 1; i <= c; i++)
    {
        root[i] = 0;
        des[i] = false;
    }

    for(int i = 0; i < r; i++)
    {
        int a,b,d; cin >> a >> b >> d;
        edges[i] = mp(d, mp(a,b));
    }

    for(int i = 0; i < d; i++)
    {
        int a; cin >> a; des[a] = true; root[a] = -1;
    }

    sort(edges, edges+r, greater<pair<int,pair<int,int>>>());

    int ans = 0;

    for(int i = 0; i < r; i++)
    {
        int w = edges[i].f; int a, b; tie(a,b) = edges[i].s;

        if(unite(a,b) && root[1] == (-1)*d)
        {
            ans = w; break;
        }
    }

    cout << ans; 
}