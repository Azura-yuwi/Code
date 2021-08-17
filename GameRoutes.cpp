//CSES Graph 
//Topological Sort

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main()
{
    int n, m;
    cin >> n >> m;

    int in[n];
    int val[n];
    int mod = 1e9 + 7;
    vector<int> adj[n];

    for(int i = 0; i < n; i++)
    {
        in[i] = 0;
        val[i] = 0;
    }

    val[0] = 1;

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        if(b != 1)
        {
            adj[a-1].pb(b-1);
            in[b-1]++;
        }
    }

    queue<int> q;

    for(int i = n-1; i >= 0; i--)
    {
        if(in[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int get = q.front();
        q.pop();

        for(int i : adj[get])
        {
            if(in[i] > 0) //if == 0, you would have visited before
            {
                in[i]--;
                val[i] += val[get];
                val[i] %= mod;

                if(in[i] == 0)
                {
                    q.push(i);
                }
            }
        } 
    }

    cout << val[n-1];

}