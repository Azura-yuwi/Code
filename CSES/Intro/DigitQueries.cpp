//CSES Intro Set;
//Brute Force
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
 
int digit(ll n)
{

    ll len = 1;
    ll pow = 1;

  //  cout << "QUERY " << n << endl;

    while(n > len*9*pow)
    {
        n -= len*9*pow;
       // cout << n << " " << len << " " << pow << endl;
        len++;
        pow *= 10;
    }
    
   // cout << n << " " << len << " " << pow << endl;

   // cout << "FOUND NUM " << endl;

    ll num = pow + n/len;
    
    if(n%len == 0)
    {
        num--;
    }

    ll left = (n-1)%len;
    //cout << num << " " << left << " " << pow << endl;

   // cout << "ISOLATE DIGIT LEFT" << endl;

    while(left > 0)
    {
        num %= pow;
        pow /= 10;
        left--;

        //cout << num << " " << left << " " << pow << endl; 
    }

    //cout << num << endl;

    //cout << "ISOLATE DIGIT RIGHT" << endl;

    if(num < pow)
    {
        return 0;
    }

    while(num >= 10)
    {
        num /= 10;
    }

    return num;

}

int main()
{
    int q;
    cin >> q;

    for(int i = 0; i < q; i++)
    {
        ll get;
        cin >> get;
        cout << digit(get) << endl;
    }
}