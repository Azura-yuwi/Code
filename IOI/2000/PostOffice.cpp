#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{
    int n,m; cin >> n >> m;
    int d[n];
    int pre[n];

    for(int i = 0; i < n; i++)
    {
        cin >> d[i]; pre[i] = d[i];
        if(i > 0) pre[i] += pre[i-1];
    }

    int dp[n][m];
    int from[n][m];

    dp[0][0] = pre[n-1] - n*d[0];
    from[0][0] = -1;
    
    for(int i = 1; i < n; i++)
    {
        dp[i][0] = i*d[i] - pre[i-1] + (pre[n-1] - pre[i]) - (n-i-1)*d[i];
        from[i][0] = -1;
    }

    for(int k = 1; k < m; k++)
    {
        for(int i = k; i < n; i++) //new post
        {
            int at = 0;
            dp[i][k] = INT_MAX;

            for(int j = k-1; j < i; j++) //right-most post
            {
                while(d[at] - d[j] < d[i] - d[at])
                {
                    at++;
                }

                int rPrev = pre[n-1] - pre[i] - (n-i-1)*d[j];
                int rCur = pre[n-1] - pre[i] - (n-i-1)*d[i];

                int mPrev = pre[i] - pre[at-1] - (i - at + 1)*d[j];
                int mCur = (i - at + 1)*d[i] - (pre[i] - pre[at-1]);

                if(dp[i][k] > dp[j][k-1] - rPrev - mPrev + rCur + mCur)
                {
                    dp[i][k] = dp[j][k-1] - rPrev - mPrev + rCur + mCur;
                    from[i][k] = j;
                }
                
            }
        }
    }

    int ans = INT_MAX;
    int ind = 0;

    for(int i = m-1; i < n; i++)
    {
        if(ans > dp[i][m-1]) 
        {
            ind = i;    
            ans = dp[i][m-1];
        }
    }

    cout << ans << endl;

    int order[m];
    order[m-1] = d[ind];

    for(int i = m-1; i > 0; i--)
    {
        ind = from[ind][i];
        order[i-1] = d[ind];
    }

    for(int i = 0; i < m; i++)
    {
        cout << order[i] << " ";
    }
}