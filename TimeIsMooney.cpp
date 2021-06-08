#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define pb push_back

int main()
{
    ofstream fout ("time.out");
    ifstream fin ("time.in");

    int n, m, c;
    fin >> n >> m >> c;

    int cost[n];

    for (int i = 0; i < n; i++)
    {
        fin >> cost[i];
    }

    vector<int> graph[n];

    for(int i = 0; i < m; i++)
    {
        int a, b;
        fin >> a >> b;

        graph[b-1].pb(a-1);
    }

    int bound = 500/c + 1;

    int dp[n][bound+1];

    for(int i = 0; i < n; i++)
    {
        dp[i][0] = -1000000;
    }

    dp[0][0] = 0;


    for (int t = 1; t <= bound; t++)
    {
        for (int i = 0; i < n; i++)
        {
            dp[i][t] = -1000000;

            for(int j : graph[i])
            {
                dp[i][t] = max(dp[i][t], dp[j][t-1]);
            }

            dp[i][t] = dp[i][t] + cost[i] - (2*t-1)*c;
        }
    }
 
    int answer = 0;

    for(int i = 1; i <= bound; i++)
    {
        answer = max(dp[0][i], answer);
    }

    fout << answer;

    return 0;
}