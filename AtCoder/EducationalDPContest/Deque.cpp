//range dp
//minimax method in games (alteranting min and max)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pairiz
#define f first
#define s second

int main()
{
    int n; cin >> n;
    ll val[n];

    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    ll dp[n][n];

    for(int l = 0; l < n; l++)
    {
        for(int i = 0; i < n-l; i++)
        {
            if(l == 0)
            {
                if((n-l)%2 == 0) //2nd person --> minimizing
                {
                    dp[i][i] = (-1)*val[i];
                }
                else //1st person --> maximizing
                {
                    dp[i][i] = val[i];
                }
            }
            else
            {
                if((n-l)%2 == 0) //2nd person --> minimizing
                {
                    dp[i][i+l] = min(dp[i][i+l-1] - val[i+l], dp[i+1][i+l] - val[i]);
                }
                else //1st person --> maximizing
                {
                    dp[i][i+l] = max(dp[i][i+l-1] + val[i+l], dp[i+1][i+l] + val[i]);
                }
            }
        }
    }

    cout << dp[0][n-1];
}