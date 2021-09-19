//oj.uz--NOI18_KNAPSACK
//USACO Knapsack DP

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int s,n; cin >> s >> n;

    pair<int,pair<int,int>> items[n];

    for(int i = 0; i < n; i++)
    {
        int v, w, c; cin >> v >> w >> c;
        items[i] = mp(w, mp(v, c));
    }

    sort(items, items + n, greater<pair<int,pair<int,int>>>());

    ll dp[s+1];

    for(int i = 0; i <= s; i++)
    {
        dp[i] = -1e10;
    }

    dp[0] = 0;
    int prevwgh = 0;
    int num = 0;

    int val,wgh,copy,upto;

    for(int i = 0; i < n; i++)
    {
        val = items[i].second.first;
        wgh = items[i].first;
        copy = items[i].second.second;
        upto = min(copy, s/wgh);

        if(wgh == prevwgh && num >= s/wgh)
        {
            continue;
        }

        if(wgh == prevwgh)
        {
            num++;
        }
        else
        {
            num = 0; 
            prevwgh = wgh;
        }

        //cout << "VAL " << val << " WEIGHT " << wgh << " COPIES " << copy << " UPTO " << upto << endl; 

        for(int k = s; k >= wgh; k--)
        {
            for(int j = 1; j <= upto; j++)
            {
                if(k >= wgh*j && (dp[k] != -1e10 || dp[k-wgh*j] != -1e10))
                { 
                    dp[k] = max(dp[k], dp[k-wgh*j] + val*j);
                }
            }

            //cout << "K " << k << " " << dp[k] << endl;
        }
    }

    ll ans = 0;

    for(int i = 0; i <= s; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans;
}