#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    ofstream fout ("windows.out");
    ifstream fin ("windows.in");

    int n, k;
    //cin >> n >> k;
    fin >> n >> k;

    pair<int,int> dp[2][n+1];
    int dirt[n+1];
    dirt[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        //cin >> dirt[i];
        fin >> dirt[i];
    }

    for(int i = 0; i <= n; i++)
    {
        dp[0][i] = mp(0,1);
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) // i = windows cleaned
    {
        dp[i%2][i-1] = mp(k+1, i-1);

        for(int j = i; j <= n; j++) //j => clean from windows 1 to j
        {
            dp[i%2][j] = mp(min(dp[(i+1)%2][j-1].first + j - dp[(i+1)%2][j-1].second + dirt[j], k+1), j); //clean window

            if(dp[i%2][j].first > dp[i%2][j-1].first) //better to not clean window
            {
                dp[i%2][j].first = dp[i%2][j-1].first;
                dp[i%2][j].second = dp[i%2][j-1].second;
            }

           //cout << i << " " << j << " (" << dp[i%2][j].first << "," << dp[i%2][j].second << ")  " << endl;
        }

        if(dp[i%2][n].first <= k)
        {
            ans = i;
        }
        else
        {
            break;
        }
    }

    //cout << ans;
    fout << ans;

}