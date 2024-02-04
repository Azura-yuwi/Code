#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main()
{
    int n; cin >> n;
    int res[n-1][n-1];
    int path[n][n];

    for(int i = 0; i < n-1; i++)
    {
        string str; cin >> str;

        for(int j = 0; j < str.size(); j++)
        {
            if(str[j] == '0')
            {
                res[i][j] = 0;
            }
            else
            {
                res[i][j] = 1;
            }
        }
    }

    int odd[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            odd[i][j] = 0; path[i][j] = 0;
        }
    }

    int ans = 0;

    for(int i = n-2; i >= 0; i--)
    {
        for(int j = 1; j < n-i; j++)
        {
            for(int k = 1; k < j; k++)
            {
                odd[i][i+j] += (odd[i+k][i+j]*path[i][i+k]);
            }

            if(res[i][j-1] != (odd[i][i+j]%2))
            {
                ans += 1;
                path[i][i+j] = 1;
                odd[i][i+j] += 1; 
            }

            odd[i][i+j] %= 2;
        }
    }

    cout << ans;

}