#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{
    int n; cin >> n;
    double p[n+1];

    for(int i = 0; i < n; i++)
    {
        cin >> p[i+1];
    }

    double dp[n+1][n+1]; //coin on, # of heads

    for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < n+1; j++)
        {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            dp[i][j] = dp[i-1][j]*(1-p[i]); //get a tail

            if(j > 0)
            {
                dp[i][j] += dp[i-1][j-1]*p[i]; //get a head
            }
        }
    }

    double ans = 0;

    for(int i = ((n+1)/2); i <= n; i++)
    {        
        ans += dp[n][i];
    }

    cout << setprecision(9) << ans << endl; //dpn't forget to do this so answer printed is in error bound

}