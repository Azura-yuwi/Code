#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector<int> adj[301];
int sz[301];
int cSz[301];
int lvl[301];

void dfs(int at, int p)
{
    sz[at] = 1;
    cSz[at] = 0;

    for(int to : adj[at])
    {
        if(to != p)
        {
            lvl[to] = lvl[at] + 1;
            dfs(to, at);
            sz[at] += sz[to];
            cSz[at] = max(cSz[at], sz[to]);
        }
    }
}


int main()
{
    int n,p; cin >> n >> p;
    
    for(int i = 0; i < p; i++)
    {
        int a,b; cin >> a >> b; a--; b--;
        adj[a].pb(b); adj[b].pb(a);
    }

    lvl[0] = 0; 
    dfs(0, -1);
    int save = n - sz[0];

    vector<int> gen[301]; 
    gen[0].pb(0); int at = 0; int nxt = 1; int mxSize = 0; int mxInd = -1; 

    while(gen[at].size() != 0)
    {
        mxSize = 0; mxInd = -1; 

        for(int get : gen[at])
        {
            for(int to : adj[get])
            {
                if(lvl[to] > lvl[get])
                {
                    if(mxInd == -1 || sz[to] > mxSize)
                    {
                        mxSize = sz[to]; 
                        if(mxInd != -1) gen[nxt].pb(mxInd);
                        mxInd = to;
                    }
                    else if(sz[to] == mxSize && cSz[to] > cSz[mxInd])
                    {
                        gen[nxt].pb(mxInd); mxInd = to;
                    }
                    else
                    {
                        gen[nxt].pb(to);
                    }
                }
            }
        }
        
        if(mxInd != -1)
        {
            save += sz[mxInd];
            //cout << "AT " << at << " saving " << mxInd << " " << sz[mxInd] << endl;
        }

        at = nxt; nxt++;
    }

    cout << (n-save) << endl;
}