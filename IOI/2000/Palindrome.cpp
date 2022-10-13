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
    int dp[n][n]; //start; length

    for(int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }

    for(int i = 0; i < n-1; i++)
    {
        if(str[i] == str[i+1]) dp[i][i+1] = 0;
        else dp[i][i+1] = 1;
    }

    for(int l = 2; l < n; l++)
    {
        for(int i = 0; i < n-l; i++)
        {
            dp[i][i+l] = INT_MAX;

            if(str[i] == str[i+l])
            {
                dp[i][i+l] = min(dp[i][i+l], dp[i+1][i+l-1]);
            }
                
            dp[i][i+l] = min(dp[i][i+l], min(dp[i][i+l-1], dp[i+1][i+l]) + 1);
        }
    }

    cout << dp[0][n-1];
}