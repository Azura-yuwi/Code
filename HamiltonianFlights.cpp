//CSES Graph
//Bitmask DP

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const ll mod  = (ll) 1e9 + 7;
vector<int> adj[20];
ll dp[1 << 20][20];

int main()
{
    int n,m; cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b; a--;b--;
        adj[b].pb(a); //b can be reached from a
    }
    
    dp[1][0] = 1;

    for(int s = 2; s < 1<<n; s++) 
    {
        if((s&(1<<0)) == 0) //chcek if it contains first city
        {
            continue;
        }

        if((s & (1 << (n-1))) && s != ((1<<n) - 1)) //has last city but is not full subset
        {
            continue;
        }

        for(int end = 0; end < n; end++)
        {
            if((s & (1 << end)) == 0) // does not contain end
            {
                continue;
            }

            int prev = s - (1<<end); //remove the end one

            for(int from : adj[end])
            {
                if((prev & (1<<from))) //contains from 
                {
                    dp[s][end] += dp[prev][from];
                    dp[s][end] %= mod;
                }
            }
        }
    }

    cout << dp[(1<<n) - 1][n-1];

    
}