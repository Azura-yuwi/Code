//CSES 
//USACO Range DP

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second


int dp[500][500];
int mod = 1e9 + 7;

int main()
{
    string s; cin >> s;
    int n = s.length();
    int val[n];

    for(int i = 0; i < n; i++)
    {
        val[i] = s[i] - 'a';
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            dp[i][j] = 1;
        }
    }

    for(int s = 1; s < n; s++)
    {
        for(int i = 0; i < n-s; i++)
        {
            if(val[i] == val[i+s] && dp[i+1][i+s-1] != -1)
            {
                dp[i][i+s] += dp[i+1][i+s-1];
            }

            for(int k = i+1; k < i+s; k++)
            {
                if(dp[i][k] != -1 && dp[k+1][i+s] != -1)
                {
                    dp[i][i+s] += dp[i][k]*dp[k+1][i+s];
                }
            }
        }
    }

    cout << dp[0][n-1];
}