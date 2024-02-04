//USACO Guide Intro to DP
//USACO Gold 2018 December

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    ifstream fin ("teamwork.in");
    ofstream fout ("teamwork.out");
    int n,k; fin >> n >> k;
    int val[n];

    for(int i = 0; i < n; i++)
    {
        fin >> val[i];
    }

    int high[n][k]; //max of interval of k+1 ending on n

    for(int i = 0; i < n; i++) //NK
    {
        for(int j = 0; j < min(k, i+1); j++)
        {
            if(j == 0)
            {
                high[i][j] = val[i];
            }
            else
            {
                high[i][j] = max(high[i][j-1], val[i-j]);
            }
        }
    }

    ll dp[n+1];
    dp[0] = 0;

    for(int i = 1; i <= n; i++) //also NK
    {
        dp[i] = 0;

        for(int j = 0; j < min(k,i); j++) 
        {
            dp[i] = max(dp[i], dp[i-j-1] + (j+1)*high[i-1][j]);
        }

        //cout << i << " " << dp[i] << endl;
    }

    fout << dp[n];
}