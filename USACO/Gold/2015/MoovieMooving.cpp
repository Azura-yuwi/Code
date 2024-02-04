//USACO Bitmask DP
//USACO Jan 2015 Gold

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int dp[1<<20];

int bits(int n, int num)
{   
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        if((num&(1<<i)) != 0)
        {
            ans++;
        }
    }

    return ans; 
}

int main()
{
    ifstream fin("movie.in");
    ofstream fout("movie.out");

    int n,l; fin >> n >> l;
    int dur[n];
    vector<int> starts[n];

    for(int i = 0; i < n; i++)
    {
        int num; fin >> dur[i] >> num;

        for(int j = 0; j < num; j++)
        {
            int get; fin >> get; starts[i].pb(get);
        }    
    }

    dp[0] = 0;
    int ans = 21;

    for(int i = 1; i < (1<<n); i++)
    {
        dp[i] = -1;

        for(int j = 0; j < n; j++)
        {
            if((i&(1<<j)) != 0)
            {
                int prev = i - (1<<j);

                if(dp[prev] == -1) //no valid consec time
                {
                    continue;
                }

                int ind = lower_bound(starts[j].begin(), starts[j].end(), dp[prev]) - starts[j].begin();

               // cout << "j " << j << " " << prev << " " << ind << endl;

                if(ind == starts[j].size() || starts[j].at(ind) > dp[prev])
                {
                    ind--;
                }

                if(ind < 0)
                {
                    continue;
                }            

                //cout << " ind " << ind << " " << dp[prev] << " " << endl;

                dp[i] = max(dp[i], starts[j].at(ind) + dur[j]);   
            }           
        }

        //cout << i << " " << dp[i] << endl;

        if(dp[i] >= l)
        {
            ans = min(ans, bits(n,i));
        }
    }

    if(ans == 21)
    {
        ans = -1;
    }

    fout << ans;    
}