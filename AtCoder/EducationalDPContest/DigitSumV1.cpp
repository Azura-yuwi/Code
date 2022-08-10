//digit dp

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

const ll mod = 1e9 + 7;

int main()
{
    string str; int d; cin >> str >> d; int n = str.length();
    ll dp[n+1][d+1][2];
    //dp[i][j][0] --> digit sum = j; from front digits 0 to i-1 is strictly less than number s[0] to s[i-1]
    //dp[i][j][1] --> digit um = j, taking the number s[0] to s[i-1];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j < d; j++)
        {
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
        }
    }

    dp[0][0][1] = 1; //set initial as 1 so only digits less than s[0] will get 1 in first iteration

    for(int i = 1; i <= n; i++) //left to right
    {
        for(int j = 0; j < d; j++)
        {
            for(int k = 0; k < 10; k++) //if (i-1)th digit is k
            {
                int c = str[i-1] - '0';
                int pM = ((j - k)%d + d)%d;

                if(k < c) //prefix from 0 to i-1 is less than s[0] to s[i-1]
                {
                    dp[i][j][0] += (dp[i-1][pM][0]%mod + dp[i-1][pM][1]%mod)%mod; dp[i][j][0] %= mod;
                }
                else if(k == c) //0 to i-1 is less only if 0 to i-2 was less
                {
                    dp[i][j][0] += dp[i-1][pM][0]; dp[i][j][0] %= mod;
                    dp[i][j][1] += dp[i-1][pM][1]; dp[i][j][1] %= mod;
                }
                else 
                {
                    //since k > s[i-1]; the number (from left) 0 to (i-1) only works if 0 to (i-2) was less than s[0] to s[i-2]
                    //thus this number will always be strictly less than s[0] to s[i-1];
                    dp[i][j][0] += dp[i-1][pM][0]; dp[i][j][0] %= mod;
                }

                //cout << i << " " << j << " " << k << " " << c << " " << pM << " " << dp[i][j][0] << " " << dp[i][j][1] << endl;
            }
        }
    }

    //note: dp[n][0][1] will be 1 if it digit sum of n is equal to d, else will be 0;

    cout << (dp[n][0][0]  - 1 + dp[n][0][1] + mod)%mod; //-1 = subtract out the number 0 (Choosing 0 for all digits)
}