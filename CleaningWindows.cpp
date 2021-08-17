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

    pair<int,int> dp[n+1][n+1];
    int dirt[n+1];
    dirt[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        //cin >> dirt[i];
        fin >> dirt[i];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            dp[i][j] = mp(k+10, j);
        }
    }

    for(int i = 0; i <= n; i++)
    {
        dp[0][i] = mp(0, 1);
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            dp[i][j] = mp(min(dp[i-1][j-1].first + j - dp[i-1][j-1].second + dirt[j], k+10), j); //clean window

            if(dp[i][j].first > dp[i][j-1].first) //don't clean window
            {
                dp[i][j].first = dp[i][j-1].first;
                dp[i][j].second = dp[i][j-1].second;
            }
        }
    }

    /*for(int i = 0; i <= n; i++) //print dp grid out
    {
        for(int j = 0; j <= n; j++)
        {
            cout << "(" << dp[i][j].first << "," << dp[i][j].second << ")  ";
        }

        cout << endl;
    }*/


    for(int i = n; i >= 0; i--)
    {
        if(dp[i][n].first <= k)
        {
            //cout << i;
            fout << i;
            break;
        }
    }
}