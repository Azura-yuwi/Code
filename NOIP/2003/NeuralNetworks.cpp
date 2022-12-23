#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{
    int n,p; cin >> n >> p;
    int stat[n];
    int u[n]; int sum[n];
    
    vector<pair<int, int>> adj[n]; //node, weight
    int deg[n];

    for(int i = 0; i < n; i++)
    {
        deg[i] = 0; sum[i] = 0;
        cin >> stat[i] >> u[i];
    }

    for(int i = 0; i < p; i++)
    {
        int a,b,w; cin >> a >> b >> w; a--; b--;
        deg[b]++; 
        adj[a].pb(mp(b,w));
    }

    queue<int> q;

    for(int i = 0; i < n; i++)
    {
        if(deg[i] == 0)
        {
            u[i] = 0;
            q.push(i);
        }
    }

    vector<int> output; 

    while(!q.empty())
    {
        int i = q.front(); q.pop();
        stat[i] = max(stat[i], sum[i] - u[i]);

        for(pair<int,int> get : adj[i])
        {
            deg[get.f]--;
            sum[get.f] += get.s*stat[i];

            if(deg[get.f] == 0)
            {
                q.push(get.f);
            }
        }

        if(adj[i].size() == 0)
        {
            output.pb(i);
        }
    }

    bool nl = true;

    for(int i : output)
    {
        if(stat[i] != 0)
        {
            nl = false;
            break;
        }
    }

    if(nl)
    {
        cout << "NULL";
    }
    else
    {
        sort(output.begin(), output.end());

        for(int i : output)
        {
            if(stat[i] != 0) {cout << (i+1) << " " << stat[i] << endl;}
        }
    }


}