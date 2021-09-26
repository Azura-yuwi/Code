//USACO Knapsack DP

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int calc(ll v, ll num)
{
    int ans = 0;
    ll value = v;

    while(value > 0 && value%num == 0)
    {
        ans++;
        value /= num;
    }

    return ans;
}

int main()
{
    int n,k; cin >> n >> k;

    ll val[n];
    int two[n];
    int five[n];

    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
        two[i] = calc(val[i], 2);
        five[i] = calc(val[i], 5);
        //cout << "VAL " << val[i] << " " << two[i] << " " << five[i] << endl;
    }

    int dp[k+1][5200]; //number of elements, number of fives = number of twos 

    for(int i = 0; i <= k; i++)
    {
        for(int j = 1; j < 5200; j++)
        {
            dp[i][j] = INT_MIN;
        }
    }

    for(int i = 0; i <= k; i++)
    {
        dp[i][0] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = k; j > 0; j--)
        {
            for(int l = five[i]; l < 5200; l++)
            {
                dp[j][l] = max(dp[j][l], dp[j-1][l-five[i]] + two[i]);
            }
        }
    }

    int ans = 0;

    for(int i = 1; i < 5200; i++)
    {
        ans = max(ans, min(i, dp[k][i]));
    }

    cout << ans;


   

}