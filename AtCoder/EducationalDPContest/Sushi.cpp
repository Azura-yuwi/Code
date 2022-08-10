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
    double dp[n+1][n+1][n+1]; //# of 1s, # of 2s, # of 3s
    int val[n];
    int num[4] = {0,0,0,0};

    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
        num[val[i]]++;
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            for(int k = 0; k <= n; k++)
            {
                dp[i][j][k] = 0;
            }
        }
    }

    dp[0][0][0] = 0;

    for(int k = 0; k <= n; k++)
    {
        for(int j = 0; j <= n; j++)
        {
            for(int i = 0; i <= n; i++)
            {
                double d = i+j+k;

                if(d>0)
                {
                    dp[i][j][k] += (double)n/d;
                }

                //cout << "i " << i << " j " << j << " k " << k << endl;

                if(i>0) 
                {
                    dp[i][j][k] += dp[i-1][j][k]*i/d;
                    //cout << "i " << setprecision(9) << dp[i-1][j][k] << " ";
                }

                if(j > 0 && i < n)
                {
                    dp[i][j][k] += dp[i+1][j-1][k]*j/d; //i needs to be updated before j
                    //cout << "j " << setprecision(9) << dp[i+1][j-1][k] << " ";
                } 
            
                if(k>0 && j < n) 
                {
                    dp[i][j][k] += dp[i][j+1][k-1]*k/d; //j needs to be updated before k
                    //cout << "k " << setprecision(9) << dp[i][j+1][k-1] << " ";
                }

               // cout << setprecision(9) <<dp[i][j][k] << " fin " << endl;
            }
        }
    }

    cout << setprecision(15) << dp[num[1]][num[2]][num[3]];


}