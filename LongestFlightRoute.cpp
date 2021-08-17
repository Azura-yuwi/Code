//CSES Graph 
//Topological Sort

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

vector<int> adj[100003]; 
vector<int> out[100003];
int in[100003];
int dp[100003];

int main()
{
    int n,m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        in[i] = 0;
        dp[i] = 0;
    }

    dp[0] = 1;

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        if(b != 1)
        {
            adj[a-1].pb(b-1);
            out[b-1].pb(a-1);
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

        for(int from : out[get])
        {
            dp[get] = max(dp[from], dp[get]);
        }
 
        if(out[get].size() > 0 & dp[get] != 0) //valid path
        {
            dp[get]++;
        }

        for(int to : adj[get])
        {
            if(in[to] > 0)
            {
                in[to]--;
                
                if(in[to] == 0)
                {
                    q.push(to);
                }
            }
        }
    }

    if(dp[n-1] == 0)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        vector<int> ans;
        ans.pb(n-1);

        cout << dp[n-1] << endl;

        int at = n-1;
        int count = 0;

        while(at != 0)
        {
            //cout << at << " " << dp[at] << endl;

            for(int pot : out[at])
            {   
                //cout << "POT " << pot << " " << dp[pot] << endl;
                if(dp[pot] + 1 == dp[at])
                {
                    at = pot;
                    ans.pb(pot);
                    //cout << "BREAK" << endl;
                    break;
                }
            }

            if(count > n)
            {
                break;
            }

            count++;
        }

        reverse(ans.begin(), ans.end());

        for(int i : ans)
        {
            cout << (i+1) << " ";
        }
    }
    
}