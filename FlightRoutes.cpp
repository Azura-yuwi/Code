//CSES Graph
//Shortest Path
//** to review

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

//ll setmax = (1e9)*5000 + 100;

int main()
{
    int n,m,k;
    cin >> n >> m >> k;

    vector<pair<int, int>> adj[n];

    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;

        adj[a-1].pb(mp(b-1, c));
    }

    priority_queue<ll> dist[n]; //largest to smallest

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll,int>>> pq; //price, node

    pq.push(mp(0, 0));
    dist[0].push(0);

    while(!pq.empty())
    {
        auto get = pq.top();
        pq.pop();

        if(dist[get.s].top() < get.f) //we want the k smallest, if the one we are at is already bigger than largest there, we don't need it
        {
            continue;
        }

        for(auto& nxt : adj[get.s])
        {
            ll price = nxt.s + get.f;

            if(dist[nxt.f].size() < k)
            {
                dist[nxt.f].push(price);
                pq.push(mp(price, nxt.f));
            }
            else if(price < dist[nxt.f].top())
            {
                dist[nxt.f].pop();
                dist[nxt.f].push(price);
                pq.push(mp(price,nxt.f));
            }   
        }        
    }

    vector<ll> ans;

    while(dist[n-1].size() > 0)
    {
        ans.pb(dist[n-1].top());
        dist[n-1].pop();
    }

    reverse(ans.begin(), ans.end());

    for(ll i : ans)
    {
        cout << i << " ";
    }
}
 