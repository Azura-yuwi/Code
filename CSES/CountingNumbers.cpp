//CSES Dynamic Programming
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll total(ll num)
{
    vector<int> digits;
    ll copy = num; // 3  6  5

    while(copy != 0)
    {
        digits.push_back(copy%10); // 3  6  5  
        copy /= 10;
    }

    reverse(digits); // 5   6   3;

    ll dp[20]; // number of digits 

    for(int i = 0; i < 20; i++)
    {
        dp[i] = 0;
    }

    dp[0] = digits[0]+1;

    for(int i = 1; i < digits.size(); i++)
    {
        int get = digits[i];
        int prev = digits[i-1];

        if(get > prev)
        {
            dp[i] = get*pow(9,i) + dp[i-1];
        }
        else if (get == prev)
        {
            dp[i] = get*pow(9, i) + get*pow(9, i-1);
        }
        else // get < prev
        {
            dp[i] = get*pow(9,i) + dp[i-1] - pow(9, i-1);
        }

    }

    return dp[digits.size()-1];
}
 
int main()
{
    ll a, b;
    cin >> a >> b;

    
}