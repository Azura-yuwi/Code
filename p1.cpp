#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main()
{
    int n,a,b; cin >> n >> a >> b;
    int pop[n]; int brib[n]; int cos[n];

    for(int i = 0; i < n; i++)
    {
        cin >> pop[i] >> brib[i] >> cos[i];
    }

    int dp[a+1][b+1];

    for(int i = 0; i <= a ; i++)
    {
        for(int j = 0; j <= b; j++)
        {
            dp[i][j] = 0;
        }
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = a; i >= 0; i--)
        {
            for(int j = b; j >= 0; j--)
            {
                //dp[i][j][k+1] = dp[i][j][k];

                int mult = 0;

                while(mult*cos[k] <= j && mult <= brib[k])
                {
                    if(i >= brib[k]-mult)
                    {
                        dp[i][j] = max(dp[i][j], dp[i-brib[k]+mult][j-mult*cos[k]]+ pop[k]);
                    }

                    mult++;
                }
            }
        }
    }

    int ans = 0;

    for(int i = 0; i <= a; i++)
    {
        for(int j = 0; j <= b; j++)
        {
            ans = max(ans, dp[i][j]);
        }   
    }

    cout << ans;


}