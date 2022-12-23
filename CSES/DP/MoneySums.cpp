//CSES Dynamic Programming

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    int coin[n];
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> coin[i];
        sum +=coin[i];
    }

    bool dp[sum+1];
    for(int i = 1; i <= sum; i++)
    {
        dp[i] = false;
    }
    dp[0] = true;

    for(int i = 0; i < n; i++)
    {
        int val = coin[i];
       // cout << i << " COIN " << val << endl;

        for(int j = sum; j >= val; j--)
        {
            //cout << dp[j] << " " << dp[j-val] << endl;
            dp[j] = dp[j]|dp[j-val];
        }
    }
    
    vector<int> track;
    int num = 0;

    for(int i = 1; i <= sum; i++)
    {
        if(dp[i])
        {
            num++;
            track.push_back(i);
        }
    }
    
    cout << num << endl;

    for(int i : track)
    {
        cout << i << " ";
    }
}