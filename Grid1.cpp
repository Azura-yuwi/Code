#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int h,w; cin >> h >> w; 
    int grid[h][w];
    int dp[h][w];

    for(int i = 0; i < h; i++)
    {
        string s; cin >> s;

        for(int j = 0; j < w; j++)
        {
            if(s[j] == '.')
            {
                grid[i][j] = 0;
            }
            else
            {
                grid[i][j] = 1;
            }

            dp[i][j] = 0;
        }
    }

    if(grid)
    {
        
    }
}