#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int main()
{
    ifstream fin("cowmbat.in");
    ofstream fout("cowmbat.out");
    int n,m,k; fin >> n >> m >> k;
    int num[n];
    int cst[m][m];

    for(int i = 0; i < n; i++)
    {
        char get; fin >> get; num[i] = get - 'a';
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            fin >> cst[i][j];
        }
    }

    for(int p = 0; p < m; p++)
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cst[i][j] = min(cst[i][j], cst[i][p] + cst[p][j]);
            }
        }
    }

    ll pre[n+1][m];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i == 0) { pre[i][j] = 0; }
            else { pre[i][j] = pre[i-1][j] + cst[num[i-1]][j]; }
        }
    }

    ll ans[n];
    ll dp[n][m];

    for(int i = 0; i < k; i++)
    {
        ans[i] = 1e9;

        for(int j = 0; j < m; j++)
        {
            dp[i][j] = 1e9;
            if(i == k-1) { dp[i][j] = pre[i+1][j]; }
            ans[i] = min(ans[i], dp[i][j]);
        }
    }

    for(int i = k; i < n; i++)
    {
        ans[i] = 1e9;

        for(int j = 0; j < m; j++)
        {
            dp[i][j] = 1e9;
            dp[i][j] = min(dp[i][j], ans[i-k] + pre[i+1][j] - pre[i-k+1][j]); // make new k block
            dp[i][j] = min(dp[i][j], dp[i-1][j] + cst[num[i]][j]); // fit into existing block
            ans[i] = min(ans[i], dp[i][j]);
        }
    }


    fout << ans[n-1];
}