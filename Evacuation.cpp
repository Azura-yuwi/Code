#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

vector<int> adj[100001];
priority_queue<int, vector<int>, greater<int>> group[100001]; //smallest to largest
int val[100001]; //groups you can split into
int n,m,k;

void dfs(int src)
{
    val[src] = 1;

    for(int to : adj[src])
    {
        if(val[to] == 0) //haven't visited yet
        {
            dfs(to);

            if(group[src].size() == k)
            {
                if(val[to] > group[src].top())
                {
                    group[src].pop();
                    group[src].push(val[to]);
                }
            }
            else
            {
                group[src].push(val[to]);
            }
        }
    }

    while(!group[src].empty())
    {
        val[src] += group[src].top();
        group[src].pop();
    }

    return;
}


int main()
{
    ofstream fout ("evacuation.out");
    ifstream fin ("evacuation.in");

    fin >> n >> m >> k;
    //cin >> n >> m >> k;

    for(int i = 0; i < n-1; i++)
    {
        int a,b;
        //cin >> a >> b;
        fin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }

    for(int i = 0; i < n; i++)
    {
        val[i] = 0;
    }

    dfs(0);

    int ans = m/val[0];

    if(m%val[0] != 0)
    {
        ans++;
    }    

    //cout << ans;
   fout << ans;
}