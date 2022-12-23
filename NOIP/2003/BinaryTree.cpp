#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

//pre --> root, left, right --> minimize root
// in --> left, root, right

int main()
{
    int n; cin >> n;
    int w[n];

    for(int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    ll dp[n][n];
    vector<int> path[n][n];

    for(int i = 0; i < n; i++)
    {
        dp[i][i] = w[i]; path[i][i].pb((i+1));
    }

    for(int l = 1; l < n; l++)
    {
        for(int i = 0; i+l < n; i++)
        {
            dp[i][i+l] = dp[i+1][i+l] + w[i]; //value should be same for either side
            int root = i; 

            for(int k = i+1; k < i+l; k++)
            {
                ll get = dp[i][k-1]*dp[k+1][i+l] + w[k];

                if(get > dp[i][i+l])
                {
                    root = k; //do something about the path
                    dp[i][i+l] = get;
                }
            }
            
            path[i][i+l].pb((root+1));

            if(root != i)
            {
                for(int left : path[i][root-1])
                {
                    path[i][i+l].pb(left);
                }
            }

            
            for(int right : path[root+1][i+l])
            {
                path[i][i+l].pb(right);
            }
        }
    }
    

    cout << dp[0][n-1] << endl;

    for(int get : path[0][n-1])
    {
        cout << get << " ";
    }


}