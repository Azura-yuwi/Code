//USACO Gold 2021 January
//DP

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

vector<pair<int,int>> adj[50004]; 
ll dist[50004];

void dijkstra(int src)
{
    priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[src] = 0;
    pq.push(mp(0,src));

    while(!pq.empty())
    {
        ll cdist; int node; tie(cdist, node) = pq.top();
        pq.pop();

        if(cdist != dist[node])
        {
            continue;
        }

        for(pair<int,int> to : adj[node])
        {
            if(cdist + to.second < dist[to.first])
            {
                dist[to.first] = cdist + to.second;
                pq.push(mp(dist[to.first], to.first));
            }
        }
    }
}

int main()
{
    int n,k; cin >> n >> k;

    int breed[n];
    char com[k][k];

    for(int i = 0; i < n; i++)
    {
        cin >> breed[i]; breed[i]--;
        dist[i] = LLONG_MAX;
    }

    string s;

    for(int i = 0; i < k; i++)
    {
        cin >> s;

        for(int j = 0; j < k; j++)
        {
            com[i][j] = s[j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(com[breed[i]][breed[j]] != '0')
            {
                adj[i].pb(mp(j, abs(i-j)));
            }
        }
    }

    dijkstra(0);

    cout << dist[n-1];
}
