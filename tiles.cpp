#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define pb push_back

int main()
{
    long long w,l;
    cin >> w >> l;
    long long mod = 998244353;

    long long n = w+l;
    long long ans = 1;
    long long count = 2;

    while(n > 0)
    {
        if(n%2 == 1)
        {
            ans *= count;
            ans = ans%mod;
            //cout << "ADD " << ans << " " << count << endl;
        }

        n = n/2;
        count = count*count;
        //cout << count << endl;
        count = count%mod; 
        //cout << n << " " << count << endl;
    }

    cout << ans;

    return 0;
}