//USACO Gold 2016 Open
//Range DP

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define f first
#define s second

int main()
{
    int n; cin >> n;
    int val[n+2];
    val[0] = 0;
    val[n+1] = 0;

    for(int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }

    int dp[n+1][n+1]; //start, end;

    for(int i = 0; i <= n+1; i++)
    {
        for(int j = 0; j <= n+1; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }

            dp[i][j] = -1;
        }

        dp[i][i] = val[i];
    }

    for(int l = 1; l < n; l++)
    {
        for(int i = 1; i <= n; i++)
        {
            
        }
    }

}