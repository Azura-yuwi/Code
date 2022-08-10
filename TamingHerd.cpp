#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int main()
{
    ifstream fin("taming.in");
    ofstream fout("taming.out");

    int n; fin >> n;
    int v[n];

    for(int i = 0; i < n; i++)
    {
        fin >> v[i];
    }

    ll bad[n][n]; //num of bad entries for breakout start at i end at j

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            bad[i][j] = 0;

            for(int at = 0; at <= (j-i); at++)
            {
                if(v[at+i] != at)
                {
                    bad[i][j]++;
                }
            }
        }
    }

    ll dp[n][n]; //num of breakouts, day of last breakout;

    for(int num = 0; num < n; num++)
    {
        for(int day = 0; day < n; day++)
        {
            dp[num][day] = LLONG_MAX;
        }
    }

    dp[0][0] = bad[0][n-1];

    for(int num = 1; num < n; num++)
    {
        for(int j = num; j < n; j++)
        {
            for(int k = num-1; k < j; k++)
            {
                if(dp[num-1][k] != LLONG_MAX)
                {
                    ll get = dp[num-1][k] - bad[k][n-1] + bad[k][j-1] + bad[j][n-1];
                    dp[num][j] = min(dp[num][j], get);
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
    { 
        ll out = LLONG_MAX;

        for(int j = 0; j < n; j++)
        {
            out = min(out, dp[i][j]);
        }

        fout << out << endl;
    }


}