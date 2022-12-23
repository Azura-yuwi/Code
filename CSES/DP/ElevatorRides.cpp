//USACO Guide Bitmask DP
//CSES DP

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

pair<int,int> dp[1<<20];

int main()
{
    int n,x; cin >> n >> x;
    int w[n];

    for(int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    dp[0] = mp(1,0);

    for(int i = 1; i < (1<<n); i++)
    {
        dp[i] = mp(20,INT_MAX);

        for(int j = 0; j < n; j++)
        {
            if((i&(1<<j)) != 0)
            {
                int prev = i - (1<<j);
                int elev = dp[prev].f;
                int wght = dp[prev].s + w[j];

                if(wght > x)
                {
                    wght = w[j];
                    elev++;
                }

                if(dp[i].f > elev)
                {
                    dp[i].f = elev;
                    dp[i].s = wght;
                }
                else if(dp[i].f == elev)
                {
                    dp[i].s = min(dp[i].s, wght);
                }

                //cout << i << " " << j << " " << dp[i].f << " " << dp[i].s << endl;
            }
        }
    }

    cout << dp[(1<<n) - 1].f;


}