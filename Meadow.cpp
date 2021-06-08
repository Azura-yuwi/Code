#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int n,k,w;
    cin >> n >> k >> w;
    int dist[n];
    ll mins[n][w+1] = {INT_MAX};
    ll area[n][w+1];

    for(int i = 0; i < n; i++)
    {
        cin >> dist[i];
        mins[i][1] = dist[i];
        area[i][1] = dist[i];
    }
    
    for(int i = 2; i <= w; i++)
    {
        for(int j = 0; j <= n-i; j++)
        {
            mins[j][i] = min(mins[j+1][i-1],mins[j][1]);
            area[j][i] = i*mins[j][i];
            //cout << j << " " << i << " " << mins[j][i] << endl;
        }
    }
    
    ll dp[k+1][n][n] = {-1000000};

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            for(int str = i; str <= j; str++)
            {
                for(int wid = 1; wid <= min(w, j-str+1); wid++)
                {
                    dp[1][i][j] = max(dp[1][i][j], area[str][wid]);
                }
            }
        }
    }

    for (int i = 2; i <= k; i++)
    {
        for(int str = 0; str < n; str++)
        {
            for(int end = str; end < n; end++)
            {  
                for(int mid = str+i-2; mid < end; mid++)
                {
                    dp[i][str][end] = max(dp[i][str][end], dp[i-1][str][mid] + dp[1][mid+1][end]);
                }
            }
        }
    }

    cout << dp[k][0][n-1];
    return 0;
}