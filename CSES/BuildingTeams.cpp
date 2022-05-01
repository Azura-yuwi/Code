//CSES Graph
//Some Way to Go through graph (this is dfs i think)
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> adj[100001];
int team[100001];
int n,m;
bool work;

void fill(int src)
{
    for(int i : adj[src])
    {
        if(team[i] == 0)
        {
            team[i] = (-1)*team[src];
            fill(i);
        }
        else if(team[i] == team[src])
        {
            work = false;
            return;
        }
    }

    return;
}

int main()
{
    cin >> n >> m;
    work = true;

    for(int i = 0; i < n; i++)
    {
        team[i] = 0;
    }

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    int at = 0;

    while(work && at < n)
    {
        if(team[at] == 0)
        { 
            team[at] = 1;
            fill(at);
        }

        at++;
    }

    if(!work)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(team[i] == -1)
            {
                team[i] = 2;
            }

            cout << team[i] << " ";
        }
    }
}