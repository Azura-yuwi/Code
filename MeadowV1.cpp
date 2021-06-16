#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n,k,w;
    cin >> n >> k >> w;
    int dist[n];
    ll mins[n][w+1] = {INT_MAX}; //start, width
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

    ll dp[k+1][n] = {-10000001}; //number of rectangles, end
    ll start[n] = {-10000001};
    start[n-1] = area[n-1][1];

    cout << "START CALCS" << endl;

    for(int i = n-2; i >= 0; i--)
    {
        start[i] = start[i+1];

        for(int wid = 1; wid <= min(w, n-i); wid++)
        {
            start[i] = max(start[i], area[i][wid]);
        }

        cout << i << " " << start[i] << endl;
    }

    dp[1][0] = area[0][1];

    for(int i = 1; i < n; i++)
    {
        dp[1][i] = dp[1][i-1];

        for(int wid = 1; wid <= min(i+1, w); wid++)
        {
            dp[1][i] = max(dp[1][i], area[i-wid+1][wid]);
        }
    }

    for(int i = 2; i <= k; i++)
    {
        for(int j = 0; j < n-1; j++)
        {
            dp[i][j] = dp[i-1][j] + start[j+1];
        }
    }

    cout << dp[k][n];
    return 0;
}