//USACO Gold 2019 Open
//USACO Intro to DP

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    ifstream fin("snakes.in");
    ofstream fout("snakes.out");

    int n,k; fin >> n >> k;

    int val[n];

    int pre[n+1];
    pre[0] = 0;

    for(int i = 0; i < n; i++)
    {
        fin >> val[i];
        pre[i+1] = pre[i] + val[i];
    }

    int high[n][n]; //[i][j] --> max of interval of j+1 ending on i;; i.e starts on i-j and ends on i;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < min(n, i+1); j++)
        {
            if(j == 0)
            {
                high[i][j] = val[i];
            }
            else
            {
                high[i][j] = max(high[i][j-1], val[i-j]);
            }
        }
    }
    
    int dp[k+1][n];

    for(int i = 0; i <= k; i++)
    {
        for(int j = 0; j < n; j++)
        {
            //cout << i << " " << j << " " << endl;
            if(i == 0)
            {
                dp[i][j] = high[j][j]*(j+1) - pre[j+1];
            }
            else
            {
                dp[i][j] = dp[i-1][j];

                for(int a = j; a > 0; a--)
                {
                    dp[i][j] = min(dp[i][j], dp[i-1][a-1] + high[j][j-a]*(j-a+1) - pre[j+1] + pre[a]);
                    //cout << a << " " << dp[i][j] << " " << dp[i-1][a-1] << " " << high[j][j-a] << " " << pre[j+1]-pre[a] << endl;
                }
            }
            
            //cout << dp[i][j] << endl;
        }
    }

    fout << dp[k][n-1];
}
