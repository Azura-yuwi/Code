//CSES Graph Algs
//USACO Guide Binary Jumping

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

const int maxn = 200002;
const int maxd = 22;
int tot[maxn][maxd];
int cyc[maxn];
int distTo[maxn];
bool incyc[maxn];
int to[maxn];
vector<int> adj[maxn];
int num;
vector<int> cyclen;

void dfs(int x)
{
    for(int get : adj[x])
    {
        if(incyc[get])
        {
            continue;
        }

        distTo[get] = distTo[x] + 1;
        cyc[get] = cyc[x];
        dfs(get);
    }
}

void floyd(int x)
{
    int a = to[x]; int b = to[to[x]];

    while(a != b)
    {
        a = to[a];
        b = to[to[b]];

        /*if(cyc[b] != 0) //entered already approached territory
        {
            dfs(b);
            return;
        }*/
    }

    //found new cycle
    a = x; 

    while(a != b)
    {
        a = to[a];
        b = to[b];
    }


    //fill cycle from b;
    incyc[b] = true; cyc[b] = num; num++; 
    a = to[b];

    while(a != b)
    {
        incyc[a] = true; cyc[a] = cyc[b];
        a = to[a];
    }

    //dfs
    int len = 1; distTo[b] = 0;
    dfs(b); a = to[b];

    while(a != b)
    {
        dfs(a); distTo[a] = len;
        len++; a = to[a];
    }

    a = to[b];

    while(a != b)
    {
        distTo[a] = len - distTo[a]; a = to[a];
    }

    cyclen.pb(len);

    return;
}

int getNum(int a, int b)
{
    int at = 0;

    while(b > 0)
    {
        if(b%2 == 1)
        {
            a = tot[a][at];
        }

        at++;
        b /= 2;
    }

    return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n,q; cin >> n >> q; num = 1; 

    for(int i = 0; i < n; i++)
    {
        cyc[i+1] = 0; incyc[i+1] = false;
        cin >> tot[i+1][0]; to[i+1] = tot[i+1][0];
        adj[to[i+1]].pb(i+1);
    }

    for(int i = 1; i <= n; i++)
    {
        if(cyc[i] == 0)
        {
            floyd(i);
        }
    }

    for(int d = 1; d < maxd; d++)
    {
        for(int i = 1; i <= n; i++)
        {
            tot[i][d] = tot[tot[i][d-1]][d-1];
        }
    }

    for(int i = 0; i < q; i++)
    {
        int a,b; cin >> a >> b;

        if(cyc[a] != cyc[b])
        {
            cout << -1 << endl;
        }
        else if(incyc[a])
        {
            if(incyc[b])
            {
                if(distTo[a] >= distTo[b])
                {
                    cout << distTo[a] - distTo[b] << endl;
                }
                else
                {
                    //cout << distTo[a] << " " << cyclen[cyc[a]-1] << " " << distTo[b] << endl;
                    cout << distTo[a] + cyclen[cyc[a]-1] - distTo[b] << endl;
                }
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else
        {
            if(incyc[b])
            {
                int ans = distTo[a];
                a = getNum(a,ans);

                if(distTo[a] >= distTo[b])
                {
                    cout << ans + distTo[a] - distTo[b] << endl;
                }
                else
                {
                    cout << ans + distTo[a] + cyclen[cyc[a]-1] - distTo[b] << endl;
                }
            }
            else
            {
                if(distTo[a] < distTo[b])
                {
                    cout << -1 << endl;
                }
                else
                {
                    int get = getNum(a, distTo[a] - distTo[b]);

                    if(get == b)
                    {
                        cout << distTo[a] - distTo[b] << endl;
                    }
                    else
                    {
                        cout << -1 << endl;
                    }
                }
            }
        }
    }
}