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

    pair<int,int> dp[n+1];
    pair<int,int> copy[n+1];
    int dirt[n+1];
    dirt[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        //cin >> dirt[i];
        fin >> dirt[i];
    }

    for(int i = 0; i <= n; i++)
    {
        copy[i] = mp(0,1);
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) // i = windows cleaned
    {
        dp[i-1] = mp(k+1, i-1);

        for(int j = i; j <= n; j++) //j => clean from windows 1 to j
        {
            dp[j] = mp(min(copy[j-1].first + j - copy[j-1].second + dirt[j], k+1), j); //clean window

            if(dp[j].first > dp[j-1].first) //better to not clean window
            {
                dp[j].first = dp[j-1].first;
                dp[j].second = dp[j-1].second;
            }

           //cout << i << " " << j << " (" << dp[i%2][j].first << "," << dp[i%2][j].second << ")  " << endl;
        }

        if(dp[n].first <= k)
        {
            ans = i;
        }
        else
        {
            break;
        }

        for(int i = 0; i <= n; i++)
        {
            copy[i].first = dp[i].first;
            copy[i].second = dp[i].second;
        }
    }

    //cout << ans;
    fout << ans;

}