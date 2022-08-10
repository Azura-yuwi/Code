#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int main()
{
    int n,m; cin >> n >> m;
    vector<int> left;
    vector<int> right;

    for(int i = 0; i < n; i++)
    {
        int a; cin >> a; left.pb(a);
    }

    for(int i = 0; i < m; i++)
    {
        int b; cin >> b; right.pb(b);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    if(n > m)
    {
        swap(left, right);
        swap(n,m);
    }

    int dp[n][m];
    dp[0][0] = abs(left[0] - right[0]);

    for(int j = 1; j < m; j++)
    {
        dp[0][j] = min(dp[0][j-1], abs(left[0] - right[j]));
    }
    
    for(int i = 1; i < n; i++)
    {
        dp[i][i] = max(dp[i-1][i-1], abs(left[i] - right[i]));

        for(int j = i+1; j < m; j++)
        {
            dp[i][j] = min(dp[i][j-1], max(dp[i-1][j], abs(left[i] - right[j]))); //pair left i with right j
        }
    }

    
    /*for(int i = 0; i < n; i++)
    {
        for(int j = i; j < m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

   cout << dp[n-1][m-1];
}