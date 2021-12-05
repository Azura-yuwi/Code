//USACO Range DP

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second


int dp[248][248];

int main()
{
    ifstream fin("248.in");
    ofstream fout("248.out");

    int n; fin >> n;
    int val[n];

    for(int i = 0; i < n; i++)
    {
        fin >> val[i];
    }

    int ans = 0;

    for(int s = 0; s < n; s++)
    {
        for(int i = 0; i < n-s; i++)
        {
            if(s == 0)
            {
                dp[i][i] = val[i]; 
                ans = max(ans, dp[i][i]);
                continue;
            }

            dp[i][i+s] = -1;

            for(int j = i; j <= i+s; j++)
            {
                if(dp[i][j] != -1 && dp[i][j] == dp[j+1][i+s])
                {
                    dp[i][i+s] = max(dp[i][i+s], dp[i][j]+1);
                }
            }

            ans = max(ans, dp[i][i+s]);
        }
    }
    
    fout << ans;

}
