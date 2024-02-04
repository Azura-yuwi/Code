//USACO Guide Intro to DP
//USACO Gold 2017 Jan

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    ifstream fin ("hps.in");
    ofstream fout ("hps.out");
    int n,k; fin >> n >> k;
    int val[n+1];

    for(int i = 1; i <= n; i++)
    {
        char get; fin >> get;

        if(get == 'H')
        {
            val[i] = 0;
        }
        else if(get == 'P')
        {
            val[i] = 1;
        }
        else
        {
            val[i] = 2;
        }
    }

    int dp[n+1][k+1][3];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            for(int s = 0; s < 3; s++)
            {
                if(i == 0)
                {
                    dp[i][j][s] = 0;
                }
                else
                {
                    if(j == 0)
                    {
                        dp[i][j][s] = dp[i-1][j][s];
                        if(val[i] == s)
                        {
                            dp[i][j][s]++;
                        }
                    }
                    else
                    {
                        dp[i][j][s] = max(max(dp[i-1][j][s], dp[i-1][j-1][(s+1)%3]), dp[i-1][j-1][(s+2)%3]) + (val[i] == s ? 1 : 0);
                    }
                }
            }
        }
    }

    fout << max(max(dp[n][k][0], dp[n][k][1]), dp[n][k][2]);
}