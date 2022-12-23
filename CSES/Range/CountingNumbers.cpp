#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

ll calc(ll n)
{
    //cout << "working on number " << n << endl;

    if(n < 0)
    {
        return 0;
    }

    if(n == 0)
    {
        return 1; 
    }

    int numDigits = 0;
    ll cn = n;
    vector<int> digits;

    while(cn > 0)
    {
        digits.pb(cn%10);
        cn /= 10; numDigits++;
    }

    reverse(digits.begin(), digits.end());

    ll dp[numDigits];
    bool eq[numDigits];

    eq[0] = true; //left i digits = no two adjacent digits r equal in n
    bool nw = false;

    for(int i = 1; i < numDigits; i++)
    {
        if(nw)
        {
            eq[i] = false;
        }
        else if(digits[i] == digits[i-1])
        {
            eq[i] = false; nw = true;
        }
        else 
        {
            eq[i] = true;
        }
    }

    dp[0] = digits[0];

    //cout << "At poistion 0 dp is " << dp[0] << endl;

    for(int i = 1; i < numDigits; i++)
    {
        dp[i] = dp[i-1]*9+1;
        
        if(eq[i-1])
        {
            if(digits[i-1] >= digits[i])
            {
                dp[i] += digits[i];
            }
            else
            {
                dp[i] += max(digits[i]-1, 0);
            }
        }

      // cout << "At  position " << i << " dp is " << dp[i] << endl;
    }

    ll ans = dp[numDigits-1];
    
    if(eq[numDigits-1])
    {
        ans++;
    }

    return ans;
}


int main()
{
    ll a, b; cin >> a >> b;

    if(a > b)
    {
        swap(a,b);
    }

    cout << (ll)(calc(b) - calc(a-1)) << endl;
    //cout << calc(b) << " " << calc(a) << " " << calc(a-1) << endl;
}