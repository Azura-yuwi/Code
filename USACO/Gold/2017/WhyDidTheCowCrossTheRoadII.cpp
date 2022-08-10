//USACO Gold 2017 February
//USACO Paths of Grids DP

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    ifstream fin("nocross.in");
    ofstream fout("nocross.out");

    int n; fin >> n;
    int l[n+1];
    int r[n+1];

    for(int i = 1; i <= n; i++)
    {
        fin >> l[i];
    }

    for(int i = 1; i <= n; i++)
    {
        fin >> r[i];
    }

    int dp[n+1][n+1];

    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(abs(l[i] - r[j]) <= 4)
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    fout << dp[n][n];


}