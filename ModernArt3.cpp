//USACO Range DP

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second


int dp[300][300];

int main()
{
    int n; cin >> n;
    int cl[n];

    for(int i = 0; i < n; i++)
    {
        cin >> cl[i];
    }

    for(int s = 1; s < n; s++)
    {
        for(int i = 0; i < n-s; i++)
        {
            if(cl[i] == cl[i+s])
            {
                dp[i][i+s] = max(dp[i][i+s], dp[i+1][i+s-1] + 1); //if i+1  > i+s-1 --> should default ot 0
            }

            for(int k = i+1; k < i+s; k++)
            {
                dp[i][i+s] = max(dp[i][i+s], dp[i][k] + dp[k][i+s]);
                
            }
        }
    }
    
    cout << n - dp[0][n-1];

}