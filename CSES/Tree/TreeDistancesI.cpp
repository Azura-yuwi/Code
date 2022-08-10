#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pairiz
#define f first
#define s second

int n;
vector<int> adj[200005];
int fir[200005];
int sec[200005];
int out[200005];

void dfs1(int p, int at)
{
    fir[at] = 1;
    sec[at] = 1;

    for(int to : adj[at])
    {
        if(to != p)
        {
            dfs1(at, to);

            if(fir[to]+1 > fir[at])
            {
                sec[at] = fir[at]; fir[at] = fir[to] + 1;
            }
            else if(fir[to]+1 > sec[at])
            {
                sec[at] = fir[to]+1;
            }
        }
    }
} 

void dfs2(int p, int at)
{
    if(at != 0)
    {
        if(fir[at] + 1 == fir[p])
        {
            out[at] = max(out[p]+1, sec[p]);
        }
        else
        {
            out[at] = max(fir[p], out[p]+1);
        }
    }

    for(int to : adj[at])
    {
        if(to != p)
        {
            dfs2(at, to);

            //dp[to] = fir[to]-1;

            /*if(fir[to]+1 == fir[at])
            {
                out[to] = max(out[to], sec[at]);
            }
            else
            {
                out[to] = max(out[to], fir[at]);
            }

            /out[to] = max(out[to], )*/
        }
    }
}
int main()
{
    cin >> n;

    for(int i = 1; i < n; i++)
    {
        int a,b; cin >> a >> b; a--;b--; 
        adj[a].pb(b); adj[b].pb(a);
    }

    dfs1(0,0);
    out[0] = 0;
    dfs2(0,0);

    for(int i = 0; i < n; i++)
    {
        cout << max(out[i], fir[i]-1) << " ";
        //cout << fir[i] << " " << sec[i] << " " << out[i] << " " << max(out[i], fir[i]-1) << endl;
    }
}