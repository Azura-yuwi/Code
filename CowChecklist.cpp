//USACO Gold 2016 December 
//USACO Paths of Grids DP

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    ifstream fin("checklist.in");
    ofstream fout("checklist.out");

    int h,g; fin >> h >> g;

    int xh[h], yh[h], xg[g+1], yg[g+1];

    for(int i = 0; i < h; i++)
    {
        fin >> xh[i] >> yh[i];
    }

    for(int j = 1; j <= g; j++)
    {
        fin >> xg[j] >> yg[j];
    }

    pair<int,int> dp[h][g+1];

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j <= g; j++)
        {
            dp[i][j] = mp(2e9 + 100, 2e9 + 100);
        }
    }

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j <= g; j++) //could be optimized a bit by doing a dist calculating function
        {
            if(i == 0)
            {
                if(j == 0)
                {
                    dp[0][0].first = 0;
                }
                else
                {
                    if(j == 1) { dp[0][j].second = dp[0][j-1].first + pow(abs(xh[0]- xg[j]), 2) + pow(abs(yh[0] - yg[j]), 2); }
                    else { dp[0][j].second = dp[0][j-1].second + pow(abs(xg[j-1]- xg[j]), 2) + pow(abs(yg[j-1] - yg[j]), 2); }
                }
            }
            else if (j == 0)
            {
                dp[i][0].first = dp[i-1][0].first + pow(abs(xh[i] - xh[i-1]),2) + pow(abs(yh[i] - yh[i-1]), 2);
            }
            else
            {
                dp[i][j].first = min(dp[i-1][j].first + pow(abs(xh[i] - xh[i-1]), 2) + pow(abs(yh[i] - yh[i-1]), 2), dp[i-1][j].second + pow(abs(xh[i] - xg[j]), 2) + pow(abs(yh[i] - yg[j]), 2));
                dp[i][j].second = min(dp[i][j-1].first + pow(abs(xg[j] - xh[i]), 2) + pow(abs(yg[j] - yh[i]), 2), dp[i][j-1].second + pow(abs(xg[j] - xg[j-1]), 2) + pow(abs(yg[j] - yg[j-1]), 2));
            }

            //cout << "i " << i << " j " << j << " DP " << dp[i][j].first << " " << dp[i][j].second << endl; 
        }
    }

    fout << dp[h-1][g].first;
}