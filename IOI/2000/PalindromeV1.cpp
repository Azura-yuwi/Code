#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int main()
{
    int n; string str;
    cin >> n >> str;
    int dp[n][3]; //start; length

    for(int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
    }

    for(int i = 0; i < n-1; i++)
    {
        if(str[i] == str[i+1]) dp[i][1] = 0;
        else dp[i][1] = 1;
    }

    for(int l = 2; l < n; l++)
    {
        for(int i = 0; i < n-l; i++)
        {
            int lat = l%3;
            int lprev = (l+2)%3;
            int l2prev = (l+1)%3;

            dp[i][lat] = INT_MAX;

            if(str[i] == str[i+l])
            {
                dp[i][lat] = min(dp[i][lat], dp[i+1][l2prev]);
            }
                
            dp[i][lat] = min(dp[i][lat], min(dp[i][lprev], dp[i+1][lprev]) + 1);
        }
    }

    cout << dp[0][(n-1)%3];
}