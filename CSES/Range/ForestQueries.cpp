#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main()
{
    int n,q; cin >> n >> q; 
    bool tree[n+1][n+1];
    int dp[n+1][n+1];

    for(int i = 1; i <= n; i++)
    {
        string str; cin >> str; 

        for(int j = 0; j < n; j++)
        {
            if(str[j] == '.')
            {
                tree[i][j+1] = false;
            }
            else
            {
                tree[i][j+1] = true;
            }
        }
    }

    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            if(tree[i][j]) dp[i][j]++;
        }
    }

    for(int i = 0; i < q; i++)
    {
        int y1,x1,y2,x2; cin >> y1 >> x1 >> y2 >> x2;

        int ymax = max(y1,y2); int ymin = min(y1,y2);
        int xmax = max(x1,x2); int xmin = min(x1,x2);

        int ans = dp[ymax][xmax] - dp[ymin-1][xmax] - dp[ymax][xmin-1] + dp[ymin-1][xmin-1];
        cout << ans << endl;
    }
}