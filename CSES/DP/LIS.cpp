//Longest Increasing Subsequence

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pairiz
#define f first
#define s second

int main()
{
    int n; cin >> n;
    vector<int> val;

    for(int i = 0; i < n; i++)
    {
        int a; cin >> a; val.pb(a);
    }

    vector<int> dp; //stores the LIS

    for(int get : val)
    {
        int pos = lower_bound(dp.begin(), dp.end(), get) - dp.begin(); 
        //first element not less than get currntly in the LIS

        if(pos == dp.size()) //all elements in LIS are smaller than get
        {
            dp.pb(get); //add get to end of LIS
        }
        else //exists element in LIS greater than get coming before the array
        { // --> last element in LIS must be greater than get
            // we can update this last element to be smaller

            dp[pos] = get;
        }
    }

    cout << dp.size();

}