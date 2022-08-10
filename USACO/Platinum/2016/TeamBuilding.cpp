#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

const ll mod = 1e9 + 9;

int main()
{
    ifstream fin("team.in");
    ofstream fout("team.out");

    int n,m,k; fin >> n >> m >> k;
    int jv[n];
    int pv[m];

    for(int i = 0; i < n; i++)
    {
        fin >> jv[i];
    }

    for(int j = 0; j < m; j++)
    {
        fin >> pv[j];
    }

    sort(jv, jv + n); sort(pv, pv + m);

    ll dp[n][m][k]; 

    //using first i cows of farmer john
    //the jth cow of farmer paul is paired
    // k total pairs done

    ll cul[n][m+1][k];

    for(int at = 0; at < k; at++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(at == 0)
                {
                    if(jv[i] > pv[j]) { dp[i][j][0] = 1; }
                    else { dp[i][j][0] = 0; }
                }
                else
                {
                    dp[i][j][at] = 0;
                }

                if(i>0) dp[i][j][at] += dp[i-1][j][at];
            }
        }
    }

    for(int at = 0; at < k; at++)
    {
        for(int i = 0; i < n; i++)
        {
            cul[i][0][at] = 0;

            for(int j = 0; j < m; j++)
            {
                cul[i][j+1][at] = cul[i][j][at] + dp[i][j][at]; cul[i][j+1][at] %= mod;
                
               // cout << "cul is "  << cul[i][j+1][at] << " " << i << " " << j << " " << at << endl;
            }

        }
    }

    for(int at = 1; at < k; at++)
    {
        for(int i = at; i < n; i++) //cow to check pairing
        {
            for(int j = at; j < m; j++)
            {
                if(jv[i] > pv[j]) //pair ith with jth
                { 
                    //dp[i][j][k] += dp[i-1][j-1][k-1]; //replace with some culmulative thing from 0 to j-1
                    dp[i][j][at] += cul[i-1][j][at-1];
                    dp[i][j][at] %= mod;

                    //cout << "added pair " << cul[i-1][j][at - 1] << endl;
                }

                dp[i][j][at] += dp[i-1][j][at]; //pair jth with something before it
                dp[i][j][at] %= mod;

                cul[i][j+1][at] = cul[i][j][at] + dp[i][j][at]; cul[i][j+1][at] %= mod;
               // cout << i << " " << j << " " << at << " " << dp[i][j][at] << " " << cul[i][j+1][at] << endl;
            }
        }
    }

    fout << cul[n-1][m][k-1] << endl;
}