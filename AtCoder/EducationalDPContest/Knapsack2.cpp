#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

//note: tried with map; oot
// prob b/c map also longer time than array

int main()
{
    int n,W; cin >> n >> W;

    ll w[n];
    int v[n];

    for(int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }

    ll dp[n+1][1000*n + 1]; //max v[i] = 1000*n
    //stores minimum weiht for set value sum

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= 1000*n; j++)
        {
            dp[i][j] = W+1;
        }
    }

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= 1000*n; j++)
        {
            if(j < v[i-1])
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i-1]] + w[i-1]);
            }
        }
    }

    int ans = 0;

    for(int j = 1000*n; j > 0; j--)
    {
        if(dp[n][j] <= W)
        {
            ans = j; 
            break;
        }
    }

    cout << ans << endl;

}