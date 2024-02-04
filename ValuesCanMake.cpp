//Knapsack DP
//CodeForces Round 360 C

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second


int main()
{
    int n,k; cin >> n >> k;
    int c[n];

    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    bool made[k+1];
    bool dp[k+1][k+1];

    for(int i = 0; i <= k; i++)
    {
        made[i] = false;
        dp[i][0] = true;

        for(int j = 1; j <= k; j++)
        {
            dp[i][j] = false;
        }
    }

    made[0] = true;

    for(int i = 0; i < n; i++)
    {
        for(int j = k; j >= c[i]; j--)
        {
            if(made[j-c[i]])
            {
                made[j] = true;

                for(int l = k; l > 0; l--)
                {
                    if(dp[j-c[i]][l] || (l >= c[i] && dp[j-c[i]][l-c[i]]))
                    {
                        dp[j][l] = true;
                    }
                }
            }
        }
    }

    int num = 0;

    for(int i = 0; i <= k; i++)
    {
        if (dp[k][i])
        {
            num++;
        }
    }

    cout << num << endl;

    for(int i = 0; i <= k; i++)
    {
        if(dp[k][i])
        {
            cout << i << " ";
        }
    }
}