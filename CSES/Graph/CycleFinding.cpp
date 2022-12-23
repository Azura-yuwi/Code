//CSES Graph
//Cycle Detection
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_tuple
#define pb push_back

ll setmax = (1e9)*5000 + 100;

int main()
{
    int n,m;
    cin >> n >> m;

    vector<tuple<int, int,int>> edges;

    ll dist[n];
    int p[n];
    bool visit[n];

    for(int i = 0; i < n; i++)
    {
        dist[i] = setmax;
        p[i] = i;
        visit[i] = false;
    }

    for(int i = 0; i < m; i++)
    {
        int a,b, w;
        cin >> a >> b >> w;
        edges.pb(mp(a-1,b-1,w));
    }

    for(int i = 0; i < n-1; i++)
    {
        for(auto e: edges)
        {
            int a,b,w;
            tie(a,b,w) = e;

            if(dist[b] > dist[a] + w)
            {
                dist[b] = dist[a] + w;
                p[b] = a;
            }
        }
    }

    bool work = false;

    for(auto e: edges)
    {
        int a,b,w;
        tie(a,b,w) = e;

        if(dist[b] > dist[a] + w)
        {
            cout << "YES" << endl;
            work = true;
            vector<int> ans;

            int og = b;
            visit[og] = true;

            ans.pb(og+1);
            //cout << og << endl;

            while(!visit[a])
            {
                //cout << (a+1) << " " << (b+1) << endl;
                ans.pb(a+1);
                b = a;
                visit[b] = true;
                a = p[b];
            }

            ans.pb((a+1));

            reverse(ans.begin(), ans.end());

            cout << (a+1);

            int count = 1;

            while(ans[count] != a+1)
            {
                cout << " " << (ans[count]);
                count++;
            }

            cout << " " << (a+1);
            
            break;
        }
    }

    if(!work)
    {
        cout << "NO";
    }

}
