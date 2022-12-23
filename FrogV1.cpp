#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int n; cin >> n;
    int s,t,m; cin >> s >> t >> m;
    int stone[m];
    vector<int> dp;

    for(int i = 0; i < m; i++)
    {
        cin >> stone[i];
    }

    sort(stone, stone + m);
    
    dp.pb(0);
    int ind = 0;

    for(int i = 1; i < s; i++)
    {
        dp.pb(101);
    }

    for(int i = s; i < t; i++)
    {
        int get = 101;
        //dp.pb(101);

        for(int j = 0; j <= i-s; j++)
        {
            get = min(get, dp[j]);
        }

        if(ind < m && stone[ind] == i)
        {
            get++; ind++; 
        }

        dp.pb(get);
    }

    for(int i = t; i <= (n-s); i++)
    {
        int get = 101; 
        
        for(int j = 0; j <= (t-s); j++)
        {
            get = min(get, dp[j]);
        }

        if(ind < m && stone[ind] == i)
        {
            get++; ind++;
        }

        //cout << i << " " << get << endl;

        dp.erase(dp.begin());
        dp.pb(get);
    }

    int ans = 101;

    for(int i = dp.size() - 1; i >= (dp.size() - 1 - (t-s)); i--)
    {
        //cout << "finding anwer " << i << " " << dp[i] << endl;

        if(i < 0) continue;

        ans = min(ans, dp[i]);
    }

    cout << ans;
}