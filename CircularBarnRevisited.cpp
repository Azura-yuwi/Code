#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main()
{
    ofstream fout ("cbarn2.out");
    ifstream fin ("cbarn2.in");

    int n, k;
    fin >> n >> k;

    int cows[n];
    int sum;

    for(int i = 0; i < n; i++)
    {
        fin >> cows[i];
    }

    for(int src = 0; src < n; src++) //make circle a line
    {
        int dp[n][k];
        int val[n][n];

        for (int i = 0; i < n; i++)
        {
            int to = (src + i)%n;
            val[to][to] = 0;

            for (int j = i+1; j < n; j++)
            {
                int next = (src + j)%n;
                val[to][next] = val[to][next - 1] + (j-i)*cows[next];
            }
        }

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1000000;
        }

        dp[src][0] = val[src][(src - 1)%n];
        
        for(int door = 1; door < k; k++)
        {
            int min = INT_MAX;
            int minIndex = -1;

            for(int i = door; i < n; i++)
            {
                int to = (src + i)%n;

                if(min > dp[to-1][door-1])
                {
                    min = dp[to-1][door-1];
                    minIndex = to-1;
                }

                dp[to][door] =  val[to][(src-1)%n]; 
            }

        }
    }
}