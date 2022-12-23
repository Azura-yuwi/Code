//CSES Dynamic Programming

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n
    cin >> n;
    vector<int> dp;

    for(int i = 0; i < n; i++)
    {
        int add;
        cin >> add;

        int pos = lower_bound(dp.begin(), dp.end(), add) - dp.begin();

        if(pos == dp.size())
        {
            dp.push_back(add);
        }
        else
        {
            dp[pos] = add;
        }
    }

    cout << dp.size();
}