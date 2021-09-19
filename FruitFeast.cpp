//USACO Gold 2015 December
//USACO Knapsack DP

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    ifstream fin("feast.in");
    ofstream fout("feast.out");

    int t,a,b; fin >> t >> a >> b;
    
    bool dp[t+2][2];

    for(int i = 1; i <= t; i++)
    {
        dp[i][0] = false; dp[i][1] = false;
    }

    dp[0][0] = true;
    dp[0][1] = true;
    dp[t+1][0] = false;
    dp[t+1][1] = false;

    for(int i = 1; i <= t; i++)
    {
        if(i >= a) { dp[i][0] = dp[i][0]|dp[i-a][0]; }

        if(i >= b) { dp[i][0] = dp[i][0]|dp[i-b][0]; }
    }

    for(int i = 1; i <= t; i++)
    {
        if(i >= a) { dp[i][1] = dp[i][1]|dp[i-a][1]; }

        if(i >= b) { dp[i][1] = dp[i][1]|dp[i-b][1]; }

        if(i <= t/2) { dp[i][1] = dp[i][1]|dp[i*2][0]|dp[i*2+1][0]; }
    }

    for(int i = t; i >= 0; i--)
    {
        if(dp[i][1])
        {
            fout << i;
            return 0;
        }
    }
}