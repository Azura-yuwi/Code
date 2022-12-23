//CSES Graph
//Shortest Path--Dijkstra
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int main()
{
    int n,m;
    cin >> n >> m;

    vector<pair<int,int>> adj[n]; //node, weight;

    for(int i = 0; i < m; i++)
    {
        int a,b,w;
        cin >> a >> b >> w;
        adj[a-1].pb(mp(b-1,w));
    }

    ll dist[n];

    for(int i = 1; i < n; i++)
    {
        dist[i] = LLONG_MAX;
    }

    dist[0] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push(mp(0, 0));

    while(!pq.empty()) //dijkstra
    {
        ll cdist; int node; 
        tie(cdist, node) = pq.top();
        //cout << "AT " << node << " DIST " << cdist << " ACTUAL DIST " << dist[node] << endl;
        pq.pop();

        if(cdist != dist[node])
        {
            //cout << "CONTINUE " << endl;
            continue;
        }

        for(pair<int,int> to : adj[node])
        {
           // cout << "TO " << to.first << " CUR DIST " << dist[to.first] << " UPDATE DIST "<< (cdist + to.second) << endl;  
            if(cdist + to.second < dist[to.first])
            {
                dist[to.first] = cdist + to.second;
                //cout << "UPDATED  " << dist[to.first] << endl;
                pq.push(mp(dist[to.first], to.first));
            }
        }
    }

    cout << "0";

    for(int i = 1; i < n; i++)
    {
        cout << " " << dist[i];
    }


}