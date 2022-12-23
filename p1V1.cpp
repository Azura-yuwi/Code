#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int main()
{
    int n,a,b; cin >> n >> a >> b;
    pair<int, pair<int,int>> f[n];

    for(int i = 0; i < n; i++)
    {
        int x,y,z; cin >> x >> y >> z;
        f[i] = mp(z, mp(y,(-1)*x)); // cost, brib, pop;
       //cin >> pop[i] >> brib[i] >> cos[i];
    }

    sort(f, f+n);

    pair<int,int> dp[a+1][n+1];

    for(int i = 0; i <= a ; i++)
    {
        dp[i][0] = mp(0, b); //pop, ice cream
    }

    for(int k = 0; k < n; k++)
    {
        int pop = (-1)*f[k].second.second; int brib = f[k].second.first; int cos = f[k].first;

        for(int i = a; i >= 0; i--)
        {
            dp[i][k+1] = dp[i][k];

            int ice = dp[i][k].second;
            int npop, nIce, nMoon;
            int mult = 0;

            while(mult*cos <= dp[i][k].second && mult <= brib)
            {
               // npop = dp[i][k].first + pop;
               // nIce = (ice - mult*cos);
               // nMoon = i - brib + mult;

                if(i >= brib - mult)
                {
                    dp[i][k+1] = max(dp[i][k+1], mp(dp[i][k].first + pop, dp[i][k].second - mult*cos));
                }

                mult++;
            }
        }
    }

    int ans = 0;

    for(int i = 0; i <= a; i++)
    {
        ans = max(ans, dp[i][n].first);
    }

    cout << ans;
}