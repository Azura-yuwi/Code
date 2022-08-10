#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

int main()
{
    ofstream fout ("cbarn2.out");
    ifstream fin ("cbarn2.in");

    int n,k; fin >> n >> k;

    ll v[n];
    for(int i = 0; i < n; i++)
    {
        fin >> v[i];
    }

    ll rn[n][n]; //door at i, cow travel from i to j
    
    for(int r = 0; r < n; r++)
    {
        for(int i = 0; i < n; i++)
        {
            if(r == 0)
            {
                rn[i][i] = 0;
            }
            else
            {
                rn[(i-r+n)%n][i] = rn[(i-r+n)%n][(i-1 + n)%n] + v[i]*r;
            }
        }
    }

    ll dp[n][n][k]; //first door; last door; num of doors opened
    ll setmx = 1e18 + 100;

    for(int dr = 0; dr < k; dr++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dr == 0 && i == j)
                {
                    dp[i][i][0] = rn[i][(i-1+n)%n]; 
                }
                else
                {
                    dp[i][j][dr] = setmx;
                }
            }
        }
    }
    
    for(int dr = 1; dr < k; dr++)
    {
        for(int i = 0; i < n; i++) //first door
        {
            for(int j = i+dr-1; j < n; j++) //last door
            { 
                if(dp[i][j][dr-1] != setmx)
                {
                    for(int nxt = j+1; nxt < n; nxt++) //next door
                    {
                        ll get = dp[i][j][dr-1];
                        ll old = rn[j][(i-1+n)%n] - rn[j][nxt-1];
                        get -= old;
                        get += rn[nxt][(i-1+n)%n];
                        dp[i][nxt][dr] = min(dp[i][nxt][dr], get);
                    }
                }

            }
        }
    }

    ll ans = LLONG_MAX;

    for(int i = 0; i < n; i++)
    {
        for(int j = i+k-1; j < n; j++)
        {
            ans = min(ans, dp[i][j][k-1]);
        }
    }

    fout << ans;
}