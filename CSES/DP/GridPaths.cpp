#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int mod = 1000000007;
    int n;
    cin >> n;

    int num[n];
    for(int i = 0; i < n; i++)
    {
        num[i] = 0;
    }

    num[0] = 1;

    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        for(int j = 0; j < n; j++)
        {
            if(str.at(j) == '*')
            {
                num[j] = 0;
            }
            else if(j > 0)
            {
                num[j] += num[j-1];
                num[j] = num[j]%mod;
            }
            //cout << num[j] << " ";
        }
        //cout << endl;
    }

    cout << num[n-1];

}