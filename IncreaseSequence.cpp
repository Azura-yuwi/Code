#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll mod = 1e9 + 7;
    int n,h; cin >> n >> h;
    ll dp[n][n+1]; //index, open segments
    memset(dp, 0, sizeof(dp));
    int val[n];

    for(int i = 0; i < n; i++)
    {
        cin >> val[i]; 
    }

    if(val[0] == h) dp[0][0] = 1;
    else dp[0][0] = 0;

    if(val[0] == (h-1)) 
    { 
        dp[0][1] = 1; //[
        dp[0][0] = 1; // []
    }
    else 
    { dp[0][1] = 0; }

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= (i+1); j++)
        {
            if(val[i] + j == h)
            {
                dp[i][j] += dp[i-1][j]; //do nothing
                dp[i][j] %= mod;

                if(j > 0) dp[i][j] += dp[i-1][j-1]; //open [
                dp[i][j] %= mod;
            }

            if(val[i] + j + 1 == h) //can close one?
            {
                dp[i][j] += (j+1)*dp[i-1][j]; //open and close []
                dp[i][j] %= mod;

                dp[i][j] += (j+1)*dp[i-1][j+1]; //close ]
                dp[i][j] %= mod;
            }

            //cout << dp[i][j] << " ";
        }

        //cout << endl;
    }

    cout << dp[n-1][0];
}