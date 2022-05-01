#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll mod = 1e9 + 7;
    int n,k; cin >> n >> k;
    ll dp[2][n+1][k+1]; //node, open, intersections
    ll pre[n+1][k+2];
    memset(pre, 0, sizeof(pre));
    memset(dp, 0, sizeof(dp));
    //cout << sizeof(dp) << endl;

    dp[1][0][0] = 1;
    dp[1][1][0] = 1;

    for(int i = 2; i <= n; i++)
    {
        //must compress otherwise segmentation error
        int index = i%2;
        int prev = (i-1)%2;

        for(int open = 0; open < i; open++)
        {   
            pre[open][0] = 0;

            for(int sect = 0; sect <= k; sect++)
            {
                pre[open][sect+1] = pre[open][sect] + dp[prev][open][sect];
                pre[open][sect+1] %= mod;
            }
        }

        for(int open = 0; open <= i; open++)
        {
            for(int sect = 0; sect <= k; sect++)
            {
                if(open < i) dp[index][open][sect] = dp[prev][open][sect]; //do nothing
                else dp[index][open][sect] = 0;

                if(open > 0) dp[index][open][sect] += dp[prev][open-1][sect]; //add a open interval
                dp[index][open][sect] %= mod;

                //close an interval
                if(open < i-1)
                {
                    dp[index][open][sect] += ( (pre[open+1][sect+1] - pre[open+1][sect - min(open,sect)] + mod) %mod); 
                    dp[index][open][sect] %= mod;

                    /* //times out in last case
                    for(int canSect = 0; canSect <= min(open, sect); canSect++)
                    {
                        dp[i][open][sect] += dp[i-1][open+1][sect-canSect];
                        dp[i][open][sect] %= mod;
                    }*/
                }

                //cout << dp[index][open][sect] << " ";
            }

            //cout << endl;
        }
    }

    cout << dp[n%2][0][k];
}