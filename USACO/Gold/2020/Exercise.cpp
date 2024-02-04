//USACO Gold 2020 Open
//DP

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int main()
{
    ifstream fin("exercise.in");
    ofstream fout("exercise.out");

    int n; ll m; fin >> n >> m;

    vector<int> primes;
    bool isprimes;

    for(int i = 2; i <= n; i++)
    {
        isprimes = true;
        for(int j = 0; j < primes.size(); j++)
        {
            if(primes[j] * primes[j] > n)
            {
                break;
            }

            if(i % primes[j] == 0)
            {
                isprimes = false;
                break;
            }
        }

        if(isprimes)
        {
            primes.pb(i);
        }
    }

    ll dp[primes.size() + 1][n+1]; //at which prime, sum of possible k for certain sum
    
    for(int i = 0; i <= n; i++)
    {
        dp[0][i] = 1;
    }

    for(int i = 1; i <= primes.size(); i++) // sum
    {
        for(int j = 0; j <= n; j++)
        {
            dp[i][j] = dp[i-1][j];
            int p = primes[i-1]; //prime power to work with;

            while(p <= j)
            {
                dp[i][j] += (dp[i-1][j-p]*p); dp[i][j] %= m;
                p *= primes[i-1]; p %= m;
            }
        }

        //cout <<  "prime " << primes[i-1] << " sum " << dp[i][n] << endl;
    }

    fout << dp[primes.size()][n];
}