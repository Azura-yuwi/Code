#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, x;
    cin >> n >> x;
    int prices[n];
    int pages[n];
    int pgMax[n+1][x+1];

    for(int i = 0; i <= x; i++)
    {
        pgMax[0][i] = 0;
    }
    for(int i = 0; i <= n; i++)
    {
        pgMax[i][0] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }


    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= x; j++)
        {
            if(j >= prices[i-1])
            {
                pgMax[i][j] = max(pgMax[i-1][j], pgMax[i-1][j-prices[i-1]] + pages[i-1]);
            }
            else
            {
                pgMax[i][j] = pgMax[i-1][j];
            }

            //cout << i << " " << j << " " << pgMax[i][j] << " " << pages[i-1] << endl;
        }
    }
    
    int ans = 0;

    for(int i = 1; i <= x; i++)
    {
        ans = max(pgMax[n][i], ans);
    }

    cout << ans;
}
