//Game

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{
    int n,k; cin >> n >> k;
    int stones[n];

    for(int i = 0; i < n; i++)
    {
        cin >> stones[i];
    }

    sort(stones, stones+n);

    bool dp[k+1]; //false = even # moves left; true = odd # moves left;

    for(int i = 0; i <= k; i++)
    {
        bool found = false;

        for(int k : stones)
        {
            if(k > i)
            {
                break;
            }

            if(!dp[i-k]) //can move to position with only even moves left --> odd moves
            {
                found = true; break;
            }
        }

        dp[i] = found;
        //if can not find any with even moves; you are even move position
    }

    if(dp[k])
    {
        cout << "First";
    }
    else
    {
        cout << "Second";
    }



}