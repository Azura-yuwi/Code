#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first

int main()
{
    string s,t; cin >> s >> t;
    
    int dp[s.length()+1][t.length()+1]; //much faster than appending characters onto strings multiple times
    pair<int,int> from[s.length()+1][t.length()+1];

    for(int i = 0; i < s.length()+1; i++)
    {
        dp[i][0] = 0;
    }

    for(int i = 0; i < t.length()+1; i++)
    {
        dp[0][i] = 0;
    }

    for(int i = 1; i <= s.length(); i++)
    {
        for(int j = 1; j <= t.length(); j++)
        {
            from[i][j] = mp(0,0);

            if(dp[i-1][j] > dp[i][j-1])
            {
                dp[i][j] = dp[i-1][j];
                from[i][j].first = i-1;
                from[i][j].second = j;
            }
            else
            {
                dp[i][j] = dp[i][j-1];
                from[i][j].first = i;
                from[i][j].second = j-1;
            }

            if(s[i-1] == t[j-1] && dp[i-1][j-1] + 1 > dp[i][j])
            {
                dp[i][j] = (dp[i-1][j-1] + 1);
                from[i][j].first = i-1;
                from[i][j].second = j-1;
            }
        }
    }

    //build string with path

    string ans = "";
    int x = s.length();
    int y = t.length();

    while(x != 0 && y != 0)
    {
        if(from[x][y].first == x-1 && from[x][y].second == y-1)
        {
            ans += s[x-1];
        }

        tie(x,y) = from[x][y];
    }

    //cout << ans;
    reverse(ans.begin(), ans.end());
    cout << ans;

}