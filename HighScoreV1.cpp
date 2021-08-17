//CSES Graph
//Shortest Path--Bellman Ford, "Negative" Cycles 

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_tuple
#define pb push_back
#define f first 
#define s second

ll setmin = -(1e9)*2501 - 100;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges; 

    ll dist[n];
    ll dn[n];

    for(int i = 0; i < n; i++)
    {
        dist[i] = setmin;
        dn[i] = setmin;
    }

    dist[0] = 0;
    dn[n-1] = 0;

    for(int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.pb(mp(a-1,b-1,w));
    }

    for(int i = 0; i < n-1; i++)
    {
        for(auto e : edges)
        {
            int a, b, w;
            tie(a, b, w) = e;

            if(dist[b] != setmin || dist[a] != setmin) // setmin --> not reachable yet
            {
                dist[b] = max(dist[b], dist[a] + w);
            }

            if(dn[a] != setmin || dn[b] != setmin) //either a or b reachable to update
            {
                dn[a] = max(dn[a] , dn[b] + w); 
            }
        }
    }

    ll copy[n];

    for(int i = 0; i < n; i++)
    {
        copy[i] = dist[i];
    }

    for(auto e : edges)
    {
        int a, b, w;
        tie(a, b, w) = e;
        copy[b] = max(copy[b], copy[a] + w);
    }

    for(int i = 0; i < n; i++)
    {
        if(copy[i] > dist[i] && dist[i] > setmin && dn[i] > setmin) //**1 -> i -> n
        {
            cout << -1;
            return 0;
        } 
    }

    cout << dist[n-1];
 }
 
 //** if dist[i] can infinitely increase:
 //   need to check that you can reach i from 1 and reach n from i
 //   to show that dist[n] can also infinitely increase
 //   so like bellman for dn part kind of overkill
 //   ... (but you could do it in same loop so i just did it like that)
 //   with bellman, dist[i] = some min --> you can not reach i from start
 //   so as long as you maintain min to those not reached, you don't need separate thing to calculate
 //   but the og update: dist[b] = max(dist[b], dist[a] + w) not necessarily preserve the min
 //   so I changed the update part a bit
 //   overall kind of ( ╯°□°)╯ ┻━━┻