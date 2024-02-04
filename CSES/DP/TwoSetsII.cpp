//CSES Dynamic Programming

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll mod = 1e9 + 7;
    int n;
    cin >> n;
    int total = n*(n+1)/2; // definietly an integer

    if(total%2 == 1)
    {
        cout << 0;
        return 0;
    }

    ll sum[total+1];

    for(int i = 1; i < total+1; i++)
    {
        sum[i] = 0;
    }

    sum[0] = 1;

    for(int i = 1; i < n; i++) //i  is also the value
    {
        for(int j = total; j >= i; j--) //should technically have sum[k] = sum[total - k]
        {
            //cout << i << " " << j << " " << (j-i) << endl;
            //cout << sum[j] << " " << sum[j-i] << endl;

            sum[j] += sum[j-i];
            sum[j] %= mod;

            //cout << sum[j] << endl;
        }
    }
    
   cout << sum[total/2]; //*you don't go to n b/c at n-1, number of ways to get total/2  at n-1 = num ways to get total/2 - n ?

}

// ** because of this, technically sum[total/2] at n-1 = sum[total/2]/2 at n, but because you are moding, after you mod
// sum[total/2] mod m not necessarily ((2*sum[total/2]) mod m)/2
// example, 5 mod 8 =/= (5*2 = 10 == 2 mod8)/2 = 1 mod 8
// that's why if u look at history on twosetsII submission, the one going from 1 to n then dividing by 2 doesn't work
