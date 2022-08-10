#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

int twos(int a)
{
    int ans = 0;

    while(a != 0)
    {
        while(a%2 == 0)
        {
            a /= 2;
        }

        a--;
        ans++;
    }

    return ans;
}

int main()
{
    int n,k; cin >> n >> k;
    int adj[n][n];
    int dp[(1<<n)];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
    
    for(int i = 0; i < (1<<n); i++)
    {
        dp[i] = INT_MAX;
    }

    dp[(1<<n) - 1]  = 0;

    if(n == k)
    {
        cout << 0 << endl;
        return 0;
    }

    int ans = INT_MAX;

    for(int val = (1<<n) - 1; val > 0; val--)
    {
        if(twos(val) == k)
        {
            ans = min(ans, dp[val]);
        }
        else
        {

            for(int i = 0; i < n; i++) //get rid of i
            {
                if((val&(1<<i)) != 0)
                {
                    for(int j = 0; j < n; j++) //dump i into j;
                    { 
                        if(i != j )
                        {
                            if((val&(1<<j)) != 0)
                            {
                                dp[val - (1<<i)] = min(dp[val - (1<<i)], dp[val] + adj[i][j]);
                            }
                        }
                    }
                }    
            }

        }
    }

    cout << ans;
}