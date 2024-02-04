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

    vector<pair<ll,ll>> weights[s+1];

    //pair<int,pair<int,int>> items[n];

    for(int i = 0; i < n; i++)
    {
        int v, w, k; cin >> v >> w >> k;
        //items[i] = mp(w, mp(v, k));
        
        if(w <= s)
        {
            weights[w].pb(mp(v,k));
        }
    }

    for(int i = 0; i <= s; i++)
    {
        sort(weights[i].begin(), weights[i].end(), greater());
    }

    ll dp[s+1];

    for(int i = 0; i <= s; i++)
    {
        dp[i] = 0;
    }

    for(int w = 1; w <= s; w++)
    {
        int i = 0; int tot = 0;

        while(i < weights[w].size() && tot <= s)
        {
            ll v,k; tie(v,k) = weights[w][i];

            for(int j = s; j >= w; j--)
            {
                dp[j] = max(dp[j], dp[j-w] + v);
            }

            weights[w][i].second -= 1; 

            if(k == 1)
            {
                i++;
            }

            tot += w;
        }
    }

    cout << dp[s];
}