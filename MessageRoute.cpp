//CSES Graph
//BFS
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n,m;
    cin >> n >> m;

    vector<int> adj[n];
    int num[n];
    int from[n];

    for(int i = 0; i < n; i++)
    {
        num[i] = INT_MAX;
        from[i] = -1;
    }

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    queue<int> q;
    q.push(0);
    num[0] = 1;
    from[0] = 0;

    while(!q.empty())
    {
        int get = q.front();
        q.pop();

        for(int to : adj[get])
        {
            if(from[to] == -1)
            {
                from[to] = get;
                q.push(to);
            }
        }
    }

    if(from[n-1] == -1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        vector<int> ans;
        int at = n-1;
        ans.push_back(n);

        while(at != 0)
        {
            at = from[at];
            ans.push_back(at+1);
        }

        cout << ans.size() << endl;

        for(int i = ans.size()-1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
    }
}